import './styles.css';

import { renderHomePage } from '@pages/home/homePage.js';
import { fetchCodebaseDataset } from '@shared/lib/dataClient.js';

const root = document.getElementById('app');

function createLoader() {
  const loader = document.createElement('div');
  loader.style.minHeight = '100vh';
  loader.style.display = 'grid';
  loader.style.placeContent = 'center';
  loader.style.color = 'var(--color-text)';
  loader.style.fontFamily = 'var(--font-mono)';
  loader.innerHTML = '<span>Loading showcase ✨</span>';
  return loader;
}

function createErrorState(message, retry) {
  const error = document.createElement('div');
  error.style.minHeight = '100vh';
  error.style.display = 'grid';
  error.style.placeContent = 'center';
  error.style.textAlign = 'center';
  error.style.padding = 'var(--space-xl)';
  error.innerHTML = `
    <div style="display:grid;gap:var(--space-md);max-width:420px;">
      <span style="font-size:1.5rem;">⚠️</span>
      <h2 style="margin:0;">We hit a snag loading the dataset</h2>
      <p style="margin:0;color:var(--color-text-muted);">${message}</p>
      <button class="primary-button" type="button">Retry</button>
    </div>
  `;
  const button = error.querySelector('button');
  button.addEventListener('click', retry);
  return error;
}

async function boot() {
  const loader = createLoader();
  root.replaceChildren(loader);

  try {
    const dataset = await fetchCodebaseDataset();
    renderHomePage(root, dataset);
  } catch (error) {
    console.error(error);
    root.replaceChildren(
      createErrorState(error.message, () => {
        boot();
      })
    );
  }
}

boot();
