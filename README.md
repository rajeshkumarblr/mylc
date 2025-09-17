# mylc — LeetCode practice (C++ & Go)

Central runner + shared test harness. Problems and test data live in **`testcases.json`** and are executed by language-specific drivers.

**Problems covered:** 16  
**Languages:** C++, Go

For complete usage, build, and troubleshooting details, see [USAGE.md](./USAGE.md).

## Quick start
```bash
# (optional) set a default language for the run helper
export LC_LANG=cpp   # or: go

# run a single problem (auto-builds runner on first use)
./run -p 94

# run a category (e.g., tree)
./run -c tree

# list categories & problems from testcases.json
./run -l
```

## Repository layout
```
./
  .env             # primary config for defaults (e.g., LC_LANG); not committed
  run              # helper script: builds runner on demand & executes tests
  testcases.json   # single source of truth for problems & cases
  src/
    cpp/
      hash/ list/ sliding_window/ misc/ two_pointer/ tree/
        <id>.*.cpp  # per-problem sources grouped by category
      main.cpp lc_test_utils.*  Makefile
    go/
      hash/ list/ sliding_window/ misc/ two_pointer/ tree/
        <id>.*.go   # per-problem sources grouped by category
      main.go lc_test_utils.go Makefile
  build/           # build artifacts (created on demand)
```

## Prerequisites
- Linux/WSL/macOS with `make`
- C++20 compiler (`g++` or `clang++`)
- Go 1.21+ (module mode)
- (Optional) `nlohmann/json` single-header; vendored or system-wide

## Problems & status
| # | Problem | Category | Test cases | Languages |
|---:|---|---|---:|---|
| 1 | Two Sum | `hash` | 2 | C++, Go |
| 2 | Add Two Numbers | `list` | 1 | C++, Go |
| 3 | Longest Substring Without Repeating Characters | `sliding_window` | 2 | C++, Go |
| 9 | Palindrome Number | `misc` | 6 | C++, Go |
| 11 | Container With Most Water | `two_pointer` | 9 | C++, Go |
| 21 | Merge Two Sorted Lists | `list` | 7 | C++, Go |
| 42 | Trapping Rain Water | `two_pointer` | 6 | C++, Go |
| 94 | Binary Tree Inorder Traversal | `tree` | 5 | C++, Go |
| 100 | Same Tree | `tree` | 5 | C++, Go |
| 102 | Binary Tree Level Order Traversal | `tree` | 5 | C++, Go |
| 103 | Binary Tree Zigzag Level Order Traversal | `tree` | 5 | C++, Go |
| 104 | Maximum Depth of Binary Tree | `tree` | 8 | C++, Go |
| 110 | Balanced Binary Tree | `tree` | 8 | C++, Go |
| 424 | Longest Repeating Character Replacement | `sliding_window` | 5 | C++, Go |
| 438 | Find All Anagrams in a String | `sliding_window` | 4 | C++, Go |
| 567 | Permutation in String | `sliding_window` | 5 | C++, Go |

> Counts reflect entries in `testcases.json`. If you add/modify cases there, re-run `./run -l` to inspect.

### Categories
Current categories: `hash`, `list`, `sliding_window`, `misc`, `two_pointer`, `tree`.

### Adding a new problem (quick checklist)
1. Append its spec & cases to `testcases.json` (unique numeric id, category, description, cases array).
2. Implement solution file(s): place them inside the category folder:
  - C++: `src/cpp/<category>/<id>.<slug>.cpp`
  - Go:  `src/go/<category>/<id>.<slug>.go`
3. Register handler:
  - C++: add to the handler map in `src/cpp/main.cpp`.
  - Go: add to `funcRegistry` in `src/go/main.go` and a switch branch (filtered runner) if required.
4. Build (or just run once and let `./run` auto-build).
5. Execute: `./run <id>` or category / all.
  - Use the flag form: `./run -p <id>` (e.g., `./run -p 94`).
