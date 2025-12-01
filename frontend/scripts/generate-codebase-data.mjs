#!/usr/bin/env node
import { promises as fs } from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const repoRoot = path.resolve(__dirname, '..', '..');
const dataRoot = path.resolve(repoRoot, 'data');
const outputPath = path.resolve(__dirname, '..', 'public', 'data', 'codebase.json');

const MAX_DEPTH = 3;
const MAX_ENTRIES_PER_DIR = 160;
const IGNORED_DIRECTORIES = new Set([
  '.git',
  '.github',
  '.idea',
  '.vscode',
  'node_modules',
  'web-app',
  'dist',
  'coverage'
]);

const stats = {
  totalFiles: 0,
  totalDirectories: 0,
  maxDepth: 0,
  lectureFolders: [],
  otherFolders: []
};

async function ensureDirectoryExists(targetPath) {
  try {
    const stat = await fs.stat(targetPath);
    if (!stat.isDirectory()) {
      throw new Error(`Expected ${targetPath} to be a directory`);
    }
  } catch (error) {
    throw new Error(`Data directory not found at ${targetPath}`);
  }
}

function toPosix(p) {
  return p.split(path.sep).join('/');
}

function normaliseName(name) {
  return name.replace(/_/g, ' ').trim();
}

function parseLectureName(name) {
  const match = name.match(/^LEC-(\d+)[\s_-]*\(?(.+?)\)?$/i);
  if (!match) {
    return null;
  }
  const number = Number.parseInt(match[1], 10);
  const title = normaliseName(match[2]).replace(/\)+$/, '').trim();
  return {
    id: number,
    title,
    slug: `lec-${number}`
  };
}

async function scanDirectory(currentPath, depth = 0) {
  stats.maxDepth = Math.max(stats.maxDepth, depth);

  const entries = await fs.readdir(currentPath, { withFileTypes: true });
  const trimmedEntries = entries
    .filter((entry) => !IGNORED_DIRECTORIES.has(entry.name) && !entry.name.endsWith('.exe'))
    .slice(0, MAX_ENTRIES_PER_DIR);

  const result = [];

  for (const entry of trimmedEntries) {
    const fullPath = path.join(currentPath, entry.name);
    const relativePath = toPosix(path.relative(repoRoot, fullPath));
    if (entry.isDirectory()) {
      stats.totalDirectories += 1;
      const lectureData = parseLectureName(entry.name);
      if (lectureData) {
        stats.lectureFolders.push({
          ...lectureData,
          path: relativePath,
          itemCount: 0
        });
      } else {
        stats.otherFolders.push({
          name: normaliseName(entry.name),
          path: relativePath
        });
      }

      const children =
        depth < MAX_DEPTH ? await scanDirectory(fullPath, depth + 1) : [];

      const lectureMeta = stats.lectureFolders.find(
        (lecture) => lecture.path === relativePath
      );
      if (lectureMeta) {
        lectureMeta.itemCount = children.length;
      }

      result.push({
        name: entry.name,
        displayName: normaliseName(entry.name),
        type: 'directory',
        path: relativePath,
        depth,
        children
      });
    } else {
      stats.totalFiles += 1;
      result.push({
        name: entry.name,
        displayName: normaliseName(entry.name),
        type: 'file',
        path: relativePath,
        depth
      });
    }
  }

  result.sort((a, b) => {
    if (a.type !== b.type) {
      return a.type === 'directory' ? -1 : 1;
    }

    if (a.type === 'directory' && b.type === 'directory') {
      const aLecture = parseLectureName(a.name);
      const bLecture = parseLectureName(b.name);

      if (aLecture && bLecture) {
        return aLecture.id - bLecture.id;
      }
      if (aLecture) return -1;
      if (bLecture) return 1;
    }

    const aName = a.displayName ?? a.name;
    const bName = b.displayName ?? b.name;
    return aName.localeCompare(bName, undefined, { numeric: true, sensitivity: 'base' });
  });

  return result;
}

function buildSummary() {
  const sortedLectures = [...stats.lectureFolders].sort((a, b) => a.id - b.id);
  const coverageByTheme = sortedLectures.reduce((acc, lecture) => {
    const keywords = lecture.title
      .split(/[^a-zA-Z0-9]+/)
      .filter(Boolean)
      .map((word) => word.toLowerCase());

    const themes = keywords.filter((word) =>
      [
        'recursion',
        'search',
        'sort',
        'tree',
        'graph',
        'dp',
        'dynamic',
        'stack',
        'queue',
        'hash',
        'greedy',
        'pointer',
        'oops',
        'string',
        'heap'
      ].includes(word)
    );

    if (themes.length === 0) {
      themes.push('fundamentals');
    }

    themes.forEach((theme) => {
      const label = theme.replace('dynamic', 'dp');
      acc[label] = (acc[label] ?? 0) + 1;
    });

    return acc;
  }, {});

  const firstLecture = sortedLectures[0] ?? null;
  const lastLecture = sortedLectures.at(-1) ?? null;

  return {
    generatedAt: new Date().toISOString(),
    totals: {
      files: stats.totalFiles,
      directories: stats.totalDirectories,
      lectures: stats.lectureFolders.length
    },
    depth: stats.maxDepth,
    coverageByTheme,
    lectureRange: {
      first: firstLecture,
      last: lastLecture
    },
    lectures: sortedLectures.map((lecture) => ({
      ...lecture,
      keywords: lecture.title
        .split(/[^a-zA-Z0-9]+/)
        .filter(Boolean)
        .map((word) => word.toLowerCase())
    }))
  };
}

async function run() {
  await ensureDirectoryExists(dataRoot);

  const tree = await scanDirectory(dataRoot, 0);
  const summary = buildSummary();

  const payload = {
    summary,
    tree
  };

  await fs.writeFile(outputPath, JSON.stringify(payload, null, 2), 'utf8');
  const { totals } = summary;
  console.log(
    `✔ Generated codebase dataset with ${totals.directories} directories, ${totals.files} files, and ${totals.lectures} lectures.`
  );
}

run().catch((error) => {
  console.error('Failed to generate codebase data:', error);
  process.exitCode = 1;
});
