import { defineConfig } from 'vite';
import fs from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const fsp = fs.promises;

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const repoRoot = path.resolve(__dirname, '..');
const dataRoot = path.resolve(repoRoot, 'data');
const distRoot = path.resolve(__dirname, 'dist');
const distDataRoot = path.resolve(distRoot, 'data');
const datasetFilename = 'codebase.json';

const repoName = process.env.GITHUB_REPOSITORY?.split('/')[1] ?? '';
const isGithubActions = process.env.GITHUB_ACTIONS === 'true';
const isUserOrOrgSite = repoName && repoName.endsWith('.github.io');
const defaultBase = isGithubActions && repoName && !isUserOrOrgSite ? `/${repoName}/` : '/';
const base = process.env.VITE_BASE ?? defaultBase;

function createSourceMiddleware() {
  return (req, res, next) => {
    try {
      const decodedUrl = decodeURIComponent(req.url || '/');
      const [requestPath] = decodedUrl.split('?');
      const trimmedPath = requestPath.replace(/^\/+/, '');

      if (!trimmedPath) {
        res.statusCode = 400;
        res.end('Missing file path');
        return;
      }

      // Prevent directory traversal attacks
      if (trimmedPath.includes('..')) {
        res.statusCode = 403;
        res.end('Forbidden');
        return;
      }

      const filePath = path.resolve(repoRoot, trimmedPath);

      if (!filePath.startsWith(dataRoot)) {
        res.statusCode = 403;
        res.end('Forbidden');
        return;
      }

      if (fs.existsSync(filePath) && fs.statSync(filePath).isFile()) {
        res.setHeader('Content-Type', 'text/plain');
        const stream = fs.createReadStream(filePath);
        stream.pipe(res);
      } else {
        next();
      }
    } catch (e) {
      console.error('Error serving file:', e);
      next();
    }
  };
}

const serveSourcePlugin = {
  name: 'serve-source',
  configureServer(server) {
    server.middlewares.use('/api/source', createSourceMiddleware());
  },
  configurePreviewServer(server) {
    server.middlewares.use('/api/source', createSourceMiddleware());
  }
};

async function copyDataDirectoryToDist() {
  if (!fs.existsSync(dataRoot)) {
    console.warn('[serve-source] data directory not found; skipping static copy.');
    return;
  }

  await fsp.mkdir(distRoot, { recursive: true });

  const datasetPath = path.resolve(distDataRoot, datasetFilename);
  let datasetBackup = null;

  if (fs.existsSync(datasetPath)) {
    datasetBackup = await fsp.readFile(datasetPath);
  }

  await fsp.rm(distDataRoot, { recursive: true, force: true });
  await fsp.cp(dataRoot, distDataRoot, { recursive: true });

  if (datasetBackup) {
    await fsp.mkdir(path.dirname(datasetPath), { recursive: true });
    await fsp.writeFile(datasetPath, datasetBackup);
  }
}

const copyDataPlugin = {
  name: 'copy-data-directory',
  apply: 'build',
  async closeBundle() {
    try {
      await copyDataDirectoryToDist();
    } catch (error) {
      console.error('Failed to copy data directory into build output:', error);
      throw error;
    }
  }
};

export default defineConfig({
  base,
  server: {
    open: true,
    port: 5173,
    fs: {
      allow: ['..']
    }
  },
  plugins: [serveSourcePlugin, copyDataPlugin],
  resolve: {
    alias: {
      '@app': '/src/app',
      '@pages': '/src/pages',
      '@widgets': '/src/widgets',
      '@features': '/src/features',
      '@shared': '/src/shared',
      '@assets': '/src/assets'
    }
  },
  test: {
    environment: 'jsdom',
    globals: true,
    setupFiles: ['./vitest.setup.js'],
    coverage: {
      reporter: ['text', 'html'],
      exclude: ['**/node_modules/**', 'public/**']
    }
  },
  build: {
    target: 'es2018',
    outDir: 'dist',
    emptyOutDir: true
  }
});
