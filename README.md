# mylc — LeetCode practice (C++, Go & Java)

Central runner + shared test harness. Problems and test data live in **`testcases.json`** and are executed by language-specific drivers.

**Problems covered:** 16  
**Languages:** C++, Go, Java

For complete usage, build, and troubleshooting details, see [USAGE.md](./USAGE.md).

## Quick start
```bash
# (optional) set a default language for the run helper
export LC_LANG=cpp   # or: go | java

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
    java/
      hash/ list/ sliding_window/ misc/ two_pointer/ tree/
        <id>.*.java # per-problem sources grouped by category
      Main.java LcTestUtils.java Makefile
  build/           # build artifacts (created on demand)
```

## Prerequisites
- Linux/WSL/macOS with `make`
- C++20 compiler (`g++` or `clang++`)
- Go 1.21+ (module mode)
- (Optional) `nlohmann/json` single-header; vendored or system-wide
- Java 17+ (OpenJDK recommended). Java support is fully integrated across the solved problems. We use a pinned Gson jar (no Maven/Gradle required).

## Problems & status
Expand a category to view its problems.

<details>
<summary><strong>hash</strong> (1)</summary>

| # | Problem | Diff | Test cases | Languages | Video |
|---:|---|:---:|---:|---|---|
| [1](https://leetcode.com/problems/two-sum/) | Two Sum | Easy | 2 | C++, Go, Java | [link](https://www.youtube.com/watch?v=KLlXCFG5TnA) |

</details>

<details>
<summary><strong>list</strong> (2)</summary>

| # | Problem | Diff | Test cases | Languages | Video |
|---:|---|:---:|---:|---|---|
| [2](https://leetcode.com/problems/add-two-numbers/) | Add Two Numbers | Medium | 1 | C++, Go, Java | [link](https://www.youtube.com/watch?v=wgFPrzTjm7s) |
| [21](https://leetcode.com/problems/merge-two-sorted-lists/) | Merge Two Sorted Lists | Easy | 7 | C++, Go, Java | [link](https://www.youtube.com/watch?v=XIdigk956u0) |

</details>

<details>
<summary><strong>misc</strong> (1)</summary>

| # | Problem | Diff | Test cases | Languages | Video |
|---:|---|:---:|---:|---|---|
| [9](https://leetcode.com/problems/palindrome-number/) | Palindrome Number | Easy | 6 | C++, Go, Java | [link](https://www.youtube.com/watch?v=f5qF2OowB5A) |

</details>

<details>
<summary><strong>sliding_window</strong> (4)</summary>

| # | Problem | Diff | Test cases | Languages | Video |
|---:|---|:---:|---:|---|---|
| [3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Longest Substring Without Repeating Characters | Medium | 2 | C++, Go, Java | [link](https://www.youtube.com/watch?v=wiGpQwVHdE0) |
| [424](https://leetcode.com/problems/longest-repeating-character-replacement/) | Longest Repeating Character Replacement | Medium | 5 | C++, Go, Java | [link](https://www.youtube.com/watch?v=gqXU1UyA8pk) |
| [438](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | Find All Anagrams in a String | Medium | 4 | C++, Go, Java | [link](https://www.youtube.com/watch?v=G8xtZy0fDKg) |
| [567](https://leetcode.com/problems/permutation-in-string/) | Permutation in String | Medium | 5 | C++, Go, Java | [link](https://www.youtube.com/watch?v=UbyhOgBN834) |

</details>

<details>
<summary><strong>stack</strong> (1)</summary>

| # | Problem | Diff | Test cases | Languages | Video |
|---:|---|:---:|---:|---|---|
| [739](https://leetcode.com/problems/daily-temperatures/) | Daily Temperatures | Medium | 6 | C++, Go, Java | [link](https://www.youtube.com/watch?v=cTBiBSnjO3c) |

</details>

<details>
<summary><strong>tree</strong> (7)</summary>

| # | Problem | Diff | Test cases | Languages | Video |
|---:|---|:---:|---:|---|---|
| [94](https://leetcode.com/problems/binary-tree-inorder-traversal/) | Binary Tree Inorder Traversal | Easy | 5 | C++, Go, Java | [link](https://www.youtube.com/watch?v=g_S5WuasWUE) |
| [98](https://leetcode.com/problems/validate-binary-search-tree/) | Validate Binary Search Tree | Medium | 6 | C++, Go, Java | - |
| [100](https://leetcode.com/problems/same-tree/) | Same Tree | Easy | 5 | C++, Go, Java | [link](https://www.youtube.com/watch?v=vRbbcKXCxOw) |
| [102](https://leetcode.com/problems/binary-tree-level-order-traversal/) | Binary Tree Level Order Traversal | Medium | 5 | C++, Go, Java | [link](https://www.youtube.com/watch?v=6ZnyEApgFYg) |
| [103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) | Binary Tree Zigzag Level Order Traversal | Medium | 5 | C++, Go, Java | [link](https://www.youtube.com/watch?v=s6ATEkipzow) |
| [104](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | Maximum Depth of Binary Tree | Easy | 8 | C++, Go, Java | [link](https://www.youtube.com/watch?v=hTM3phVI6YQ) |
| [110](https://leetcode.com/problems/balanced-binary-tree/) | Balanced Binary Tree | Easy | 8 | C++, Go, Java | [link](https://www.youtube.com/watch?v=QfJsau0ItOY) |

</details>

<details>
<summary><strong>two_pointer</strong> (2)</summary>

| # | Problem | Diff | Test cases | Languages | Video |
|---:|---|:---:|---:|---|---|
| [11](https://leetcode.com/problems/container-with-most-water/) | Container With Most Water | Medium | 9 | C++, Go, Java | [link](https://www.youtube.com/watch?v=UuiTKBwPgAo) |
| [42](https://leetcode.com/problems/trapping-rain-water/) | Trapping Rain Water | Hard | 6 | C++, Go, Java | [link](https://www.youtube.com/watch?v=ZI2z5pq0TqA) |

</details>

> Counts reflect entries in `testcases.json`. If you add/modify cases there, re-run `./run -l` to inspect.
### Categories
Current categories: `hash`, `list`, `sliding_window`, `misc`, `two_pointer`, `tree`.

### Adding a new problem (quick checklist)
1. Append its spec & cases to `testcases.json` (unique numeric id, category, description, cases array).
2. Implement solution file(s): place them inside the category folder:
  - C++: `src/cpp/<category>/<id>.<slug>.cpp`
  - Go:  `src/go/<category>/<id>.<slug>.go`
  - Java: `src/java/<category>/<id>.<slug>.java` (class Solution inside @lc markers)
3. Register handler:
  - C++: add to the handler map in `src/cpp/main.cpp`.
  - Go: add to `funcRegistry` in `src/go/main.go` and a switch branch (filtered runner) if required.
  - Java: add to `Registry` in `src/java/LcTestUtils.java` and a driver in `Drivers` for the problem.
4. Build (or just run once and let `./run` auto-build).
5. Execute: `./run <id>` or category / all.
  - Use the flag form: `./run -p <id>` (e.g., `./run -p 94`).
