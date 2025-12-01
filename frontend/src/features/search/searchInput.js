export function createSearchInput({ onQueryChange }) {
  const container = document.createElement('div');
  container.className = 'search-panel';
  container.setAttribute('role', 'search');

  const icon = document.createElement('span');
  icon.setAttribute('aria-hidden', 'true');
  icon.textContent = '⌕';
  icon.style.fontSize = '1.1rem';
  icon.style.opacity = '0.85';

  const input = document.createElement('input');
  input.type = 'search';
  input.placeholder = 'Search lectures, topics, or files…';
  input.autocomplete = 'off';
  input.spellcheck = false;
  input.setAttribute('aria-label', 'Search the repository');

  const shortcut = document.createElement('kbd');
  shortcut.textContent = '/';

  input.addEventListener('input', (event) => {
    onQueryChange?.(event.target.value.trim());
  });

  window.addEventListener('keydown', (event) => {
    if (event.key === '/' && !event.ctrlKey && !event.metaKey && !event.altKey) {
      event.preventDefault();
      input.focus();
      input.select();
    }
  });

  container.append(icon, input, shortcut);
  return { container, input };
}
