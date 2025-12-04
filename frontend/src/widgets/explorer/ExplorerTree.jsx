const ICON_STYLES = {
  width: 16,
  height: 16,
  viewBox: '0 0 24 24'
};

function FolderIcon() {
  return (
    <svg {...ICON_STYLES} fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
      <path d="M22 19a2 2 0 0 1-2 2H4a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2h5l2 3h9a2 2 0 0 1 2 2z" />
    </svg>
  );
}

function FileIcon() {
  return (
    <svg {...ICON_STYLES} fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
      <path d="M13 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V9z" />
      <polyline points="13 2 13 9 20 9" />
    </svg>
  );
}

function ChevronRightIcon() {
  return (
    <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
      <polyline points="9 18 15 12 9 6" />
    </svg>
  );
}

function ChevronDownIcon() {
  return (
    <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
      <polyline points="6 9 12 15 18 9" />
    </svg>
  );
}

function ExplorerNode({ node, depth, collapsedPaths, onToggleCollapse, onSelect, selectedPath }) {
  const isDirectory = node.type === 'directory';
  const isCollapsed = isDirectory && collapsedPaths.has(node.path);
  const paddedStyle = { paddingLeft: `${depth * 12 + 8}px` };
  const handleSelect = () => onSelect?.(node);

  return (
    <div data-node-path={node.path}>
      <div
        className={[
          'tree-node',
          node.path === selectedPath ? 'is-selected' : '',
          node.highlight ? 'is-highlight' : ''
        ]
          .filter(Boolean)
          .join(' ')}
        style={paddedStyle}
        onClick={handleSelect}
      >
        {isDirectory ? (
          <button
            type="button"
            className="node-caret"
            aria-label={`Toggle ${node.displayName ?? node.name} children`}
            aria-expanded={(!isCollapsed).toString()}
            onClick={(event) => {
              event.stopPropagation();
              onToggleCollapse(node.path);
            }}
          >
            {isCollapsed ? <ChevronRightIcon /> : <ChevronDownIcon />}
          </button>
        ) : (
          <span className="node-spacer" />
        )}
        <span
          className="node-icon"
          style={{ color: isDirectory ? 'var(--color-accent)' : 'var(--color-text-muted)' }}
        >
          {isDirectory ? <FolderIcon /> : <FileIcon />}
        </span>
        <span className="node-name">{node.displayName ?? node.name}</span>
      </div>
      {isDirectory && node.children?.length ? (
        <div className="tree-children" hidden={isCollapsed}>
          {node.children.map((child) => (
            <ExplorerNode
              key={child.path}
              node={child}
              depth={depth + 1}
              collapsedPaths={collapsedPaths}
              onToggleCollapse={onToggleCollapse}
              onSelect={onSelect}
              selectedPath={selectedPath}
            />
          ))}
        </div>
      ) : null}
    </div>
  );
}

export function ExplorerTree({ nodes, collapsedPaths, onToggleCollapse, onSelect, selectedPath }) {
  if (!nodes?.length) {
    return (
      <section className="explorer">
        <p className="empty-state" style={{ fontSize: '0.875rem', color: 'var(--color-text-muted)' }}>
          No matches
        </p>
      </section>
    );
  }

  return (
    <section className="explorer">
      {nodes.map((node) => (
        <ExplorerNode
          key={node.path}
          node={node}
          depth={0}
          collapsedPaths={collapsedPaths}
          onToggleCollapse={onToggleCollapse}
          onSelect={onSelect}
          selectedPath={selectedPath}
        />
      ))}
    </section>
  );
}
