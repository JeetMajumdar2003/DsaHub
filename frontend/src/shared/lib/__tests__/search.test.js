import { describe, expect, it } from 'vitest';

import { filterTree, highlightMatches } from '../search.js';

const treeFixture = [
  {
    name: 'LEC-22',
    displayName: 'LEC-22 Time Complexity',
    path: 'LEC-22',
    type: 'directory',
    depth: 0,
    children: [
      {
        name: 'notes.txt',
        displayName: 'notes.txt',
        path: 'LEC-22/notes.txt',
        type: 'file',
        depth: 1,
        children: []
      }
    ]
  },
  {
    name: 'LEC-23',
    displayName: 'LEC-23 Recursion',
    path: 'LEC-23',
    type: 'directory',
    depth: 0,
    children: []
  }
];

describe('search helpers', () => {
  it('returns original tree when query empty', () => {
    const filtered = filterTree(treeFixture, '');
    expect(filtered).toHaveLength(2);
    expect(filtered[0].children).toHaveLength(1);
  });

  it('filters nodes by query and retains parents', () => {
    const filtered = filterTree(treeFixture, 'notes');
    expect(filtered).toHaveLength(1);
    expect(filtered[0].children).toHaveLength(1);
    expect(filtered[0].children[0].displayName).toBe('notes.txt');
  });

  it('highlights matched nodes', () => {
    const filtered = filterTree(treeFixture, 'recursion');
    const highlighted = highlightMatches(filtered);
    expect(highlighted[0].children).toHaveLength(0);
    expect(highlighted[0].highlight).toBe(true);
  });
});
