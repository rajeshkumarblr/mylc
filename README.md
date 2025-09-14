# mylc — LeetCode practice (C++ & Go)

Central runner + shared test harness. Problems and test data live in **`testcases.json`** and are executed by language-specific drivers.

**Problems covered:** 13  
**Languages:** C++, Go

## Repository layout
```
./
  env.sh           # sets paths and defaults (LC_LANG)
  run              # thin wrapper to run a single problem (cpp/go)
  testcases.json   # single source of truth for problems & cases
  src/
    cpp/           # C++ solutions + test harness
    go/            # Go solutions + test harness
    mk/            # helper scripts
  build/           # build artifacts (created on demand)
```
## Prerequisites
- **Linux/WSL/macOS** with `make`.
- **C++20** compiler (`g++` or `clang++`).
- **nlohmann/json** single‑header library installed system‑wide (e.g., `sudo apt-get install nlohmann-json3-dev`).
- **vsc-leetcode-cli** for submitting solutions (used by `make submit`):
  ```bash
  npm install -g vsc-leetcode-cli
  ```
- **Go 1.21+** (module mode).

## Quick start
```bash
# one-time
source ./env.sh

# C++: build & run all
make -C src/cpp run-all

# Go: build & run all
make -C src/go run-all

# Run a single problem via helper (defaults to LC_LANG=cpp)
./run 94           # runs C++ lc94 by default
./run 94 go        # runs Go version
```

## How it works
- `testcases.json` holds metadata for each problem:
  - `category` — tag like `tree`, `sliding_window`.
  - `description` — short human title.
  - `cases` — array of inputs/expected values interpreted by the harness.
- Main drivers:
  - **C++:** [`src/cpp/main.cpp`](src/cpp/main.cpp) reads `testcases.json` and dispatches to `lc_test_<id>(json)` functions for each problem.
  - **Go:** [`src/go/main.go`](src/go/main.go) reads `testcases.json` and dispatches to corresponding Go test functions.
- Language harnesses read `testcases.json` and call your solution functions for each test case.
# Running a problem locally
You can build and run a specific problem solution using:
```bash
make -C src/cpp run NUM=434   # C++: build & run problem 434
make -C src/go run NUM=434    # Go: build & run problem 434
make run 434                  # Uses LC_LANG (default: cpp) to run problem 434
```

## Problems & status
| # | Problem | Category | Test cases | Languages |
|---:|---|---|---:|---|
| 1 | Two Sum | `hash` | 2 | C++, Go |
| 2 | Add Two Numbers | `list` | 1 | C++, Go |
| 3 | Longest Substring Without Repeating Characters | `sliding_window` | 2 | C++, Go |
| 9 | Palindrome Number | `misc` | 5 | C++, Go |
| 11 | Container With Most Water | `two_pointer` | 3 | C++, Go |
| 21 | Merge Two Sorted Lists | `list` | 3 | C++, Go |
| 42 | Trapping Rain Water | `two_pointer` | 4 | C++, Go |
| 94 | Binary Tree Inorder Traversal | `tree` | 3 | C++, Go |
| 104 | Maximum Depth of Binary Tree | `tree` | 4 | C++, Go |
| 110 | Balanced Binary Tree | `tree` | 6 | C++, Go |
| 424 | Longest Repeating Character Replacement | `sliding_window` | 5 | C++, Go |
| 438 | Find All Anagrams in a String | `sliding_window` | 4 | C++, Go |
| 567 | Permutation in String | `sliding_window` | 5 | C++, Go |

## C++ workflow
Key targets (see `src/cpp/Makefile`):
```bash
make -C src/cpp 94        # build & run problem 94
make -C src/cpp run NUM=94 # same as above
make -C src/cpp run-all    # run all problems & print summary
make -C src/cpp submit NUM=94  # extract @lc code block to build/cpp/submit.94.cpp
```

## Go workflow
Key targets (see `src/go/Makefile`):
```bash
make -C src/go 94          # build & run problem 94
make -C src/go run NUM=94  # build & run
make -C src/go run-all     # run all problems through central runner
make -C src/go stress NUM=94 N=100000  # micro-stress a single problem
```

## Notes & tips
- Set default language via `LC_LANG` in `env.sh`.
- Binaries land in `build/cpp` and `build/go`; `env.sh` prepends them to `PATH` so `lc94` etc. are runnable directly.
- The harness prints a compact PASS/FAIL summary per case and a final result line.

## Adding a new problem
1. Add an entry to `testcases.json` with `category`, `description`, and `cases`.
2. Implement the solution file(s): `src/cpp/<id>.*.cpp` and/or `src/go/<id>.*.go`.
3. Implement `lc_test_<id>()` in the harness for that language if needed.
4. `make -C src/<lang> run NUM=<id>` or `./run <id> <lang>`.
