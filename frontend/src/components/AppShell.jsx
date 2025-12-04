import { useState } from 'react';

import logoUrl from '@assets/logo.svg';
import { SearchInput } from '@features/search/SearchInput.jsx';
import { ThemeToggle } from '@features/theme/ThemeToggle.jsx';
import { ExplorerTree } from '@widgets/explorer/ExplorerTree.jsx';

const NAV_ITEMS = [
  {
    id: 'overview',
    label: 'Overview',
    icon: (
      <svg
        width="18"
        height="18"
        viewBox="0 0 24 24"
        fill="none"
        stroke="currentColor"
        strokeWidth="2"
        strokeLinecap="round"
        strokeLinejoin="round"
      >
        <path d="M3 9l9-7 9 7v11a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2z" />
        <polyline points="9 22 9 12 15 12 15 22" />
      </svg>
    )
  },
  {
    id: 'insights',
    label: 'Insights',
    icon: (
      <svg
        width="18"
        height="18"
        viewBox="0 0 24 24"
        fill="none"
        stroke="currentColor"
        strokeWidth="2"
        strokeLinecap="round"
        strokeLinejoin="round"
      >
        <line x1="18" y1="20" x2="18" y2="10" />
        <line x1="12" y1="20" x2="12" y2="4" />
        <line x1="6" y1="20" x2="6" y2="14" />
      </svg>
    )
  }
];

function Footer() {
  const year = new Date().getFullYear();
  return (
    <footer className="app-footer">
      <div className="footer-content">
        <div className="footer-links">
          <a href="https://github.com/JeetMajumdar2003" target="_blank" rel="noreferrer" aria-label="GitHub">
            <svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
              <path d="M9 19c-5 1.5-5-2.5-7-3m14 6v-3.87a3.37 3.37 0 0 0-.94-2.61c3.14-.35 6.44-1.54 6.44-7A5.44 5.44 0 0 0 20 4.77 5.07 5.07 0 0 0 19.91 1S18.73.65 16 2.48a13.38 13.38 0 0 0-7 0C6.27.65 5.09 1 5.09 1A5.07 5.07 0 0 0 5 4.77a5.44 5.44 0 0 0-1.5 3.78c0 5.42 3.3 6.61 6.44 7A3.37 3.37 0 0 0 9 18.13V22" />
            </svg>
          </a>
          <a href="https://www.linkedin.com/in/jeet-majumdar648/" target="_blank" rel="noreferrer" aria-label="LinkedIn">
            <svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
              <path d="M16 8a6 6 0 0 1 6 6v7h-4v-7a2 2 0 0 0-2-2 2 2 0 0 0-2 2v7h-4v-7a6 6 0 0 1 6-6z" />
              <rect x="2" y="9" width="4" height="12" />
              <circle cx="4" cy="4" r="2" />
            </svg>
          </a>
          <a href="https://x.com/jeet_exist" target="_blank" rel="noreferrer" aria-label="Twitter">
            <svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
              <path d="M23 3a10.9 10.9 0 0 1-3.14 1.53 4.48 4.48 0 0 0-7.86 3v1A10.66 10.66 0 0 1 3 4s-4 9 5 13a11.64 11.64 0 0 1-7 2c9 5 20 0 20-11.5a4.5 4.5 0 0 0-.08-.83A7.72 7.72 0 0 0 23 3z" />
            </svg>
          </a>
        </div>
        <div className="footer-copyright">&copy; {year} DSA Atlas. All rights reserved.</div>
      </div>
    </footer>
  );
}

export function AppShell({
  children,
  activeNav,
  onNavigate,
  searchQuery,
  onSearchChange,
  explorerProps,
  onCollapseAll,
  onExpandAll,
  isSidebarOpen,
  setSidebarOpen
}) {
  const [isCollapsed, setIsCollapsed] = useState(true);

  // When mobile drawer is open, force expanded width regardless of collapse toggle
  const shouldShowCollapsedSidebar = isSidebarOpen ? false : isCollapsed;

  const sidebarClass = [
    'app-sidebar',
    shouldShowCollapsedSidebar ? 'collapsed' : '',
    isSidebarOpen ? 'is-open' : ''
  ]
    .filter(Boolean)
    .join(' ');

  return (
    <div className="app-shell">
      <aside className={sidebarClass}>
        <button type="button" className="sidebar-brand" onClick={() => { onNavigate('overview'); setSidebarOpen(false); }}>
          <img src={logoUrl} alt="DSA Atlas" width="24" height="24" />
          <span>DSA Atlas</span>
        </button>
        <nav className="sidebar-nav">
          <ul>
            {NAV_ITEMS.map((item) => (
              <li key={item.id}>
                <button
                  type="button"
                  className={['nav-item', activeNav === item.id ? 'active' : ''].filter(Boolean).join(' ')}
                  title={item.label}
                  onClick={() => {
                    onNavigate(item.id);
                    setSidebarOpen(false);
                  }}
                >
                  {item.icon}
                  <span>{item.label}</span>
                </button>
              </li>
            ))}
          </ul>
        </nav>
        <div className="sidebar-explorer">
          <div className="sidebar-section-header">
            <span className="sidebar-section-title">Explorer</span>
            <div className="sidebar-actions">
              <button className="action-btn" type="button" title="Collapse All" onClick={onCollapseAll}>
                <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                  <polyline points="4 14 12 6 20 14" />
                  <line x1="12" y1="19" x2="12" y2="13" />
                </svg>
              </button>
              <button className="action-btn" type="button" title="Expand All" onClick={onExpandAll}>
                <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
                  <polyline points="4 10 12 18 20 10" />
                  <line x1="12" y1="6" x2="12" y2="12" />
                </svg>
              </button>
            </div>
          </div>
          <ExplorerTree {...explorerProps} />
        </div>
        <button
          type="button"
          className="sidebar-toggle"
          title="Toggle Sidebar"
          onClick={() => setIsCollapsed((prev) => !prev)}
        >
          <svg
            width="16"
            height="16"
            viewBox="0 0 24 24"
            fill="none"
            stroke="currentColor"
            strokeWidth="2"
            strokeLinecap="round"
            strokeLinejoin="round"
            style={{ transform: shouldShowCollapsedSidebar ? 'rotate(180deg)' : 'rotate(0deg)' }}
          >
            <polyline points={shouldShowCollapsedSidebar ? '9 18 15 12 9 6' : '15 18 9 12 15 6'} />
          </svg>
        </button>
      </aside>
      <main className="app-main">
        <header className="app-header">
          <button type="button" className="mobile-toggle" onClick={() => setSidebarOpen(true)}>
            <svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
              <line x1="3" y1="12" x2="21" y2="12" />
              <line x1="3" y1="6" x2="21" y2="6" />
              <line x1="3" y1="18" x2="21" y2="18" />
            </svg>
          </button>
          <div className="header-search">
            <SearchInput value={searchQuery} onChange={onSearchChange} />
          </div>
          <div className="header-actions">
            <ThemeToggle />
          </div>
        </header>
        <div className="app-scroll-container">
          <div className="app-viewport">{children}</div>
          <Footer />
        </div>
      </main>
      <div
        className={['sidebar-overlay', isSidebarOpen ? 'is-visible' : ''].filter(Boolean).join(' ')}
        onClick={() => setSidebarOpen(false)}
      />
    </div>
  );
}
