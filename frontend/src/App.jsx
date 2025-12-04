import { useCallback, useEffect, useState } from 'react';

import { HomePage } from '@pages/home/HomePage.jsx';
import { fetchCodebaseDataset } from '@shared/lib/dataClient.js';

const STATUS = {
  IDLE: 'idle',
  LOADING: 'loading',
  READY: 'ready',
  ERROR: 'error'
};

function FullscreenMessage({ title, message, children }) {
  return (
    <div
      style={{
        minHeight: '100vh',
        display: 'grid',
        placeContent: 'center',
        padding: 'var(--space-xl)',
        textAlign: 'center',
        color: 'var(--color-text)',
        fontFamily: 'var(--font-mono)'
      }}
    >
      <div style={{ display: 'grid', gap: 'var(--space-md)', maxWidth: 420 }}>
        {title ? <h2 style={{ margin: 0 }}>{title}</h2> : null}
        {message ? (
          <p style={{ margin: 0, color: 'var(--color-text-muted)' }}>{message}</p>
        ) : null}
        {children}
      </div>
    </div>
  );
}

export default function App() {
  const [state, setState] = useState({
    status: STATUS.LOADING,
    dataset: null,
    error: null
  });

  const loadDataset = useCallback(async () => {
    setState({ status: STATUS.LOADING, dataset: null, error: null });

    try {
      const dataset = await fetchCodebaseDataset();
      setState({ status: STATUS.READY, dataset, error: null });
    } catch (error) {
      setState({ status: STATUS.ERROR, dataset: null, error });
    }
  }, []);

  useEffect(() => {
    loadDataset();
  }, [loadDataset]);

  if (state.status === STATUS.LOADING) {
    return (
      <FullscreenMessage title="Loading showcase ✨" message="Fetching the latest dataset snapshot" />
    );
  }

  if (state.status === STATUS.ERROR) {
    return (
      <FullscreenMessage title="We hit a snag" message={state.error?.message ?? 'Unknown error'}>
        <button className="primary-button" type="button" onClick={loadDataset}>
          Retry
        </button>
      </FullscreenMessage>
    );
  }

  return <HomePage dataset={state.dataset} />;
}
