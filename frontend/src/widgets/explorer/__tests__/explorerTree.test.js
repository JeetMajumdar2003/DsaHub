import { act, render, screen } from '@testing-library/react';
import userEvent from '@testing-library/user-event';
import { createElement, useState } from 'react';
import { describe, expect, it, vi } from 'vitest';

import { ExplorerTree } from '@widgets/explorer/ExplorerTree.jsx';

const sampleTree = [
  {
    name: 'root',
    displayName: 'Root',
    path: 'root',
    type: 'directory',
    depth: 0,
    children: [
      {
        name: 'child',
        displayName: 'Child',
        path: 'root/child',
        type: 'file',
        depth: 1
      }
    ]
  }
];

const emptyTree = [];

function collectDirectories(nodes) {
  const paths = new Set();
  const stack = [...nodes];
  while (stack.length) {
    const node = stack.pop();
    if (!node) continue;
    if (node.type === 'directory') {
      paths.add(node.path);
      if (node.children) {
        stack.push(...node.children);
      }
    }
  }
  return paths;
}

function ExplorerHarness({ nodes, onSelect }) {
  const [collapsed, setCollapsed] = useState(() => collectDirectories(nodes));
  const [selectedPath, setSelectedPath] = useState(null);

  const handleToggle = (path) => {
    setCollapsed((prev) => {
      const next = new Set(prev);
      if (next.has(path)) {
        next.delete(path);
      } else {
        next.add(path);
      }
      return next;
    });
  };

  const handleSelect = (node) => {
    setSelectedPath(node.path);
    onSelect?.(node);
  };

  return createElement(ExplorerTree, {
    nodes,
    collapsedPaths: collapsed,
    onToggleCollapse: handleToggle,
    onSelect: handleSelect,
    selectedPath
  });
}

describe('ExplorerTree', () => {
  it('collapses and expands directory children when caret is clicked', async () => {
    const user = userEvent.setup();
    await act(async () => {
      render(createElement(ExplorerHarness, { nodes: sampleTree }));
    });

    const container = document.querySelector('[data-node-path="root"] > .tree-children');
    const caret = document.querySelector('[data-node-path="root"] button.node-caret');

    expect(container).toBeTruthy();
    expect(container?.hidden).toBe(true);
    expect(caret).toHaveAttribute('aria-expanded', 'false');

    await act(async () => {
      await user.click(caret);
    });
    expect(container?.hidden).toBe(false);
    expect(caret).toHaveAttribute('aria-expanded', 'true');

    await act(async () => {
      await user.click(caret);
    });
    expect(container?.hidden).toBe(true);
    expect(caret).toHaveAttribute('aria-expanded', 'false');
  });

  it('invokes onSelect callback when a node is clicked', async () => {
    const user = userEvent.setup();
    const handleSelect = vi.fn();
    await act(async () => {
      render(createElement(ExplorerHarness, { nodes: sampleTree, onSelect: handleSelect }));
    });

    const row = document.querySelector('[data-node-path="root/child"] .tree-node');
    await act(async () => {
      await user.click(row);
    });

    expect(handleSelect).toHaveBeenCalledWith(
      expect.objectContaining({ path: 'root/child', type: 'file' })
    );
  });

  it('renders empty state when no nodes are provided', async () => {
    await act(async () => {
      render(
        createElement(ExplorerTree, {
          nodes: emptyTree,
          collapsedPaths: new Set(),
          onToggleCollapse: () => {},
          onSelect: () => {},
          selectedPath: null
        })
      );
    });

    expect(screen.getByText(/no matches/i)).toBeInTheDocument();
  });
});
