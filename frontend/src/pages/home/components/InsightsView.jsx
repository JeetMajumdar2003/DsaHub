import { InsightsPanel } from '@widgets/insights/InsightsPanel.jsx';

export function InsightsView({ summary }) {
  return (
    <div className="view-insights">
      <div style={{ marginBottom: 'var(--space-xl)' }}>
        <h1 style={{ fontSize: '2rem', marginBottom: 'var(--space-xs)' }}>Insights</h1>
        <p style={{ color: 'var(--color-text-muted)' }}>Deep dive into the repository statistics and coverage.</p>
      </div>
      <InsightsPanel summary={summary} />
    </div>
  );
}
