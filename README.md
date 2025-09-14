# mylc — LeetCode practice (C++ & Go)

Central runner + shared test harness. Problems and test data live in **`testcases.json`** and are executed by language-specific drivers.

**Problems covered:** 13  
**Languages:** C++, Go

## Repository layout
```
./
  env.sh           # optional defaults (sets LC_LANGUAGE if you want)
  run              # helper script: builds runner on demand & executes tests
  testcases.json   # single source of truth for problems & cases
  src/
    cpp/           # C++ solutions + test harness
    go/            # Go solutions + test harness
  build/           # build artifacts (created on demand)
```

## Prerequisites
- **Linux/WSL/macOS** with `make`
- **C++20** compiler (`g++` or `clang++`)
- **Go 1.21+** (module mode)
- (Optional) `nlohmann/json` single-header; vendored or system-wide

---

## Helper script: `run`

The `run` script is the simplest way to execute solutions using the prebuilt (or auto-built) central runners in `build/<lang>/runner`.

### Usage
```bash
./run [options] [problem-id]

Options:
  -l, --lang [cpp|go]  With an argument: set language (default from $LC_LANGUAGE, else cpp)
                       Without an argument: list categories & problems from testcases.json
  -c, --category <cat> Run the given category
  -a, --all            Run all problems (sets LC_PROB_NUM=all)
  -L                   List categories & problems (same as bare -l)
  -h, --help           Show help

Behavior:
  • If build/<lang>/runner is missing, the script auto-builds it via: make -C src/<lang> all
  • For single-problem runs, it validates that the problem exists in testcases.json and
    has an implementation in the selected language before executing.
  • It exports LC_PROB_NUM / LC_CATEGORY for the language runners.
```

### Examples
```bash
# Default language (from LC_LANGUAGE; falls back to cpp)
./run 94

# Force language
./run -l go 94
./run -l cpp 104

# Run a whole category
./run -c sliding_window

# Run everything
./run -a

# List categories & problems (pulled from testcases.json)
./run -l     # or: ./run -L
```

### Environment
```bash
# Set your preferred default language for the run helper
export LC_LANGUAGE=cpp   # or: go
```

---

## Quick start
```bash
# (Optional) set a default language for the run helper
export LC_LANGUAGE=cpp

# Run a single problem (auto-builds the runner on first use)
./run 94

# Run all problems in a category
./run -c tree

# Run all problems
./run -a

# List problems & categories
./run -l
```

---

## How it works
- `testcases.json` holds metadata for each problem:
  - `category` — tag like `tree`, `sliding_window`
  - `description` — short human title
  - `cases` — array of inputs/expected values interpreted by the harness
- Main drivers:
  - **C++:** `src/cpp/main.cpp` reads `testcases.json` and dispatches to per-problem handlers.
  - **Go:**  `src/go/main.go` reads `testcases.json` and dispatches to per-problem handlers.
- Runners live at `build/cpp/runner` and `build/go/runner`. The `run` script ensures they exist (auto-builds if needed) and then executes them with the appropriate environment (single id, category, or all).

---

## Running a problem via `make` (alternative)
You can also build and run through the per-language Makefiles:

```bash
# C++
make -C src/cpp runner
make -C src/cpp run NUM=94
make -C src/cpp run-all

# Go
make -C src/go runner
make -C src/go run NUM=94
make -C src/go run-all
```

---

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
