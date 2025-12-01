import { extractKeywords, formatNumber, formatPercentage } from './format.js';

export function buildStatCards(summary) {
  const { totals, lectures } = summary;
  const assetTotal = totals.files + totals.directories;
  const avgItemsPerLecture =
    lectures.length === 0
      ? 0
      : lectures.reduce((sum, lecture) => sum + (lecture.itemCount ?? 0), 0) /
        lectures.length;

  return [
    {
      title: 'Lecture Archive',
      value: formatNumber(totals.lectures),
      caption: `From LEC-${lectures[0]?.id ?? '??'} to LEC-${lectures.at(-1)?.id ?? '??'}`,
      tone: 'accent'
    },
    {
      title: 'Repository Assets',
      value: formatNumber(assetTotal),
      caption: `${formatNumber(totals.files)} files · ${formatNumber(
        totals.directories
      )} folders`,
      tone: 'neutral'
    },
    {
      title: 'Avg. items per Lecture',
      value: avgItemsPerLecture.toFixed(1),
      caption: 'Helps estimate prep effort per topic',
      tone: 'success'
    }
  ];
}

export function buildTimeline(summary) {
  const { coverageByTheme, totals } = summary;
  const entries = Object.entries(coverageByTheme).map(([label, count]) => ({
    label,
    count,
    percentage: formatPercentage(count, totals.lectures)
  }));

  return entries
    .sort((a, b) => b.count - a.count)
    .slice(0, 10);
}

export function buildTopicSpotlight(summary) {
  const lectureKeywords = summary.lectures.flatMap((lecture) => lecture.keywords);
  const keywordCounts = lectureKeywords.reduce((acc, keyword) => {
    if (!keyword) return acc;
    const key = keyword.toLowerCase();
    acc[key] = (acc[key] ?? 0) + 1;
    return acc;
  }, {});

  return Object.entries(keywordCounts)
    .filter(([, count]) => count > 1)
    .sort((a, b) => b[1] - a[1])
    .slice(0, 12)
    .map(([keyword, count]) => ({
      keyword,
      count,
      emphasis: count > Math.max(3, summary.lectures.length * 0.06)
    }));
}

export function flattenTree(nodes) {
  return nodes.flatMap((node) => {
    const base = [node];
    if (node.children && node.children.length > 0) {
      return base.concat(flattenTree(node.children));
    }
    return base;
  });
}

export function findNodeByPath(nodes, targetPath) {
  for (const node of nodes) {
    if (node.path === targetPath) return node;
    if (node.children) {
      const match = findNodeByPath(node.children, targetPath);
      if (match) return match;
    }
  }
  return null;
}

export function deriveTagsFromName(displayName) {
  return extractKeywords(displayName)
    .filter((word) => word.length > 2)
    .slice(0, 5);
}
