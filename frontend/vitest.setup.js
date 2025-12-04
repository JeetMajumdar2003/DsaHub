import '@testing-library/jest-dom/vitest';
import { beforeEach } from 'vitest';

globalThis.IS_REACT_ACT_ENVIRONMENT = true;

globalThis.matchMedia =
  globalThis.matchMedia ||
  function matchMedia(query) {
    return {
      media: query,
      matches: false,
      onchange: null,
      addListener() {},
      removeListener() {},
      addEventListener() {},
      removeEventListener() {},
      dispatchEvent() {
        return false;
      }
    };
  };

beforeEach(() => {
  document.body.innerHTML = '';
});
