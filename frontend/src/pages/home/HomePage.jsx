import { useEffect, useMemo, useState } from 'react';

import { AppShell } from '@components/AppShell.jsx';
import { filterTree, highlightMatches } from '@shared/lib/search.js';

import { DetailView } from './components/DetailView.jsx';
import { InsightsView } from './components/InsightsView.jsx';
import { OverviewView } from './components/OverviewView.jsx';

/**
 * Traverses a tree of nodes and collects all directory paths into a Set.
 * This is used to track the collapsed state of directories in the UI.
 *
 * @param {Array} nodes - The root nodes of the tree to traverse.
 * @returns {Set<string>} A set containing all directory paths found in the tree.
 */
function collectDirectoryPaths(nodes = []) {
  const paths = new Set();

  function traverse(list) {
    list.forEach((node) => {
      if (node.type === 'directory') {
        paths.add(node.path);
        if (node.children?.length) {
          traverse(node.children);
        }
      }
    });
  }

  traverse(nodes);
  return paths;
}

function trimQuery(value) {
  return value.trim();
}

export function HomePage({ dataset }) {
  const { summary, tree } = dataset;
  const [view, setView] = useState('overview');
  const [selectedNode, setSelectedNode] = useState(null);
  const [searchQuery, setSearchQuery] = useState('');
  const [collapsedPaths, setCollapsedPaths] = useState(() => collectDirectoryPaths(tree));
  const [isSidebarOpen, setSidebarOpen] = useState(false);

  const explorerNodes = useMemo(() => {
    if (!searchQuery) {
      return tree;
    }
    return highlightMatches(filterTree(tree, searchQuery));
  }, [tree, searchQuery]);

  useEffect(() => {
    if (searchQuery) {
      setCollapsedPaths(new Set());
    } else {
      setCollapsedPaths(collectDirectoryPaths(tree));
    }
  }, [searchQuery, tree]);

  const selectedPath = selectedNode?.path ?? null;
  const activeNav = view === 'detail' ? null : view;

  const ensurePathVisible = (path) => {
    if (!path) return;
    setCollapsedPaths((prev) => {
      const next = new Set(prev);
      const segments = path.split('/');
      let current = '';
      segments.slice(0, -1).forEach((segment) => {
        current = current ? `${current}/${segment}` : segment;
        next.delete(current);
      });
      return next;
    });
  };

  const handleNavigate = (target) => {
    setView(target);
    if (target !== 'detail') {
      setSelectedNode(null);
    }
    setSidebarOpen(false);
  };

  const handleNodeSelect = (node) => {
    ensurePathVisible(node.path);
    setSelectedNode(node);
    setView('detail');
    setSidebarOpen(false);
  };

  const handleChildSelect = (child) => {
    if (!child) return;
    ensurePathVisible(child.path);
    setSelectedNode(child);
    setView('detail');
  };

  const handleToggleCollapse = (path) => {
    setCollapsedPaths((prev) => {
      const next = new Set(prev);
      if (next.has(path)) {
        next.delete(path);
      } else {
        next.add(path);
      }
      return next;
    });
  };

  const handleCollapseAll = () => {
    setCollapsedPaths(collectDirectoryPaths(explorerNodes));
  };

  const handleExpandAll = () => {
    setCollapsedPaths(new Set());
  };

  const currentView = (() => {
    if (view === 'overview') {
      return <OverviewView summary={summary} onNavigate={handleNavigate} />;
    }
    if (view === 'insights') {
      return <InsightsView summary={summary} />;
    }
    return <DetailView node={selectedNode} onChildSelect={handleChildSelect} />;
  })();

  return (
    <AppShell
      activeNav={activeNav}
      onNavigate={handleNavigate}
      searchQuery={searchQuery}
      onSearchChange={(value) => setSearchQuery(trimQuery(value))}
      explorerProps={{
        nodes: explorerNodes,
        collapsedPaths,
        onToggleCollapse: handleToggleCollapse,
        onSelect: handleNodeSelect,
        selectedPath
      }}
      onCollapseAll={handleCollapseAll}
      onExpandAll={handleExpandAll}
      isSidebarOpen={isSidebarOpen}
      setSidebarOpen={setSidebarOpen}
    >
      {currentView}
    </AppShell>
  );
}
