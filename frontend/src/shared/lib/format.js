export function formatNumber(value) {
  return Number(value).toLocaleString('en-IN');
}

export function formatPercentage(part, total) {
  if (!total) return '0%';
  const percentage = (part / total) * 100;
  return `${percentage.toFixed(1)}%`;
}

export function extractKeywords(text) {
  if (!text) return [];
  return text
    .split(/[^a-zA-Z0-9]+/)
    .map((word) => word.toLowerCase())
    .filter(Boolean);
}
