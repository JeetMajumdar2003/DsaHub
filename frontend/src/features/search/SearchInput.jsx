import { useEffect, useRef } from 'react';

export function SearchInput({ value, onChange }) {
  const inputRef = useRef(null);

  useEffect(() => {
    function handleKeyDown(event) {
      if (event.key === '/' && !event.ctrlKey && !event.metaKey && !event.altKey && !event.shiftKey) {
        const target = event.target;
        const isInEditableField = target instanceof HTMLElement && (target.isContentEditable || ['INPUT', 'TEXTAREA', 'SELECT'].includes(target.tagName));
        if (isInEditableField) {
          return;
        }
        event.preventDefault();
        inputRef.current?.focus();
        inputRef.current?.select();
      }
    }

    window.addEventListener('keydown', handleKeyDown);
    return () => window.removeEventListener('keydown', handleKeyDown);
  }, []);

  return (
    <div className="search-panel" role="search">
      <span className="search-panel__icon" aria-hidden="true">
        <svg
          width="16"
          height="16"
          viewBox="0 0 24 24"
          fill="none"
          stroke="currentColor"
          strokeWidth="2"
          strokeLinecap="round"
          strokeLinejoin="round"
        >
          <circle cx="11" cy="11" r="7" />
          <line x1="21" y1="21" x2="16.65" y2="16.65" />
        </svg>
      </span>
      <input
        ref={inputRef}
        type="search"
        value={value}
        onChange={(event) => onChange(event.target.value)}
        placeholder="Search lectures, topics, or files…"
        autoComplete="off"
        spellCheck={false}
        aria-label="Search the repository"
      />
      <kbd aria-hidden="true">/</kbd>
    </div>
  );
}
