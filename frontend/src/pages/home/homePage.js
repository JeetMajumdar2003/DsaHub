import { createAppShell } from '@app/layout.js';
import { createExplorerTree } from '@widgets/explorer/explorerTree.js';
import { createInsightsPanel } from '@widgets/insights/insightsPanel.js';
import { deriveTagsFromName, findNodeByPath, flattenTree } from '@shared/lib/analytics.js';
import { filterTree, highlightMatches } from '@shared/lib/search.js';
import { formatNumber } from '@shared/lib/format.js';

// --- Helper Components ---

function createSignalStrip(summary) {
  const strip = document.createElement('div');
  strip.className = 'signal-strip';

  const items = [
    { label: 'Lectures', value: formatNumber(summary.totals?.lectures ?? 0) },
    { label: 'Files tracked', value: formatNumber(summary.totals?.files ?? 0) },
    { label: 'Depth', value: `${formatNumber(summary.depth ?? 0)} levels` }
  ];

  items.forEach((item) => {
    const pill = document.createElement('div');
    pill.className = 'signal-pill';
    
    const value = document.createElement('strong');
    value.textContent = item.value;
    
    const label = document.createElement('span');
    label.textContent = item.label;
    
    pill.append(value, label);
    strip.append(pill);
  });

  return strip;
}

function createHero(summary, onNavigate) {
  const hero = document.createElement('section');
  hero.className = 'hero';

  const grid = document.createElement('div');
  grid.className = 'hero__grid';

  const copy = document.createElement('div');
  copy.className = 'hero__content';

  const eyebrow = document.createElement('span');
  eyebrow.className = 'eyebrow';
  eyebrow.textContent = 'C++ DSA Repository';

  const title = document.createElement('h1');
  title.textContent = 'A calmer way to inspect 80+ DSA lectures';

  const description = document.createElement('p');
  description.textContent =
    'Scan topics, surface lecture stats, and deep-dive into recursion, graph theory, and DP in a single structured canvas built for engineers.';

  const actions = document.createElement('div');
  actions.className = 'hero-actions';

  const primaryCta = document.createElement('button');
  primaryCta.className = 'primary-button';
  primaryCta.innerHTML = `
    <span>Explore Insights</span>
    <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><line x1="5" y1="12" x2="19" y2="12"></line><polyline points="12 5 19 12 12 19"></polyline></svg>
  `;
  primaryCta.addEventListener('click', () => onNavigate('insights'));

  actions.append(primaryCta);

  const strip = createSignalStrip(summary);

  copy.append(eyebrow, title, description, actions, strip);

  const visual = document.createElement('div');
  visual.className = 'hero__visual';
  const panel = document.createElement('div');
  panel.className = 'hero-panel';
  panel.innerHTML = `
    <div class="hero-panel__meta">
      <span>Snapshot</span>
      <span>${formatTimestamp(summary.generatedAt)}</span>
    </div>
    <div class="hero-panel__body">
      <pre>// coverage map</pre>
      <ul>
        ${Object.entries(summary.coverageByTheme ?? {})
          .slice(0, 4)
          .map(
            ([topic, count]) => `
              <li>
                <span>${topic}</span>
                <strong>${formatNumber(count)}</strong>
              </li>
            `
          )
          .join('')}
      </ul>
    </div>
  `;
  visual.append(panel);

  grid.append(copy, visual);
  hero.append(grid);

  return hero;
}

function createHighlightsSection(summary) {
  const section = document.createElement('section');
  section.className = 'feature-section';

  const header = document.createElement('div');
  header.className = 'feature-section__header';
  header.innerHTML = `
    <span class="eyebrow">Dataset signals</span>
    <h2>What makes this repo shine</h2>
    <p>Auto-generated stats keep the learning path transparent and traceable.</p>
  `;

  const grid = document.createElement('div');
  grid.className = 'card-grid';

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

  cards.forEach((card) => {
    const article = document.createElement('article');
    article.className = 'info-card';
    article.innerHTML = `
      <div class="info-card__top">
        <h3>${card.title}</h3>
        <strong class="info-card__stat">${card.stat}</strong>
      </div>
      <p>${card.body}</p>
      <span class="info-card__meta">${card.meta}</span>
    `;
    grid.append(article);
  });

  section.append(header, grid);
  return section;
}

function createCurriculumRail(summary) {
  const section = document.createElement('section');
  section.className = 'curriculum-rail';
  section.innerHTML = `
    <div class="curriculum-rail__header">
      <span class="eyebrow">Curriculum milestones</span>
      <h2>Navigate by lecture anchors</h2>
    </div>
  `;

  const rail = document.createElement('div');
  rail.className = 'rail-cards';

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

  cards.forEach((card) => {
    const article = document.createElement('article');
    article.className = 'rail-card';
    article.innerHTML = `
      <span class="rail-card__badge">${card.label}</span>
      <h3>${card.lecture?.title ?? 'Coming soon'}</h3>
      <code>${card.lecture?.path ?? 'N/A'}</code>
      <p>${card.description}</p>
    `;
    rail.append(article);
  });

  section.append(rail);
  return section;
}

// --- Views ---

function createOverviewView(summary, onNavigate) {
  const container = document.createElement('div');
  container.className = 'view-overview';
  
  const hero = createHero(summary, onNavigate);
  const highlights = createHighlightsSection(summary);
  const curriculum = createCurriculumRail(summary);

  container.append(hero, highlights, curriculum);
  return container;
}

function createInsightsView(summary) {
  const container = document.createElement('div');
  container.className = 'view-insights';
  
  const header = document.createElement('div');
  header.style.marginBottom = 'var(--space-xl)';
  header.innerHTML = `
    <h1 style="font-size: 2rem; margin-bottom: var(--space-xs);">Insights</h1>
    <p style="color: var(--color-text-muted);">Deep dive into the repository statistics and coverage.</p>
  `;

  container.append(header, createInsightsPanel(summary));
  return container;
}

function createDetailView(node, summary, onChildSelect) {
  const container = document.createElement('div');
  container.className = 'detail-view';

  if (!node) return container;

  const header = document.createElement('div');
  header.className = 'detail-header';
  
  const title = document.createElement('h1');
  title.className = 'detail-title';
  title.textContent = node.displayName ?? node.name;

  const meta = document.createElement('div');
  meta.className = 'detail-meta';
  meta.innerHTML = `
    <span>${node.type === 'directory' ? 'Folder' : 'File'}</span>
    <span>•</span>
    <span>Depth: ${node.depth}</span>
    <span>•</span>
    <span style="font-family: var(--font-mono);">${node.path}</span>
  `;

  header.append(title, meta);

  const content = document.createElement('div');
  content.className = 'detail-content';
  
  // If it's a directory, show children
  if (node.type === 'directory' && node.children) {
    const childrenList = document.createElement('div');
    childrenList.className = 'card-grid';
    childrenList.style.marginTop = 'var(--space-xl)';
    
    node.children.forEach(child => {
      const card = document.createElement('div');
      card.className = 'rail-card'; // Reuse card style
      card.style.cursor = 'pointer';
      card.innerHTML = `
        <h3>${child.displayName ?? child.name}</h3>
        <code>${child.type}</code>
      `;
      card.addEventListener('click', () => {
        onChildSelect?.(child);
      });
      childrenList.append(card);
    });
    content.append(childrenList);
  } else {
    // File Content View
    const fileContainer = document.createElement('div');
    fileContainer.className = 'file-viewer';
    fileContainer.style.marginTop = 'var(--space-xl)';

    const copyButton = document.createElement('button');
    copyButton.type = 'button';
    copyButton.className = 'file-copy-btn';
    copyButton.innerHTML = `
      <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
        <rect x="9" y="9" width="13" height="13" rx="2" ry="2"></rect>
        <path d="M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2-2h9a2 2 0 0 1 2 2v1"></path>
      </svg>
    `;
    copyButton.disabled = true;

    const codeBlock = document.createElement('pre');
    codeBlock.className = 'code-block';
    const code = document.createElement('code');
    
    // Determine language class
    const ext = node.name.split('.').pop().toLowerCase();
    const langMap = {
      'cpp': 'language-cpp',
      'c': 'language-c',
      'h': 'language-cpp',
      'hpp': 'language-cpp',
      'js': 'language-javascript',
      'json': 'language-json',
      'md': 'language-markdown',
      'html': 'language-html',
      'css': 'language-css'
    };
    code.className = langMap[ext] || 'language-none';
    
    codeBlock.append(code);
    fileContainer.append(copyButton, codeBlock);
    let currentCode = '';
    let resetCopyLabelTimeout;
    
    function resetCopyButton(state) {
      copyButton.classList.remove('is-success', 'is-error');
      if (state === 'success') {
        copyButton.classList.add('is-success');
      } else if (state === 'error') {
        copyButton.classList.add('is-error');
      }
      clearTimeout(resetCopyLabelTimeout);
      if (state === 'success') {
        resetCopyLabelTimeout = setTimeout(() => {
          copyButton.classList.remove('is-success', 'is-error');
          copyButton.dataset.tooltip = '';
        }, 2000);
      }
    }

    function legacyCopyToClipboard(text) {
      return new Promise((resolve, reject) => {
        const textarea = document.createElement('textarea');
        textarea.value = text;
        textarea.setAttribute('readonly', '');
        textarea.style.position = 'absolute';
        textarea.style.left = '-9999px';
        document.body.appendChild(textarea);
        textarea.select();
        try {
          const successful = document.execCommand && document.execCommand('copy');
          if (successful) {
            resolve();
          } else {
            reject(new Error('Copy command rejected'));
          }
        } catch (error) {
          reject(error);
        } finally {
          document.body.removeChild(textarea);
        }
      });
    }

    async function copyToClipboard(text) {
      if (typeof navigator !== 'undefined' && navigator.clipboard?.writeText) {
        return navigator.clipboard.writeText(text);
      }
      return legacyCopyToClipboard(text);
    }

    copyButton.addEventListener('click', async () => {
      if (!currentCode || copyButton.disabled) {
        return;
      }
      copyButton.disabled = true;
      copyButton.classList.remove('is-error', 'is-success');
      try {
        await copyToClipboard(currentCode);
        copyButton.dataset.tooltip = 'Copied!';
        resetCopyButton('success');
      } catch (error) {
        console.error('Failed to copy code snippet:', error);
        copyButton.dataset.tooltip = '';
        resetCopyButton('error');
      } finally {
        copyButton.disabled = false;
      }
    });
    
    // Loading state
    code.textContent = 'Loading content...';
    
    // Fetch content
    const encodedPath = encodeURI(node.path);
    fetch(`/api/source/${encodedPath}`)
      .then(res => {
        if (!res.ok) throw new Error('Failed to load file');
        return res.text();
      })
      .then(text => {
        currentCode = text;
        code.textContent = text;
        if (window.Prism) {
          window.Prism.highlightElement(code);
        }
        copyButton.disabled = false;
        copyButton.dataset.tooltip = '';
        resetCopyButton();
      })
      .catch(err => {
        code.textContent = `Error loading file: ${err.message}\n\nMake sure the development server is running and the file exists.`;
        code.style.color = 'var(--color-danger)';
        currentCode = '';
        copyButton.disabled = true;
        copyButton.dataset.tooltip = '';
        resetCopyButton('error');
      });

    content.append(fileContainer);
  }

  container.append(header, content);
  return container;
}

// --- Main Render Function ---

export function renderHomePage(root, dataset) {
  const { summary, tree } = dataset;
  let originalTree = tree;

  // State
  let currentView = 'overview';
  let selectedNode = null;

  // Shell
  const shell = createAppShell({
    onNavigate: (target) => navigateTo(target),
    onSearch: handleSearch
  });

  // Explorer
  const explorer = createExplorerTree({
    nodes: tree,
    defaultSelection: null,
    onSelect: (node) => {
      selectedNode = node;
      navigateTo('detail');
    }
  });
  shell.explorerContainer.append(explorer.element);

  // Wire up Explorer Actions
  shell.explorerActions.collapseBtn.addEventListener('click', (e) => {
    e.stopPropagation();
    explorer.collapseAll();
  });
  shell.explorerActions.expandBtn.addEventListener('click', (e) => {
    e.stopPropagation();
    explorer.expandAll();
  });

  // Navigation Logic
  function navigateTo(viewId) {
    currentView = viewId;
    shell.viewport.innerHTML = '';
    shell.setSidebarActive(viewId === 'detail' ? '' : viewId);

    if (viewId === 'overview') {
      shell.viewport.append(createOverviewView(summary, navigateTo));
    } else if (viewId === 'insights') {
      shell.viewport.append(createInsightsView(summary));
    } else if (viewId === 'detail') {
      shell.viewport.append(createDetailView(selectedNode, summary, (childNode) => {
        selectedNode = childNode;
        explorer.setSelection(childNode.path);
        navigateTo('detail');
      }));
    }
  }

  // Search Logic
  function handleSearch(query) {
    if (!query) {
      explorer.render(originalTree);
      return;
    }
    const filtered = highlightMatches(filterTree(originalTree, query));
    explorer.render(filtered);
    explorer.expandAll();
  }

  // Initial Render
  root.replaceChildren(shell.element);
  navigateTo('overview');

  return {
    searchInput: shell.searchInput,
    explorer
  };
}

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
