# Security Policy

## Supported Versions

| Version | Supported |
|---------|-----------|
| `main`  | ✅
| Releases/tags | ✅ (latest tag only)

Older snapshots may remain in the history but do not receive security updates.

## Reporting a Vulnerability

1. **Do not open a public issue.** Instead, create a private security advisory via the GitHub Security tab (`Security` → `Advisories` → `Report a vulnerability`).
2. Alternatively, send a private message to the maintainer via the email listed on [@JeetMajumdar2003](https://github.com/JeetMajumdar2003)'s GitHub profile.
3. Provide as much detail as possible:
   - Affected files and functions
   - Steps to reproduce
   - Potential impact (data exposure, remote execution, etc.)
   - Suggested mitigation if known

We aim to acknowledge new reports within **72 hours** and provide a remediation timeline within **7 days**. Please give us a reasonable opportunity to fix the issue before any public disclosure.

## Scope

This policy covers:
- All C++ source under the `LEC-*` folders
- Documentation or notes that may ship executable snippets
- The `frontend/` Vite application and related build scripts

Third-party dependencies vendored into the repository should be reported upstream, though we welcome heads-up notifications.

Thanks for helping us keep the community safe! 🙏
