import { act, render, screen, waitFor } from '@testing-library/react';
import userEvent from '@testing-library/user-event';
import { createElement } from 'react';
import { afterEach, beforeEach, describe, expect, it, vi } from 'vitest';

import { HomePage } from '@pages/home/HomePage.jsx';

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

describe('HomePage (React)', () => {
  const originalFetch = globalThis.fetch;
  let user;

  beforeEach(() => {
    user = userEvent.setup();
  });

  afterEach(() => {
    vi.restoreAllMocks();
    if (typeof originalFetch !== 'undefined') {
      globalThis.fetch = originalFetch;
    } else {
      delete globalThis.fetch;
    }
    delete navigator.clipboard;
  });

  it('renders hero and shows detail view after explorer selection', async () => {
    await act(async () => {
      render(createElement(HomePage, { dataset }));
    });

    expect(await screen.findByText(/A calmer way to inspect/i)).toBeInTheDocument();

    const lectureRow = document.querySelector('[data-node-path="LEC-01"] .tree-node');
    await act(async () => {
      await user.click(lectureRow);
    });

    expect(await screen.findByRole('heading', { name: /LEC-01/i })).toBeInTheDocument();
  });

  it('copies file contents from detail view', async () => {
    const clipMock = vi.fn().mockResolvedValue();
    Object.defineProperty(navigator, 'clipboard', {
      configurable: true,
      value: { writeText: clipMock }
    });
    globalThis.fetch = vi.fn().mockResolvedValue({
      ok: true,
      text: () => Promise.resolve('int main() {}')
    });

    await act(async () => {
      render(createElement(HomePage, { dataset: fileDataset }));
    });

    const fileRow = document.querySelector('[data-node-path="data/LEC-01/main.cpp"] .tree-node');
    await act(async () => {
      await user.click(fileRow);
    });

    const copyButton = await screen.findByRole('button', { name: /copy file contents/i });
    await waitFor(() => expect(copyButton).not.toBeDisabled());

    await act(async () => {
      await user.click(copyButton);
    });

    await waitFor(() => {
      expect(clipMock).toHaveBeenCalledWith('int main() {}');
    });
  });
});
