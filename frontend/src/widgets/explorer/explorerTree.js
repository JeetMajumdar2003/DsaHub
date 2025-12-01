const ICONS = {
  folder: '<svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M22 19a2 2 0 0 1-2 2H4a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2h5l2 3h9a2 2 0 0 1 2 2z"></path></svg>',
  file: '<svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M13 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V9z"></path><polyline points="13 2 13 9 20 9"></polyline></svg>',
  chevronRight: '<svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polyline points="9 18 15 12 9 6"></polyline></svg>',
  chevronDown: '<svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polyline points="6 9 12 15 18 9"></polyline></svg>'
};

function registerDirectories(nodes, directorySet) {
  const stack = [...nodes];
  while (stack.length) {
    const node = stack.pop();
    if (!node || node.type !== 'directory') {
      continue;
    }
    directorySet.add(node.path);
    if (Array.isArray(node.children) && node.children.length) {
      stack.push(...node.children);
    }
  }
}

function createCaret(node, { getCollapsed, toggleCollapsed, onCollapseChange }) {
  const caret = document.createElement('button');
  caret.type = 'button';
  caret.className = 'node-caret';
  
  caret.setAttribute('aria-label', `Toggle ${node.displayName} children`);

  const syncState = () => {
    const collapsed = getCollapsed(node.path);
    caret.innerHTML = collapsed ? ICONS.chevronRight : ICONS.chevronDown;
    caret.setAttribute('aria-expanded', String(!collapsed));
  };

  syncState();

  caret.addEventListener('click', (event) => {
    event.stopPropagation();
    const collapsed = toggleCollapsed(node.path);
    syncState();
    const wrapper = caret.closest('[data-node-path]');
    const children = wrapper?.querySelector(':scope > .tree-children');
    if (children) {
      children.hidden = collapsed;
    }
    onCollapseChange?.();
  });

  return caret;
}

function createRow(node, depth, state, callbacks) {
  const row = document.createElement('div');
  row.className = 'tree-node';
  row.dataset.path = node.path;
  // Indentation handled by padding-left on the row content wrapper or similar
  // But here we are using grid. Let's adjust padding-left of the row itself.
  // However, the caret needs to be aligned.
  // Let's use a spacer for depth.
  
  row.style.paddingLeft = `${depth * 12 + 8}px`; 

  if (node.highlight) {
    row.classList.add('is-highlight');
  }

  const icon = document.createElement('span');
  icon.className = 'node-icon';
  icon.style.display = 'flex';
  icon.style.alignItems = 'center';
  icon.style.color = node.type === 'directory' ? 'var(--color-accent)' : 'var(--color-text-muted)';
  icon.innerHTML = node.type === 'directory' ? ICONS.folder : ICONS.file;

  const title = document.createElement('span');
  title.className = 'node-name';
  title.textContent = node.displayName ?? node.name;

  const rowElements = [];

  if (node.type === 'directory') {
    const caret = createCaret(node, callbacks);
    rowElements.push(caret);
  } else {
    const spacer = document.createElement('span');
    spacer.className = 'node-spacer';
    rowElements.push(spacer);
  }

  rowElements.push(icon, title);
  row.append(...rowElements);

  if (state.selectedPath === node.path) {
    row.classList.add('is-selected');
  }

  row.addEventListener('click', () => {
    callbacks.onSelect?.(node);
  });

  return row;
}

function renderNodes(nodes, depth, state, callbacks) {
  const fragment = document.createDocumentFragment();

  nodes.forEach((node) => {
    const wrapper = document.createElement('div');
    wrapper.dataset.nodePath = node.path;

    const row = createRow(node, depth, state, callbacks);
    wrapper.append(row);

    if (node.type === 'directory' && node.children) {
      const childrenContainer = document.createElement('div');
      childrenContainer.className = 'tree-children';
      childrenContainer.style.marginLeft = '0'; // Reset margin as we handle depth in row
      childrenContainer.style.borderLeft = 'none'; // Remove dashed line for cleaner look
      childrenContainer.style.paddingLeft = '0';
      
      childrenContainer.hidden = callbacks.getCollapsed(node.path);
      const childFragment = renderNodes(node.children, depth + 1, state, callbacks);
      childrenContainer.append(childFragment);
      wrapper.append(childrenContainer);
    }

    fragment.append(wrapper);
  });

  return fragment;
}

export function createExplorerTree({ nodes, defaultSelection, onSelect }) {
  const container = document.createElement('section');
  container.className = 'explorer';

  const state = {
    selectedPath: defaultSelection ?? null,
    collapsed: new Set(),
    directories: new Set()
  };

  registerDirectories(nodes, state.directories);

  // Default to collapsed
  state.directories.forEach(dir => state.collapsed.add(dir));

  function getCollapsed(path) {
    return state.collapsed.has(path);
  }

  function toggleCollapsed(path) {
    if (state.collapsed.has(path)) {
      state.collapsed.delete(path);
      return false;
    }
    state.collapsed.add(path);
    return true;
  }

  function handleSelect(node) {
    state.selectedPath = node.path;
    render(currentNodes);
    onSelect?.(node);
  }

  let currentNodes = nodes;

  function render(tree) {
    currentNodes = tree;
    registerDirectories(tree, state.directories);
    container.innerHTML = '';
    const fragment = renderNodes(tree, 0, state, {
      onSelect: handleSelect,
      getCollapsed,
      toggleCollapsed,
      onCollapseChange: () => {
        // Optional: persist state
      }
    });
    container.append(fragment);
  }

  function setSelection(path) {
    state.selectedPath = path;
    render(currentNodes);
  }

  function expandAll() {
    state.collapsed.clear();
    render(currentNodes);
  }

  function collapseAll() {
    state.directories.forEach((path) => {
      state.collapsed.add(path);
    });
    render(currentNodes);
  }

  render(nodes);

  return {
    element: container,
    render,
    setSelection,
    expandAll,
    collapseAll
  };
}
