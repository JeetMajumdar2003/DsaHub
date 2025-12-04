import { useEffect, useRef, useState } from 'react';

const LANGUAGE_MAP = {
  cpp: 'language-cpp',
  c: 'language-c',
  h: 'language-cpp',
  hpp: 'language-cpp',
  js: 'language-javascript',
  json: 'language-json',
  md: 'language-markdown',
  html: 'language-html',
  css: 'language-css'
};

function joinWithBase(base, target) {
  const normalizedBase = base.endsWith('/') ? base : `${base}/`;
  const normalizedTarget = target.replace(/^\/+/, '');
  return `${normalizedBase}${normalizedTarget}`;
}

async function fetchText(url, options) {
  const response = await fetch(url, options);
  if (!response.ok) {
    throw new Error(`Request failed (${response.status})`);
  }
  return response.text();
}

async function loadFile(pathname) {
  const encodedPath = encodeURI(pathname);
  const basePath = import.meta.env.BASE_URL ?? '/';
  const staticUrl = joinWithBase(basePath, pathname);
  const apiUrl = joinWithBase(basePath, `api/source/${encodedPath}`);

  const staticFetch = () =>
    fetchText(staticUrl, {
      headers: {
        Accept: 'text/plain, text/*;q=0.9, */*;q=0.8'
      }
    });

  if (import.meta.env.DEV) {
    return fetchText(apiUrl);
  }

  try {
    return await staticFetch();
  } catch (error) {
    console.warn(`Static fetch failed for ${pathname}:`, error);
    return fetchText(apiUrl);
  }
}

function getLanguageClass(filename) {
  const ext = filename.split('.').pop()?.toLowerCase();
  return LANGUAGE_MAP[ext] ?? 'language-none';
}

async function legacyCopy(text) {
  return new Promise((resolve, reject) => {
    const textarea = document.createElement('textarea');
    textarea.value = text;
    textarea.setAttribute('readonly', '');
    textarea.style.position = 'absolute';
    textarea.style.left = '-9999px';
    document.body.appendChild(textarea);
    textarea.select();
    try {
      const successful = typeof document.execCommand === 'function' ? document.execCommand('copy') : false;
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
  if (navigator?.clipboard?.writeText) {
    return navigator.clipboard.writeText(text);
  }
  return legacyCopy(text);
}

export function FileViewer({ node }) {
  const codeRef = useRef(null);
  const [contentState, setContentState] = useState({ status: 'loading', content: '', error: null });
  const [copyState, setCopyState] = useState('idle');

  useEffect(() => {
    let cancelled = false;
    setContentState({ status: 'loading', content: '', error: null });

    loadFile(node.path)
      .then((text) => {
        if (cancelled) return;
        setContentState({ status: 'ready', content: text, error: null });
      })
      .catch((error) => {
        if (cancelled) return;
        setContentState({ status: 'error', content: '', error });
      });

    return () => {
      cancelled = true;
    };
  }, [node.path]);

  useEffect(() => {
    if (contentState.status === 'ready' && codeRef.current && typeof window !== 'undefined' && window.Prism) {
      window.Prism.highlightElement(codeRef.current);
    }
  }, [contentState]);

  const disabled = contentState.status !== 'ready';
  const languageClass = getLanguageClass(node.name ?? node.path);

  const handleCopy = async () => {
    if (disabled) return;
    setCopyState('idle');
    try {
      await copyToClipboard(contentState.content);
      setCopyState('success');
      setTimeout(() => setCopyState('idle'), 2000);
    } catch (error) {
      console.error('Failed to copy code snippet:', error);
      setCopyState('error');
      setTimeout(() => setCopyState('idle'), 2000);
    }
  };

  let codeContent = contentState.content;
  if (contentState.status === 'loading') {
    codeContent = 'Loading content...';
  }
  if (contentState.status === 'error') {
    codeContent = `Error loading file: ${contentState.error?.message ?? 'Unknown error'}\n\nMake sure the development server is running and the file exists.`;
  }

  const tooltipText =
    copyState === 'success' ? 'Copied!' : copyState === 'error' ? 'Copy failed' : '';

  return (
    <div className="file-viewer" style={{ marginTop: 'var(--space-xl)' }}>
      <button
        type="button"
        className={['file-copy-btn', copyState === 'success' ? 'is-success' : '', copyState === 'error' ? 'is-error' : '']
          .filter(Boolean)
          .join(' ')}
        onClick={handleCopy}
        disabled={disabled}
        aria-live="polite"
        aria-label={copyState === 'success' ? 'Copied!' : 'Copy file contents'}
        data-tooltip={tooltipText}
      >
        <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round">
          <rect x="9" y="9" width="13" height="13" rx="2" ry="2" />
          <path d="M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2-2h9a2 2 0 0 1 2 2v1" />
        </svg>
      </button>
      <pre className="code-block">
        <code ref={codeRef} className={languageClass}>
          {codeContent}
        </code>
      </pre>
    </div>
  );
}
