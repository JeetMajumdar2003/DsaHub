import { FileViewer } from './FileViewer.jsx';

function DetailEmptyState() {
  return (
    <div className="detail-view" data-testid="detail-empty">
      <p style={{ color: 'var(--color-text-muted)' }}>Select a file or folder from the explorer to inspect its contents.</p>
    </div>
  );
}

export function DetailView({ node, onChildSelect }) {
  if (!node) {
    return <DetailEmptyState />;
  }

  const isDirectory = node.type === 'directory';

  return (
    <div className="detail-view">
      <div className="detail-header">
        <h1 className="detail-title">{node.displayName ?? node.name}</h1>
        <div className="detail-meta">
          <span>{isDirectory ? 'Folder' : 'File'}</span>
          <span>•</span>
          <span>Depth: {node.depth}</span>
          <span>•</span>
          <span style={{ fontFamily: 'var(--font-mono)' }}>{node.path}</span>
        </div>
      </div>
      <div className="detail-content">
        {isDirectory && node.children?.length ? (
          <div className="card-grid" style={{ marginTop: 'var(--space-xl)' }}>
            {node.children.map((child) => (
              <button
                className="rail-card"
                key={child.path}
                type="button"
                onClick={() => onChildSelect?.(child)}
                style={{ cursor: 'pointer' }}
              >
                <h3>{child.displayName ?? child.name}</h3>
                <code>{child.type}</code>
              </button>
            ))}
          </div>
        ) : (
          <FileViewer node={node} />
        )}
      </div>
    </div>
  );
}
