# Go Build & Test Guide

This directory hosts Go solutions plus a central runner (`main.go`) that executes problems using `testcases.json` via shared utilities in `lc_test_utils.go`.

## Test Data Discovery
The same discovery order as C++ (handled in shared logic):
1. `./testcases.json`
2. `src/cpp/testcases.json`
3. `src/go/testcases.json` (current location)

## Directory Layout
```
src/go/
  main.go             # central runner (package main)
  lc_test_utils.go    # shared JSON parsing, list/tree helpers, registry
  hash/
  list/
  sliding_window/
  misc/
  two_pointer/
  tree/
```
Problem filenames follow `<number>.<kebab-case-title>.go` and remain `package main` so they can all compile together once merged.

## Build Strategy (Why a Merge Directory?)
Go requires all `package main` files in a single directory for a single build. To keep category subfolders (for organization) without creating separate packages, the Makefile:
1. Collects all source files (`main.go`, `lc_test_utils.go`, and problem files).
2. Copies them into a temporary directory: `build/go/_merged`.
3. Initializes (or reuses) a simple temp module `tempbuild`.
4. Runs `go build` there to produce the unified binary: `build/go/runner`.

This keeps per-problem files simple (no imports back into a shared lib) while maintaining a single binary.

## Key Artifacts
```
build/go/
  runner       # central executable
  _merged/     # temporary build directory (safe to delete)
```

## Make Targets
Run these from `src/go/`:

| Target | Purpose |
| ------ | ------- |
| `make run <n|all|category>` | Build (if needed) & run a single problem, all, or a category. |
| `make run-all` | Build & run all problems (alias: `make all`). |
| `make NUM=42 build` | Build a minimal binary with only problem 42 + harness. |
| `make fmt` | Format all Go files. |
| `make vet` | Run `go vet` for static checks. |
| `make clean` | Remove `build/go` contents (keeps directory). |
| `make distclean` | Remove all artifacts including directory (if empty). |
| `make help` | Show usage summary. |

Examples:
```
make run 1
make run all
make run tree
make NUM=3 build
```

## Environment Variables (Runtime)
Set before launching `build/go/runner` (the Makefile does most automatically):
- `REPO_ROOT`: absolute path to repo root (used to locate `testcases.json`).
- `LC_PROB_NUM`: numeric id to run a single problem.
- `LC_CATEGORY`: run all problems in a category (ignored if `LC_PROB_NUM` is set).
- `LC_LANGUAGE=go`: language tag (used in multi-language contexts).
- `LC_STRESS_ITERS`: repeat count for stress mode (default 1).

## VS Code Debugging
Use the `Go: Debug runner (single problem)` launch config (in `.vscode/launch.json`). Change `LC_PROB_NUM` to target a different problem. For a category run, remove `LC_PROB_NUM` and set `LC_CATEGORY`.

## Adding a New Problem
1. Choose the correct category directory (create only if genuinely new category).
2. Add `<id>.<kebab-case-title>.go` with `package main`.
3. Implement the solution function & any helpers (keep names consistent with existing patterns for the data types: lists, trees, etc.).
4. Register the problem in the `funcRegistry` map inside `lc_test_utils.go` if required (depending on current harness pattern).
5. Add test cases to `testcases.json`.
6. Run `make run <id>` to verify.

## Minimal Single Problem Build
You can build a lightweight binary containing only one problem plus the runner:
```
make NUM=100 build
./../../build/go/lc100
```
This is faster when iterating on a single solution.

## Stress / Race / Debug Modes (Suggested Extensions)
You can extend the Makefile with additional targets (some already hinted in comments):
- `stress`: loop a problem with `LC_STRESS_ITERS` high value.
- `race`: add `-race` to the build command.
- `dbg`: use Delve directly (or rely on VS Code config).

## Troubleshooting
| Symptom | Fix |
| ------- | --- |
| Missing problem at runtime | Verify filename starts with numeric id and is `package main`. |
| Build fails in `_merged` about module | Ensure temp directory not left partially written; `make clean` then rebuild. |
| Cannot set breakpoint | Rebuild, ensure binary not stripped (no extra `-ldflags -s -w`). |
| Category run skips files | Confirm category name is listed in `CATEGORY_DIRS` in Makefile. |

## Future Ideas
- Auto-generate registry from filenames.
- Optional per-problem benchmarks (using `testing` package separately).
- JSON output mode for CI dashboards.

---
_Last updated: synced with category-based layout & merge-build harness._
