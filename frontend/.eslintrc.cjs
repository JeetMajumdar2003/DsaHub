module.exports = {
  root: true,
  env: {
    browser: true,
    es2022: true
  },
  parserOptions: {
    ecmaVersion: 'latest',
    sourceType: 'module',
    ecmaFeatures: {
      jsx: true
    }
  },
  extends: ['eslint:recommended', 'plugin:import/recommended', 'plugin:react/recommended', 'plugin:react-hooks/recommended', 'prettier'],
  plugins: ['import', 'react'],
  settings: {
    react: {
      version: 'detect'
    },
    'import/resolver': {
      node: {
        extensions: ['.js', '.jsx']
      },
      alias: {
        map: [
          ['@components', './src/components'],
          ['@pages', './src/pages'],
          ['@widgets', './src/widgets'],
          ['@features', './src/features'],
          ['@shared', './src/shared'],
          ['@assets', './src/assets']
        ],
        extensions: ['.js', '.jsx']
      }
    }
  },
  rules: {
    'import/order': [
      'warn',
      {
        groups: [['builtin', 'external'], ['internal'], ['parent', 'sibling', 'index']],
        'newlines-between': 'always',
        alphabetize: {
          order: 'asc',
          caseInsensitive: true
        }
      }
    ],
    'no-console': ['warn', { allow: ['warn', 'error'] }],
    'no-unused-vars': [
      'warn',
      {
        argsIgnorePattern: '^_',
        varsIgnorePattern: '^_'
      }
    ],
    'react/react-in-jsx-scope': 'off',
    'react/jsx-uses-react': 'off',
    'react/prop-types': 'off'
  }
};
