# mylc — LeetCode practice (C++ & Go)

Central runner + shared test harness. Problems and test data live in **`testcases.json`** and are executed by language-specific drivers.

**Problems covered:** 16  
**Languages:** C++, Go

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
- **Linux/WSL/macOS** with `make`
- **C++20** compiler (`g++` or `clang++`)
- **Go 1.21+** (module mode)
- (Optional) `nlohmann/json` single-header; vendored or system-wide

### Configuration (.env)
- The `run` script will source `.env` from the repo root if present, and fall back to `env.sh` for backward compatibility.
- Put non-secret defaults in `.env` (kept out of git via `.gitignore`). Example:

```
# .env (example)
LC_LANG=cpp       # default language for ./run (cpp|go)
# LC_PROB_NUM=all  # optional: run-all by default
# LC_CATEGORY=tree # optional: default category
# LC_VERBOSE=1     # optional: future per-test verbosity
```

---

## Helper script: `run`

The `run` script is the simplest way to execute solutions using the prebuilt (or auto-built) central runners in `build/<lang>/runner`.

### Usage
```bash
./run [options] [problem-id]

Options:
  -l, --lang [cpp|go]  With an argument: set language (default from $LC_LANG via .env, else cpp)
                       Without an argument: list categories & problems
  -c, --category <cat> Run the given category
  -a, --all            Run all problems (sets LC_PROB_NUM=all)
  -L                   List categories & problems (same as bare -l)
  -h, --help           Show help
  -s, --submit <id>    Extract and submit via vsc-leetcode-cli (lang from -l or $LC_LANG)

Behavior:
  • If build/<lang>/runner is missing, the script auto-builds it via: make -C src/<lang> all
  • For single-problem runs, it validates that the problem exists in testcases.json and
    has an implementation in the selected language before executing.
  • It exports LC_PROB_NUM / LC_CATEGORY for the language runners.
```

### Examples
```bash
# Default language (from LC_LANG; falls back to cpp)
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

# Extract a submission snippet (writes to build/<lang>/submit.<id>.<ext>)
./run -s 9 -l cpp
./run --submit 21 -l go
```

### Environment variables
These are consumed by the runners (the `run` helper exports them for you):

| Variable | Purpose | Typical values / notes |
|----------|---------|------------------------|
| `LC_PROB_NUM` | Single problem id to run, or `all` | e.g. `94`, `102`, `all` |
| `LC_CATEGORY` | Category filter (mutually exclusive with single id) | e.g. `tree`, `sliding_window` |
| `LC_LANG` | Default language for the `run` script | `cpp` (default) or `go` |
| `LC_VERBOSE` | (Planned / partial) Force verbose per‑test output in single‑problem mode | `1` |

Set a default language (optional):
```bash
export LC_LANG=cpp   # or: go
```

---

## Quick start
```bash
# (Optional) set a default language for the run helper
export LC_LANG=cpp

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

## Development workflow
- After changes to `run`, Makefiles, or the harness, use the smoke test script to validate everything quickly:

```
./test.sh
```

It will clean-build C++ and Go runners, list problems, and run representative scenarios (all, category, and single) for both languages. Submit tests are skipped unless you set `TEST_SUBMIT=1` and have `vsc-leetcode-cli` installed and logged in.

---

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
