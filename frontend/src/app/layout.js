import { createThemeToggle } from '@features/theme/themeToggle.js';
import { createSearchInput } from '@features/search/searchInput.js';
import logoUrl from '@assets/logo.svg';

export function createAppShell({ onNavigate, onSearch }) {
  const shell = document.createElement('div');
  shell.className = 'app-shell';

  // --- Sidebar ---
  const sidebar = document.createElement('aside');
  sidebar.className = 'app-sidebar collapsed';

  const brand = document.createElement('div');
  brand.className = 'sidebar-brand';
  brand.innerHTML = `
    <img src="${logoUrl}" alt="DSA Atlas" width="24" height="24" />
    <span>DSA Atlas</span>
  `;
  brand.addEventListener('click', () => {
    onNavigate('overview');
    closeMobileSidebar();
  });

  const nav = document.createElement('nav');
  nav.className = 'sidebar-nav';
  
  const navItems = [
    { id: 'overview', label: 'Overview', icon: '<path d="M3 9l9-7 9 7v11a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2z"></path><polyline points="9 22 9 12 15 12 15 22"></polyline>' },
    { id: 'insights', label: 'Insights', icon: '<line x1="18" y1="20" x2="18" y2="10"></line><line x1="12" y1="20" x2="12" y2="4"></line><line x1="6" y1="20" x2="6" y2="14"></line>' },
  ];

  const navList = document.createElement('ul');
  navItems.forEach(item => {
    const li = document.createElement('li');
    const btn = document.createElement('button');
    btn.className = 'nav-item';
    btn.dataset.target = item.id;
    btn.title = item.label; // Add tooltip for collapsed state
    btn.innerHTML = `
      <svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
        ${item.icon}
      </svg>
      <span>${item.label}</span>
    `;
    btn.addEventListener('click', () => {
      document.querySelectorAll('.nav-item').forEach(b => b.classList.remove('active'));
      btn.classList.add('active');
      onNavigate(item.id);
      closeMobileSidebar();
    });
    if (item.id === 'overview') btn.classList.add('active');
    li.append(btn);
    navList.append(li);
  });
  nav.append(navList);

  const explorerContainer = document.createElement('div');
  explorerContainer.className = 'sidebar-explorer';
  
  const explorerHeader = document.createElement('div');
  explorerHeader.className = 'sidebar-section-header';
  explorerHeader.innerHTML = `
    <span class="sidebar-section-title">Explorer</span>
    <div class="sidebar-actions">
      <button class="action-btn" title="Collapse All" data-action="collapse">
        <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polyline points="4 14 12 6 20 14"></polyline><line x1="12" y1="19" x2="12" y2="13"></line></svg>
      </button>
      <button class="action-btn" title="Expand All" data-action="expand">
        <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polyline points="4 10 12 18 20 10"></polyline><line x1="12" y1="6" x2="12" y2="12"></line></svg>
      </button>
    </div>
  `;
  explorerContainer.append(explorerHeader);

  // Sidebar Toggle
  const sidebarToggle = document.createElement('button');
  sidebarToggle.className = 'sidebar-toggle';
  sidebarToggle.title = 'Toggle Sidebar';
  sidebarToggle.innerHTML = `
    <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" style="transform: rotate(180deg);">
      <polyline points="9 18 15 12 9 6"></polyline>
    </svg>
  `;
  sidebarToggle.addEventListener('click', () => {
    sidebar.classList.toggle('collapsed');
    const isCollapsed = sidebar.classList.contains('collapsed');
    sidebarToggle.innerHTML = isCollapsed
      ? '<svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polyline points="9 18 15 12 9 6"></polyline></svg>' // Right arrow (actually using same icon rotated or different icon)
      : '<svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polyline points="15 18 9 12 15 6"></polyline></svg>'; // Left arrow
    
    // Rotate icon if collapsed
    sidebarToggle.querySelector('svg').style.transform = isCollapsed ? 'rotate(180deg)' : 'rotate(0deg)';
  });

  sidebar.append(brand, nav, explorerContainer, sidebarToggle);

  // --- Main Content Area ---
  const main = document.createElement('main');
  main.className = 'app-main';

  // --- Header ---
  const header = document.createElement('header');
  header.className = 'app-header';

  const mobileToggle = document.createElement('button');
  mobileToggle.className = 'mobile-toggle';
  mobileToggle.innerHTML = '<svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><line x1="3" y1="12" x2="21" y2="12"></line><line x1="3" y1="6" x2="21" y2="6"></line><line x1="3" y1="18" x2="21" y2="18"></line></svg>';
  mobileToggle.addEventListener('click', () => {
    toggleMobileSidebar();
  });

  const { container: searchContainer, input: searchInput } = createSearchInput({
    onQueryChange: onSearch
  });
  searchContainer.classList.add('header-search');

  const actions = document.createElement('div');
  actions.className = 'header-actions';
  
  const themeToggle = createThemeToggle();
  actions.append(themeToggle);

  header.append(mobileToggle, searchContainer, actions);

  // --- Content Viewport ---
  const scrollContainer = document.createElement('div');
  scrollContainer.className = 'app-scroll-container';

  const viewport = document.createElement('div');
  viewport.className = 'app-viewport';

  // --- Footer ---
  const footer = document.createElement('footer');
  footer.className = 'app-footer';
  footer.innerHTML = `
    <div class="footer-content">
      <div class="footer-links">
        <a href="https://github.com/JeetMajumdar2003" target="_blank" rel="noopener noreferrer" aria-label="GitHub">
          <svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M9 19c-5 1.5-5-2.5-7-3m14 6v-3.87a3.37 3.37 0 0 0-.94-2.61c3.14-.35 6.44-1.54 6.44-7A5.44 5.44 0 0 0 20 4.77 5.07 5.07 0 0 0 19.91 1S18.73.65 16 2.48a13.38 13.38 0 0 0-7 0C6.27.65 5.09 1 5.09 1A5.07 5.07 0 0 0 5 4.77a5.44 5.44 0 0 0-1.5 3.78c0 5.42 3.3 6.61 6.44 7A3.37 3.37 0 0 0 9 18.13V22"></path></svg>
        </a>
        <a href="https://www.linkedin.com/in/jeet-majumdar648/" target="_blank" rel="noopener noreferrer" aria-label="LinkedIn">
          <svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M16 8a6 6 0 0 1 6 6v7h-4v-7a2 2 0 0 0-2-2 2 2 0 0 0-2 2v7h-4v-7a6 6 0 0 1 6-6z"></path><rect x="2" y="9" width="4" height="12"></rect><circle cx="4" cy="4" r="2"></circle></svg>
        </a>
        <a href="https://x.com/jeet_exist" target="_blank" rel="noopener noreferrer" aria-label="Twitter">
          <svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M23 3a10.9 10.9 0 0 1-3.14 1.53 4.48 4.48 0 0 0-7.86 3v1A10.66 10.66 0 0 1 3 4s-4 9 5 13a11.64 11.64 0 0 1-7 2c9 5 20 0 20-11.5a4.5 4.5 0 0 0-.08-.83A7.72 7.72 0 0 0 23 3z"></path></svg>
        </a>
      </div>
      <div class="footer-copyright">
        &copy; ${new Date().getFullYear()} DSA Atlas. All rights reserved.
      </div>
    </div>
  `;

  scrollContainer.append(viewport, footer);
  main.append(header, scrollContainer);
  shell.append(sidebar, main);

  // Overlay for mobile sidebar
  const overlay = document.createElement('div');
  overlay.className = 'sidebar-overlay';
  overlay.addEventListener('click', () => closeMobileSidebar());
  shell.append(overlay);

  function setMobileSidebarState(isOpen) {
    if (isOpen) {
      sidebar.classList.add('is-open');
      overlay.classList.add('is-visible');
    } else {
      sidebar.classList.remove('is-open');
      overlay.classList.remove('is-visible');
    }
  }

  function toggleMobileSidebar() {
    setMobileSidebarState(!sidebar.classList.contains('is-open'));
  }

  function closeMobileSidebar() {
    setMobileSidebarState(false);
  }

  closeMobileSidebar();

  return {
    element: shell,
    viewport,
    explorerContainer,
    explorerActions: {
      collapseBtn: explorerHeader.querySelector('[data-action="collapse"]'),
      expandBtn: explorerHeader.querySelector('[data-action="expand"]')
    },
    searchInput,
    setSidebarActive: (id) => {
      document.querySelectorAll('.nav-item').forEach(b => b.classList.remove('active'));
      const active = document.querySelector(`.nav-item[data-target="${id}"]`);
      if (active) active.classList.add('active');
    }
  };
}
