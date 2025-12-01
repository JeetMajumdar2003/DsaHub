import { describe, expect, it } from 'vitest';

import {
  buildStatCards,
  buildTimeline,
  buildTopicSpotlight,
  deriveTagsFromName,
  findNodeByPath,
  flattenTree
} from '../analytics.js';

const summaryFixture = {
  totals: {
    files: 120,
    directories: 30,
    lectures: 4
  },
  coverageByTheme: {
    recursion: 3,
    tree: 1,
    dp: 2
  },
  lectureRange: {
    first: { id: 22, title: 'Time Complexity' },
    last: { id: 25, title: 'Pointers' }
  },
  lectures: [
    { id: 22, title: 'Time Complexity', itemCount: 8, keywords: ['time', 'complexity'] },
    { id: 23, title: 'Recursion Basics', itemCount: 12, keywords: ['recursion', 'basics'] },
    { id: 24, title: 'Recursion Advanced', itemCount: 10, keywords: ['recursion', 'advanced'] },
    { id: 25, title: 'Dynamic Programming', itemCount: 16, keywords: ['dynamic', 'programming'] }
  ]
};

const treeFixture = [
  {
    name: 'LEC-22',
    displayName: 'LEC-22 (Time Complexity)',
    path: 'LEC-22',
    type: 'directory',
    depth: 0,
    children: [
      {
        name: 'notes.txt',
        displayName: 'notes.txt',
        path: 'LEC-22/notes.txt',
        type: 'file',
        depth: 1
      }
    ]
  },
  {
    name: 'LEC-23',
    displayName: 'LEC-23 (Recursion Basics)',
    path: 'LEC-23',
    type: 'directory',
    depth: 0,
    children: []
  }
];

describe('analytics helpers', () => {
  it('buildStatCards summarises totals', () => {
    const [archiveCard, assetsCard, averageCard] = buildStatCards(summaryFixture);

    expect(archiveCard.value).toBe('4');
    expect(archiveCard.caption).toContain('LEC-22');

    expect(assetsCard.caption).toContain('120 files');
    expect(averageCard.value).toBe('11.5');
  });

  it('buildTimeline orders topics by prevalence', () => {
    const timeline = buildTimeline(summaryFixture);
    expect(timeline).toHaveLength(3);
    expect(timeline[0]).toMatchObject({ label: 'recursion', count: 3 });
    expect(timeline[1]).toMatchObject({ label: 'dp', count: 2 });
  });

  it('buildTopicSpotlight extracts repeated keywords', () => {
    const spotlight = buildTopicSpotlight(summaryFixture);
    const keywords = spotlight.map((entry) => entry.keyword);
    expect(keywords).toContain('recursion');
    expect(keywords).not.toContain('time');
  });

  it('deriveTagsFromName returns concise tokens', () => {
    expect(deriveTagsFromName('LEC-23 (Recursion Basics)')).toEqual(['lec', 'recursion', 'basics']);
  });

  it('flattenTree creates depth-first list of nodes', () => {
    const flattened = flattenTree(treeFixture);
    expect(flattened.map((node) => node.path)).toEqual(['LEC-22', 'LEC-22/notes.txt', 'LEC-23']);
  });

  it('findNodeByPath locates nested node', () => {
    const node = findNodeByPath(treeFixture, 'LEC-22/notes.txt');
    expect(node).toBeDefined();
    expect(node.type).toBe('file');
  });
});
