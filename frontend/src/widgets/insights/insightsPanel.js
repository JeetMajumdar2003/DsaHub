import { buildStatCards, buildTimeline, buildTopicSpotlight } from '@shared/lib/analytics.js';

function createStatCard(card) {
  const article = document.createElement('article');
  article.className = 'stat-card';

  const title = document.createElement('h3');
  title.textContent = card.title;

  const value = document.createElement('strong');
  value.textContent = card.value;

  const caption = document.createElement('p');
  caption.textContent = card.caption;
  caption.style.margin = '0';
  caption.style.color = 'var(--color-text-muted)';
  caption.style.fontSize = '0.85rem';

  article.append(title, value, caption);
  return article;
}

function createTimelineSection(timeline) {
  const section = document.createElement('section');
  section.className = 'insight-card';

  const heading = document.createElement('h3');
  heading.textContent = 'Topic Coverage';
  section.append(heading);

  const bars = document.createElement('div');
  bars.className = 'timeline-bars';

  timeline.forEach((entry) => {
    const row = document.createElement('div');
    row.className = 'timeline-bar';

    const label = document.createElement('span');
    label.textContent = entry.label.toUpperCase();
    label.title = entry.label; // Tooltip for truncated text

    const progress = document.createElement('div');
    progress.className = 'timeline-progress';

    const value = document.createElement('span');
    value.textContent = `${entry.count} • ${entry.percentage}`;

    const indicator = document.createElement('div');
    indicator.className = 'timeline-progress__value';
    indicator.style.width = '0%';

    // Use setTimeout to ensure the transition triggers after append
    setTimeout(() => {
      indicator.style.width = entry.percentage;
    }, 100);

    progress.append(indicator);

    row.append(label, progress, value);
    bars.append(row);
  });

  section.append(bars);
  return section;
}

function createTopicGrid(spotlight) {
  const grid = document.createElement('section');
  grid.className = 'insight-card';

  const heading = document.createElement('h3');
  heading.textContent = 'Keyword Pulse';
  grid.append(heading);

  const list = document.createElement('div');
  list.className = 'topic-grid';

  spotlight.forEach((topic) => {
    const card = document.createElement('article');
    card.className = 'topic-card';

    const title = document.createElement('h4');
    title.textContent = topic.keyword;

    const meta = document.createElement('small');
    meta.textContent = `${topic.count}`;

    card.append(title, meta);
    list.append(card);
  });

  grid.append(list);
  return grid;
}

export function createInsightsPanel(summary) {
  const container = document.createElement('section');
  container.className = 'insights-panel';

  const cards = document.createElement('section');
  cards.className = 'dashboard-grid';
  buildStatCards(summary).forEach((card) => {
    cards.append(createStatCard(card));
  });

  container.append(cards);

  const timeline = buildTimeline(summary);
  if (timeline.length > 0) {
    container.append(createTimelineSection(timeline));
  }

  const topics = buildTopicSpotlight(summary);
  if (topics.length > 0) {
    container.append(createTopicGrid(topics));
  }

  return container;
}
