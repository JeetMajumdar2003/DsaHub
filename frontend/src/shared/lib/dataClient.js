const DATA_URL = '/data/codebase.json';

async function safeParseJSON(response) {
  const text = await response.text();
  try {
    return JSON.parse(text);
  } catch (error) {
    throw new Error(`Failed to parse dataset JSON: ${error.message}`);
  }
}

export async function fetchCodebaseDataset({ signal } = {}) {
  const url = `${DATA_URL}?v=${Date.now()}`;
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
