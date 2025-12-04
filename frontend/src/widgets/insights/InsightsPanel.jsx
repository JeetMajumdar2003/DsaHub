import { buildStatCards, buildTimeline, buildTopicSpotlight } from '@shared/lib/analytics.js';

function StatCard({ card }) {
  return (
    <article className="stat-card">
      <h3>{card.title}</h3>
      <strong>{card.value}</strong>
      <p style={{ margin: 0, color: 'var(--color-text-muted)', fontSize: '0.85rem' }}>{card.caption}</p>
    </article>
  );
}

function TimelineSection({ timeline }) {
  return (
    <section className="insight-card">
      <h3>Topic Coverage</h3>
      <div className="timeline-bars">
        {timeline.map((entry) => (
          <div className="timeline-bar" key={entry.label}>
            <span title={entry.label}>{entry.label.toUpperCase()}</span>
            <div className="timeline-progress">
              <div className="timeline-progress__value" style={{ width: entry.percentage }} />
            </div>
            <span>
              {entry.count} • {entry.percentage}
            </span>
          </div>
        ))}
      </div>
    </section>
  );
}

function TopicGrid({ topics }) {
  return (
    <section className="insight-card">
      <h3>Keyword Pulse</h3>
      <div className="topic-grid">
        {topics.map((topic) => (
          <article className="topic-card" key={topic.keyword}>
            <h4>{topic.keyword}</h4>
            <small>{topic.count}</small>
          </article>
        ))}
      </div>
    </section>
  );
}

export function InsightsPanel({ summary }) {
  const statCards = buildStatCards(summary);
  const timeline = buildTimeline(summary);
  const topics = buildTopicSpotlight(summary);

  return (
    <section className="insights-panel">
      <section className="dashboard-grid">
        {statCards.map((card) => (
          <StatCard key={card.title} card={card} />
        ))}
      </section>
      {timeline.length > 0 ? <TimelineSection timeline={timeline} /> : null}
      {topics.length > 0 ? <TopicGrid topics={topics} /> : null}
    </section>
  );
}
