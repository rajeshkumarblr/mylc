# C++ Build & Test Guide

This directory hosts the C++ solutions plus a central test runner (`main.cpp`) that executes problems using `testcases.json`.

## Test Data Discovery Order
The runner looks for `testcases.json` in:
1. `./testcases.json`
2. `src/cpp/testcases.json`
3. `src/go/testcases.json` (current location in repo)

## Directory Layout
```
src/cpp/
  main.cpp              # central runner
  lc_test_utils.*       # shared JSON, list, tree utilities
  hash/                 # category subdirs (problem sources only)
  list/
  sliding_window/
  misc/
  two_pointer/
  tree/
```
Each problem file is named `<number>.<kebab-case-title>.cpp`.

## Build Artifacts
All objects & the unified binary are emitted under:
```
build/cpp/
  runner                # central executable
  <category>/*.o        # per-problem object files
  main.o
```

## Make Targets
From `src/cpp/`:

| Target | Purpose |
| ------ | ------- |
| `make` / `make build` | Build the runner (`build/cpp/runner`). |
| (execution moved) | Use top-level `./run` script to execute problems. |
| `make submit NUM=<id>` | Extract only the LeetCode @lc code block for submission. |
| `make clean` | Remove `build/cpp`. |

Execution examples (from repo root):
```
./run 1                 # run problem 1
./run -c tree           # run all tree problems
./run -a                # run everything
./run -l                # list categories & problems
make submit NUM=42      # extract problem 42 body to build/cpp/submit.42.cpp
```

## Environment Variables (Runner)
Set before invoking the runner (Make handles most for you):
- `REPO_ROOT` (auto-set by Make): absolute repo root used to resolve `testcases.json`.
- `LC_PROB_NUM` or legacy `NUM`: single problem id to run.
- `LC_CATEGORY`: run all problems in category if set (ignored if `LC_PROB_NUM` set).
- `LC_LANGUAGE=cpp`: identifies language for multi-language reporting.

When using the VS Code launch config `C++: Debug runner (single problem)` you can change `LC_PROB_NUM` to focus on a problem while debugging.

## Implementation Notes
- All problem sources are compiled once; selecting a subset just filters execution.
- The Makefile creates per-category object subdirectories automatically.
- Extra standalone `main()`s inside problem files should be disabled or guarded (recommended pattern: wrap standalone mains with `#ifdef LC_STANDALONE_MAIN`). Currently the central build passes `-DLC_LOCAL_TEST` but not `-DLC_STANDALONE_MAIN`; ensure problem files either don't declare a conflicting `main` or guard it.

## Adding a New Problem
1. Pick the correct category directory (create if genuinely new, otherwise reuse existing list).
2. Name the file `<number>.<kebab-case-title>.cpp`.
3. Implement the solution exposing the expected function signature used by the harness (see similar problems in the category for patterns).
4. Add test cases to `testcases.json` (under the root of the repo in `src/go` currently).
5. Run it via the script (from repo root):
  ```
  ./run <number>
  ```
6. (Optional) Debug in VS Code by updating `LC_PROB_NUM` in the launch configuration.

## Submitting to LeetCode
Use `make submit NUM=<id>` to generate a trimmed file with only the `@lc code` region to paste into LeetCode. Ensure your source is annotated:
```cpp
// @lc code=start
// solution body
// @lc code=end
```
The extracted file is written to `build/cpp/submit.<id>.cpp`.

## Troubleshooting
| Symptom | Fix |
| ------- | --- |
| Runner says problem not found | Check filename pattern and that `<id>` matches the numeric prefix. |
| No test cases picked up | Confirm `testcases.json` exists at one of the discovery paths. |
| Build error for object directory | Make sure category directory name appears in `CATEGORY_DIRS` in Makefile. |
| Debugger hits no breakpoints | Ensure you built with debug flags (`-g -O0` already in Makefile). |

## Future Improvements (Ideas)
- Auto-generate problem table in root `README.md` from filenames.
- Add timing / memory instrumentation.
- Optional JSON emit mode for CI.

---
_Last updated: automated refactor to category-based layout._
