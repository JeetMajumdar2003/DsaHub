<div align="center">

# Data Structures & Algorithms in C++

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENCE)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![CI ready](https://img.shields.io/badge/CI-ready-success.svg)](#-project-roadmap)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](CONTRIBUTING.md)
[![Open Source Love](https://badges.frapsoft.com/os/v2/open-source.svg?v=103)](https://github.com/JeetMajumdar2003/DSA)

**Hands-on implementations, lecture notes, and interview-ready problem sets for mastering classic and modern DSA topics in C++.**

</div>

---

## 🧭 Overview

This repository follows the PW Skills DSA curriculum and extends it with production-ready C++ implementations, annotated notes, and a Vite-powered frontend for interactive exploration. Use it as a self-paced learning path, a reference while interviewing, or a base to contribute new techniques.

### Highlights

- 🎓 Structured by lecture so you can jump to any topic quickly.
- 🧠 Covers fundamentals through advanced graph and DP problems.
- 🛠️ Includes ready-to-run C++17 source plus compiled artifacts for Windows users.
- 🌐 Ships with a modern frontend (`frontend/`) for visualization and experimentation.
- 🤝 Open to community contributions with clear guidelines and templates.

---

## 🛠️ Tech Stack

- **Languages:** Modern C++17, TypeScript/JavaScript
- **Tooling:** GCC/MSVC, Vite, Vitest, ESLint, Prettier
- **Paradigms:** Object-Oriented Programming, Functional Recursion, Dynamic Programming
- **Docs:** Markdown, KaTeX (when formulas are required)

---

## ✨ Key Features

| Area | What you get |
|------|--------------|
| Algorithms | Classic + interview-focused problems with clean C++ implementations |
| Complexity Guides | Time/space breakdowns and comparative tables |
| Notes | "C++ Imp Notes" folder for quick language refreshers |
| Frontend | Vite app for interactive demos and visualizations |
| Templates | Issue, PR, contributing, conduct, support, and security policies |

---

## 🗂️ Repository Tour

```
DSA/
├── C++ Imp Notes/        # Important C++ summaries
├── docs/                 # PRDs, todos, and planning notes
├── frontend/             # Vite-based visualization app
├── LEC-XX(...)/          # Lecture-wise source code & binaries
├── LICENCE               # MIT license text
├── README.md             # You are here 📍
├── CONTRIBUTING.md       # How to contribute
├── CODE_OF_CONDUCT.md    # Community expectations
├── SECURITY.md           # Vulnerability policy
├── SUPPORT.md            # Getting help
└── .github/              # Issue & PR templates
```

> Each `LEC-*` directory contains standalone `.cpp` files and, when relevant, pre-built `.exe` binaries for fast verification on Windows.

---

## 🚀 Getting Started

### Prerequisites

- C++17-compatible compiler (GCC 9+, Clang 10+, or MSVC 2019+)
- Git 2.30+
- Node.js 18+ (only required for the `frontend/` app)
- A terminal or IDE (VS Code recommended)

### Clone & Explore

```bash
git clone https://github.com/JeetMajumdar2003/DSA.git
cd DSA
```

### Build & Run a Sample C++ Program

```bash
cd "LEC-44(Binary Search)"
g++ -std=c++17 Binary_Search_Algorithm.cpp -o binary_search
./binary_search    # On Windows use: binary_search.exe
```

### Run the Frontend Playground

```bash
cd frontend
npm install
npm run dev
```

> See `frontend/README.md` for production builds, linting, and test commands.

---

## 🧪 Usage

- **Per-topic experiments:** compile and run any `.cpp` file directly; each file contains a `main()` entry point and descriptive comments.
- **Homework/problem practice:** look for `Problems on ...` lecture folders for curated sets.
- **Interactive view:** use the frontend to visualize algorithms and compare complexities.
- **Notes revision:** skim `C++ Imp Notes/` before interviews for language refreshers.

---

## 📚 Topic Coverage Snapshot

| Track | Lectures | Focus |
|-------|----------|-------|
| Foundations | LEC 3-26 | Variables, control flow, pointers |
| Recursion | LEC 27-34 | Recursion patterns & classic problems |
| Sorting & Searching | LEC 35-47 | From Bubble Sort to advanced binary search variants |
| Strings & OOP | LEC 48-49 | String APIs, OOP pillars, STL usage |
| Linked Lists to Queues | LEC 50-58 | Multiple list types, stacks, queues |
| Hashing & Backtracking | LEC 59-64 | Hash maps/sets, backtracking templates |
| Trees & Heaps | LEC 65-71 | Binary trees, BSTs, heaps, priority queues |
| Advanced Strategies | LEC 72-86 | Greedy, DP, graphs, MST, Dijkstra |

> Detailed breakdowns live inside each lecture folder along with example inputs, outputs, and complexities.

---

## 🗺️ Project Roadmap

- [ ] Add unit tests for newly contributed algorithms.
- [ ] Publish hosted version of the frontend playground.
- [ ] Add continuous integration (GitHub Actions) for C++ build + frontend lint/test.
- [ ] Expand documentation with video links per lecture.
- [ ] Tag issues for "good first issue" to onboard contributors.

See [open issues](https://github.com/JeetMajumdar2003/DSA/issues) for current priorities.

---

## 🤝 Contributing

We welcome fixes, optimizations, docs improvements, and new problem solutions. Please:

1. Read `CONTRIBUTING.md` for branching, coding style, and commit message guidance.
2. Abide by the `CODE_OF_CONDUCT.md` to keep the community inclusive.
3. Use the provided issue and PR templates so maintainers can review quickly.

> Unsure where to begin? Check the project board or open issues labeled **help wanted** or **good first issue**.

---

## 💬 Community & Support

- Need help? Start with `SUPPORT.md` for FAQ and contact options.
- Found a vulnerability? Follow the process in `SECURITY.md`.
- Want to discuss ideas? Open a discussion or reach out via issues.

---

## 📄 License

Copyright (c) 2025 Jeet Majumdar.

Distributed under the MIT License. See [`LICENCE`](LICENCE) for the full text.

---

## 👤 Maintainer

- **Jeet Majumdar** – [@JeetMajumdar2003](https://github.com/JeetMajumdar2003)

If this project helps you, please ⭐ the repo and share it with fellow learners!