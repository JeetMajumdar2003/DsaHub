# Contributing Guide

Thanks for your interest in improving **Data Structures & Algorithms in C++**! Contributions of every size are welcome—from typo fixes and documentation tweaks to entirely new algorithm implementations.

---

## 📜 Code of Conduct

Participation in this project is governed by the [Code of Conduct](CODE_OF_CONDUCT.md). By contributing, you agree to uphold an inclusive, respectful community.

---

## 🧰 Ways to Contribute

- **Report bugs** using the *Bug Report* issue template.
- **Request features** through the *Feature Request* template.
- **Improve documentation** (README, notes, comments, diagrams, etc.).
- **Add or optimize algorithms/data structures** with well-documented C++17 code.
- **Enhance the frontend** (visualizations, UI polish, tests, accessibility updates).

---

## 🛠️ Development Setup

### Clone the repository

```bash
git clone https://github.com/JeetMajumdar2003/DSA.git
cd DSA
```

### C++ workspace

- Use any C++17-compatible compiler (GCC, Clang, MSVC).
- Keep each lecture/program self-contained (inputs/outputs described in comments).
- Prefer header-only helpers to minimize shared-state coupling between lectures.

### Frontend workspace

```bash
cd frontend
npm install
npm run dev           # Start local server
npm run test          # Run unit tests (Vitest)
npm run lint          # ESLint + Prettier
```

---

## 🧑‍💻 Coding Guidelines

### C++
- Target **C++17**; avoid compiler-specific extensions when possible.
- Prefer `std::vector`, `std::array`, `std::unique_ptr`, and other STL utilities over raw pointers unless demonstrating pointer behavior.
- Document the algorithm, constraints, and time/space complexity at the top of each file.
- Keep functions short and focused; extract helpers if a `main()` grows beyond ~80 lines.

### Frontend
- Follow the existing ESLint + Prettier configuration.
- Type everything (TypeScript) when authoring new modules.
- Co-locate component, style, and test files when practical.

### General
- Use descriptive names (`findFirstOccurrence`, `binarySearchIterative`) over abbreviations.
- Keep line length ≤ 110 characters when reasonable.
- Add KaTeX/Markdown diagrams whenever formulas or recurrences are involved.

---

## 🌿 Branching & Commits

1. Create a feature branch from `main`:
   ```bash
   git checkout -b feature/add-binary-tree-views
   ```
2. Write clear, present-tense commits. Conventional commits are encouraged, e.g. `feat: add binary heap delete operation`.
3. Keep PRs focused. Separate unrelated changes into different branches/PRs.

---

## ✅ Pull Request Checklist

Before opening a PR:

- [ ] All code/lint/tests pass locally (`npm run lint`, `npm run test`, relevant C++ builds).
- [ ] Documentation is updated (README, lecture notes, comments) if behavior changed.
- [ ] New algorithms include sample input/output and complexity info.
- [ ] Issue/feature request linked in the PR description (`Fixes #123`).
- [ ] Screenshots or terminal output attached when UI or CLI behavior changes.

Use the provided [PR template](.github/PULL_REQUEST_TEMPLATE.md) so reviewers can respond quickly.

---

## 📦 Adding New Algorithms or Notes

1. Create a new lecture folder if necessary following the `LEC-XX(Topic)` naming pattern.
2. Include both the `.cpp` source and (optionally) a compiled `.exe` for Windows users.
3. Update any relevant index (README, docs, frontend data) so the addition is discoverable.
4. Mention edge cases, constraints, and links/reference materials inside the file header.

---

## 🧑‍🤝‍🧑 Getting Help

- Open a draft PR early if you want feedback.
- Start a discussion/issue if you are unsure where a contribution fits.
- Tag maintainers (`@JeetMajumdar2003`) for direction on roadmap-aligned tasks.

Thanks again for helping grow this knowledge base! 🙌
