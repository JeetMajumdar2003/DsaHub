const DATA_PATH = `${import.meta.env.BASE_URL ?? '/'}data/codebase.json`;

function buildDatasetUrl() {
  const cacheBuster = Date.now().toString();

  if (typeof window !== 'undefined' && window.location?.origin) {
    const url = new URL(DATA_PATH, window.location.origin);
    url.searchParams.set('v', cacheBuster);
    return url.toString();
  }

  const separator = DATA_PATH.includes('?') ? '&' : '?';
  return `${DATA_PATH}${separator}v=${cacheBuster}`;
}

async function safeParseJSON(response) {
  const text = await response.text();
  try {
    return JSON.parse(text);
  } catch (error) {
    throw new Error(`Failed to parse dataset JSON: ${error.message}`);
  }
}

export async function fetchCodebaseDataset({ signal } = {}) {
  const url = buildDatasetUrl();
  const response = await fetch(url, {
    signal,
    headers: {
      Accept: 'application/json'
    }
  });

  if (!response.ok) {
    throw new Error(`Unable to load dataset (${response.status})`);
  }

  return safeParseJSON(response);
}
