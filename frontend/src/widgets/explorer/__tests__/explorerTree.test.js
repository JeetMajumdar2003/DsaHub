import { describe, expect, it } from 'vitest';

import { createExplorerTree } from '../explorerTree.js';

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

const multiBranchTree = [
  {
    name: 'alpha',
    displayName: 'Alpha',
    path: 'alpha',
    type: 'directory',
    depth: 0,
    children: [
      {
        name: 'alpha-nested',
        displayName: 'Alpha nested',
        path: 'alpha/alpha-nested',
        type: 'directory',
        depth: 1,
        children: [
          {
            name: 'alpha-file.md',
            displayName: 'alpha-file.md',
            path: 'alpha/alpha-nested/alpha-file.md',
            type: 'file',
            depth: 2
          }
        ]
      }
    ]
  },
  {
    name: 'beta',
    displayName: 'Beta',
    path: 'beta',
    type: 'directory',
    depth: 0,
    children: [
      {
        name: 'beta-file.md',
        displayName: 'beta-file.md',
        path: 'beta/beta-file.md',
        type: 'file',
        depth: 1
      }
    ]
  }
];

describe('createExplorerTree', () => {
  it('collapses and expands directory children when caret is clicked', () => {
    const tree = createExplorerTree({ nodes: sampleTree, defaultSelection: 'root/child' });
    document.body.append(tree.element);

    const queryChildrenContainer = () =>
      tree.element.querySelector('[data-node-path="root"] > .tree-children');
    const queryCaret = () =>
      tree.element.querySelector('[data-node-path="root"] button.node-caret');

    expect(queryChildrenContainer()?.hidden).toBe(true);
    expect(queryCaret()?.getAttribute('aria-expanded')).toBe('false');

    // Expand
    queryCaret()?.click();
    expect(queryChildrenContainer()?.hidden).toBe(false);
    expect(queryCaret()?.getAttribute('aria-expanded')).toBe('true');

    // Collapse
    queryCaret()?.click();
    expect(queryChildrenContainer()?.hidden).toBe(true);
    expect(queryCaret()?.getAttribute('aria-expanded')).toBe('false');
  });

  it('collapses and expands entire tree via controls', () => {
    const tree = createExplorerTree({ nodes: sampleTree, defaultSelection: 'root/child' });
    document.body.append(tree.element);

    const childrenContainer = () =>
      tree.element.querySelector('[data-node-path="root"] > .tree-children');

    tree.expandAll();
    expect(childrenContainer()?.hidden).toBe(false);

    tree.collapseAll();
    expect(childrenContainer()?.hidden).toBe(true);

    tree.expandAll();
    expect(childrenContainer()?.hidden).toBe(false);
  });

  it('collapses directories that are not visible in the current render', () => {
    const tree = createExplorerTree({
      nodes: multiBranchTree,
      defaultSelection: 'alpha/alpha-nested/alpha-file.md'
    });
    document.body.append(tree.element);

    tree.render([multiBranchTree[0]]);
    tree.collapseAll();

    tree.render(multiBranchTree);

    const alphaChildren = () =>
      tree.element.querySelector('[data-node-path="alpha"] > .tree-children');
    const betaChildren = () =>
      tree.element.querySelector('[data-node-path="beta"] > .tree-children');

    expect(alphaChildren()?.hidden).toBe(true);
    expect(betaChildren()?.hidden).toBe(true);
  });
});
