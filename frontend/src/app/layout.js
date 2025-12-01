import { createThemeToggle } from '@features/theme/themeToggle.js';
import { createSearchInput } from '@features/search/searchInput.js';

export function createAppShell({ onNavigate, onSearch }) {
  const shell = document.createElement('div');
  shell.className = 'app-shell';

  // --- Sidebar ---
  const sidebar = document.createElement('aside');
  sidebar.className = 'app-sidebar';

  const brand = document.createElement('div');
  brand.className = 'sidebar-brand';
  brand.innerHTML = `
    <svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
      <path d="M4 19.5A2.5 2.5 0 0 1 6.5 17H20"></path>
      <path d="M6.5 2H20v20H6.5A2.5 2.5 0 0 1 4 19.5v-15A2.5 2.5 0 0 1 6.5 2z"></path>
    </svg>
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
    <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
      <polyline points="15 18 9 12 15 6"></polyline>
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
  const viewport = document.createElement('div');
  viewport.className = 'app-viewport';

  main.append(header, viewport);
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
