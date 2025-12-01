import { describe, expect, it, beforeEach, afterEach, vi } from 'vitest';

import { renderHomePage } from '../homePage.js';

const baseSummary = {
  generatedAt: new Date().toISOString(),
  totals: {
    files: 3,
    directories: 1,
    lectures: 1
  },
  depth: 1,
  coverageByTheme: {
    recursion: 1
  },
  lectureRange: {
    first: {
      id: 1,
      title: 'Recursion Basics',
      path: 'LEC-01'
    },
    last: {
      id: 1,
      title: 'Recursion Basics',
      path: 'LEC-01'
    }
  },
  lectures: [
    {
      id: 1,
      title: 'Recursion Basics',
      path: 'LEC-01',
      itemCount: 0,
      keywords: ['recursion']
    }
  ]
};

const dataset = {
  summary: baseSummary,
  tree: [
    {
      name: 'LEC-01',
      displayName: 'LEC-01 (Recursion Basics)',
      path: 'LEC-01',
      type: 'directory',
      depth: 0,
      children: []
    }
  ]
};

const fileDataset = {
  summary: baseSummary,
  tree: [
    {
      name: 'main.cpp',
      displayName: 'main.cpp',
      path: 'data/LEC-01/main.cpp',
      type: 'file',
      depth: 0
    }
  ]
};

describe('renderHomePage', () => {
  let root;
  const originalFetch = global.fetch;

  beforeEach(() => {
    root = document.createElement('div');
    root.id = 'root';
    document.body.innerHTML = '';
    document.body.append(root);
  });

  afterEach(() => {
    vi.restoreAllMocks();
    if (originalFetch) {
      global.fetch = originalFetch;
    } else {
      delete global.fetch;
    }
    delete navigator.clipboard;
    document.body.innerHTML = '';
  });

  it('renders hero/explorer and navigates to detail view on selection', () => {
    renderHomePage(root, dataset);

    expect(root.querySelector('.hero')).toBeTruthy();
    expect(root.querySelector('.explorer')).toBeTruthy();

    const search = root.querySelector('.search-panel input');
    expect(search?.getAttribute('placeholder')).toContain('Search');

    const lectureRow = root.querySelector('[data-node-path="LEC-01"] .tree-node');
    lectureRow?.dispatchEvent(new MouseEvent('click', { bubbles: true }));

    expect(root.querySelector('.detail-view')).toBeTruthy();
  });

  it('provides a copy button for file detail view', async () => {
    const clipMock = vi.fn().mockResolvedValue();
    navigator.clipboard = { writeText: clipMock };
    global.fetch = vi.fn().mockResolvedValue({
      ok: true,
      text: () => Promise.resolve('int main() {}')
    });

    renderHomePage(root, fileDataset);

    const fileRow = root.querySelector('[data-node-path="data/LEC-01/main.cpp"] .tree-node');
    fileRow?.dispatchEvent(new MouseEvent('click', { bubbles: true }));

    const flush = () => new Promise((resolve) => setTimeout(resolve, 0));
    await flush();

    const copyButton = root.querySelector('.file-copy-btn');
    expect(copyButton).toBeTruthy();
    await flush();
    expect(copyButton?.disabled).toBe(false);

    copyButton?.dispatchEvent(new MouseEvent('click', { bubbles: true }));
    await flush();

    expect(clipMock).toHaveBeenCalledWith('int main() {}');
  });
});
