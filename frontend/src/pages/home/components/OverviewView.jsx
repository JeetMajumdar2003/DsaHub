import { formatNumber } from '@shared/lib/format.js';

function formatTimestamp(value) {
  if (!value) return 'Unknown';
  try {
    return new Intl.DateTimeFormat('en', {
      month: 'short',
      day: 'numeric',
      year: 'numeric'
    }).format(new Date(value));
  } catch (error) {
    return value;
  }
}

function SignalStrip({ summary }) {
  const items = [
    { label: 'Lectures', value: formatNumber(summary.totals?.lectures ?? 0) },
    { label: 'Files tracked', value: formatNumber(summary.totals?.files ?? 0) },
    { label: 'Depth', value: `${formatNumber(summary.depth ?? 0)} levels` }
  ];

  return (
    <div className="signal-strip">
      {items.map((item) => (
        <div className="signal-pill" key={item.label}>
          <strong>{item.value}</strong>
          <span>{item.label}</span>
        </div>
      ))}
    </div>
  );
}

function Hero({ summary, onNavigate }) {
  const coverageEntries = Object.entries(summary.coverageByTheme ?? {}).slice(0, 4);

  return (
    <section className="hero">
      <div className="hero__grid">
        <div className="hero__content">
          <span className="eyebrow">C++ DSA Repository</span>
          <h1>A calmer way to inspect 80+ DSA lectures</h1>
          <p>
            Scan topics, surface lecture stats, and deep-dive into recursion, graph theory, and DP in a single structured
            canvas built for engineers.
          </p>
          <div className="hero-actions">
            <button type="button" className="primary-button" onClick={() => onNavigate('insights')}>
              <span>Explore Insights</span>
              <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                <line x1="5" y1="12" x2="19" y2="12" />
                <polyline points="12 5 19 12 12 19" />
              </svg>
            </button>
          </div>
          <SignalStrip summary={summary} />
        </div>
        <div className="hero__visual">
          <div className="hero-panel">
            <div className="hero-panel__meta">
              <span>Snapshot</span>
              <span>{formatTimestamp(summary.generatedAt)}</span>
            </div>
            <div className="hero-panel__body">
              <pre>{'// coverage map'}</pre>
              <ul>
                {coverageEntries.map(([topic, count]) => (
                  <li key={topic}>
                    <span>{topic}</span>
                    <strong>{formatNumber(count)}</strong>
                  </li>
                ))}
              </ul>
            </div>
          </div>
        </div>
      </div>
    </section>
  );
}

function HighlightsSection({ summary }) {
  const cards = [
    {
      title: 'Lecture coverage',
      stat: `${formatNumber(summary.totals?.lectures ?? 0)} sessions`,
      body: 'Comprehensive walkthroughs from recursion warm-ups to graph mastery.',
      meta: `First lecture · ${summary.lectureRange?.first?.title ?? 'N/A'}`
    },
    {
      title: 'Code surface area',
      stat: `${formatNumber(summary.totals?.files ?? 0)} files`,
      body: `Organized into ${formatNumber(summary.totals?.directories ?? 0)} structural folders for fast lookup.`,
      meta: 'Includes notes, labs, and STL use-cases.'
    },
    {
      title: 'Fresh snapshot',
      stat: formatTimestamp(summary.generatedAt),
      body: 'Regenerate locally with npm run generate:data to sync with git.',
      meta: 'Deterministic export · JSON'
    }
  ];

  return (
    <section className="feature-section">
      <div className="feature-section__header">
        <span className="eyebrow">Dataset signals</span>
        <h2>What makes this repo shine</h2>
        <p>Auto-generated stats keep the learning path transparent and traceable.</p>
      </div>
      <div className="card-grid">
        {cards.map((card) => (
          <article className="info-card" key={card.title}>
            <div className="info-card__top">
              <h3>{card.title}</h3>
              <strong className="info-card__stat">{card.stat}</strong>
            </div>
            <p>{card.body}</p>
            <span className="info-card__meta">{card.meta}</span>
          </article>
        ))}
      </div>
    </section>
  );
}

function CurriculumRail({ summary }) {
  const first = summary.lectureRange?.first;
  const last = summary.lectureRange?.last;

  const cards = [
    {
      label: 'Kick-off',
      lecture: first,
      description: 'Your first checkpoint into recursion fundamentals and call-stack tracing.'
    },
    {
      label: 'Latest drop',
      lecture: last,
      description: 'Fresh uploads often pack graph drills, DP revisions, and STL snippets.'
    }
  ];

  return (
    <section className="curriculum-rail">
      <div className="curriculum-rail__header">
        <span className="eyebrow">Curriculum milestones</span>
        <h2>Navigate by lecture anchors</h2>
      </div>
      <div className="rail-cards">
        {cards.map((card) => (
          <article className="rail-card" key={card.label}>
            <span className="rail-card__badge">{card.label}</span>
            <h3>{card.lecture?.title ?? 'Coming soon'}</h3>
            <code>{card.lecture?.path ?? 'N/A'}</code>
            <p>{card.description}</p>
          </article>
        ))}
      </div>
    </section>
  );
}

export function OverviewView({ summary, onNavigate }) {
  return (
    <div className="view-overview">
      <Hero summary={summary} onNavigate={onNavigate} />
      <HighlightsSection summary={summary} />
      <CurriculumRail summary={summary} />
    </div>
  );
}
