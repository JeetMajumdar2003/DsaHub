# C++ DSA Showcase Web App

Immersive single-page web application that celebrates the breadth of the C++ DSA learning repository. Built with Vite, modern vanilla JavaScript, and a feature-sliced architecture for maintainability.

![Hero Screenshot](./assets/hero-placeholder.png)

## ✨ Highlights

- **Interactive explorer:** Collapsible tree to browse lectures and assets quickly.
- **Insightful dashboard:** Live statistics spotlighting coverage and keyword trends.
- **Fast search:** Instant filtering with keyboard shortcut (`/`) and highlighted matches.
- **Dynamic theming:** Light/dark mode respecting system preference with smooth toggles.
- **Static-first:** Zero backend; data generated from the repository tree via script.

## 🧱 Project Structure

```
web-app/
├── public/
│   └── data/           # Generated dataset (codebase.json)
├── scripts/
│   └── generate-codebase-data.mjs
├── src/
│   ├── app/
│   ├── features/
│   ├── pages/
│   ├── shared/
│   └── widgets/
└── docs/
```

## 🚀 Quickstart

1. **Install dependencies**
   ```powershell
   npm install
   ```
2. **Generate dataset**
   ```powershell
   npm run generate:data
   ```
3. **Start development server**
   ```powershell
   npm run dev
   ```
4. Open [`http://localhost:5173`](http://localhost:5173) to explore the showcase.

## 📦 Scripts

| Command | Description |
| --- | --- |
| `npm run dev` | Start Vite dev server |
| `npm run build` | Bundle production build |
| `npm run preview` | Preview production build |
| `npm run test` | Run Vitest suite once |
| `npm run test:watch` | Run Vitest in watch mode |
| `npm run lint` | Lint source files |
| `npm run format` | Prettier formatting |
| `npm run generate:data` | Rebuild static dataset |

## 🧪 Testing

Vitest is preconfigured with JSDOM environment. Place tests alongside modules using the `.test.js` suffix. Example skeleton:

```js
import { describe, it, expect } from 'vitest';

import { filterTree } from '../shared/lib/search.js';

describe('filterTree', () => {
  it('filters nodes', () => {
    expect(filterTree([{ name: 'LEC-01', children: [] }], 'lec')).toHaveLength(1);
  });
});
```

Run with:

```powershell
npm run test
```

## 🔁 Dataset Regeneration

The explorer reads from `public/data/codebase.json`. Refresh the dataset whenever repository contents change.

```powershell
npm run generate:data
```

> **Note:** Dataset generation excludes the `web-app` directory to avoid recursion.

## 🛠️ Tech Stack

- [Vite](https://vitejs.dev/) – lightning-fast bundler
- Vanilla JS with ES modules – lightweight and flexible
- CSS custom properties, grids, flexbox for layout and theming
- Vitest + JSDOM – testing environment

## 📚 Documentation

Product requirements and task tracking live under `docs/`:

- `docs/prd/showcase-web-app.prd.md`
- `docs/todos/showcase-web-app.todos.md`

Stay in sync by updating the PRD/TODO after significant feature work.

## 📄 License

This project inherits the repository license located at the root `LICENCE` file.
