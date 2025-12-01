import { defineConfig } from 'vite';
import fs from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const repoRoot = path.resolve(__dirname, '..');
const dataRoot = path.resolve(repoRoot, 'data');

export default defineConfig({
  server: {
    open: true,
    port: 5173,
    fs: {
      allow: ['..']
    }
  },
  plugins: [
    {
      name: 'serve-source',
      configureServer(server) {
        server.middlewares.use('/api/source', (req, res, next) => {
          try {
            const decodedUrl = decodeURIComponent(req.url || '/');
            const [requestPath] = decodedUrl.split('?');
            const trimmedPath = requestPath.replace(/^\/+/, '');

            if (!trimmedPath) {
              res.statusCode = 400;
              res.end('Missing file path');
              return;
            }

            // Prevent directory traversal attacks
            if (trimmedPath.includes('..')) {
              res.statusCode = 403;
              res.end('Forbidden');
              return;
            }

            const filePath = path.resolve(repoRoot, trimmedPath);

            if (!filePath.startsWith(dataRoot)) {
              res.statusCode = 403;
              res.end('Forbidden');
              return;
            }

            if (fs.existsSync(filePath) && fs.statSync(filePath).isFile()) {
              res.setHeader('Content-Type', 'text/plain');
              const stream = fs.createReadStream(filePath);
              stream.pipe(res);
            } else {
              next();
            }
          } catch (e) {
            console.error('Error serving file:', e);
            next();
          }
        });
      }
    }
  ],
  resolve: {
    alias: {
      '@app': '/src/app',
      '@pages': '/src/pages',
      '@widgets': '/src/widgets',
      '@features': '/src/features',
      '@shared': '/src/shared'
    }
  },
  test: {
    environment: 'jsdom',
    globals: true,
    setupFiles: ['./vitest.setup.js'],
    coverage: {
      reporter: ['text', 'html'],
      exclude: ['**/node_modules/**', 'public/**']
    }
  },
  build: {
    target: 'es2018',
    outDir: 'dist',
    emptyOutDir: true
  }
});
