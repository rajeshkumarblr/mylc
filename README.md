# mylc — LeetCode practice (C++, Go & Java)

Central runner + shared test harness. Problems and test data live in **`testcases.json`** and are executed by language-specific drivers.

**Problems covered:** 29  
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
      binary_search/ dp/ graphs/ hash/ list/ misc/ prefix_sum/ sliding_window/ stack/ tree/ two_pointer/
        <id>.*.cpp  # per-problem sources grouped by category
      main.cpp lc_test_utils.*  Makefile
    go/
      binary_search/ dp/ graphs/ hash/ list/ misc/ prefix_sum/ sliding_window/ stack/ tree/ two_pointer/
        <id>.*.go   # per-problem sources grouped by category
      main.go lc_test_utils.go Makefile
    java/
      binary_search/ dp/ graphs/ hash/ list/ misc/ prefix_sum/ sliding_window/ stack/ tree/ two_pointer/
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

All 29 problems implemented across C++, Go, and Java. Use `./run -l` to list problems, `./run -c <category>` to run by category.

_Click problem ID to view LeetCode problem description. Click ✓ to view source code._

| ID | Problem | Category | Difficulty | Cases | C++ | Go | Java | Video |
|---:|---|---|---|---:|---|---|---|---|
| [1](https://leetcode.com/problems/two-sum/description/) | Two Sum | hash | Easy | 2 | [✓](src/cpp/hash/1.two-sum.cpp) | [✓](src/go/hash/1.two.sum.go) | [✓](src/java/hash/1.two-sum.java) | [📺](https://www.youtube.com/watch?v=KLlXCFG5TnA) |
| [2](https://leetcode.com/problems/add-two-numbers/description/) | Add Two Numbers | list | Medium | 1 | [✓](src/cpp/list/2.add-two-numbers.cpp) | [✓](src/go/list/2.add-two-numbers.go) | [✓](src/java/list/2.add-two-numbers.java) | [📺](https://www.youtube.com/watch?v=wgFPrzTjm7s) |
| [3](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/) | Longest Substring Without Repeating Characters | sliding_window | Medium | 2 | [✓](src/cpp/sliding_window/3.longest-substring-without-repeating-characters.cpp) | [✓](src/go/sliding_window/3.longest-substring-without-repeating-characters.go) | [✓](src/java/sliding_window/3.longest-substring-without-repeating-characters.java) | [📺](https://www.youtube.com/watch?v=wiGpQwVHdE0) |
| [9](https://leetcode.com/problems/palindrome-number/description/) | Palindrome Number | misc | Easy | 6 | [✓](src/cpp/misc/9.palindrome-number.cpp) | [✓](src/go/misc/9.palindrome-number.go) | [✓](src/java/misc/9.palindrome-number.java) | [📺](https://www.youtube.com/watch?v=f5qF2OowB5A) |
| [11](https://leetcode.com/problems/container-with-most-water/description/) | Container With Most Water | two_pointer | Medium | 9 | [✓](src/cpp/two_pointer/11.container-with-most-water.cpp) | [✓](src/go/two_pointer/11.container-with-most-water.go) | [✓](src/java/two_pointer/11.container-with-most-water.java) | [📺](https://www.youtube.com/watch?v=UuiTKBwPgAo) |
| [15](https://leetcode.com/problems/3sum/description/) | 3Sum | two_pointer | Medium | 4 | [✓](src/cpp/two_pointer/15.3-sum.cpp) | [✓](src/go/two_pointer/15.3-sum.go) | [✓](src/java/two_pointer/15.3-sum.java) | - |
| [20](https://leetcode.com/problems/valid-parentheses/description/) | Valid Parentheses | stack | Easy | 10 | [✓](src/cpp/stack/20.valid-parentheses.cpp) | [✓](src/go/stack/20.valid-parentheses.go) | [✓](src/java/stack/20.valid-parentheses.java) | [📺](https://www.youtube.com/watch?v=WTzjTskDFMg) |
| [21](https://leetcode.com/problems/merge-two-sorted-lists/description/) | Merge Two Sorted Lists | list | Easy | 7 | [✓](src/cpp/list/21.merge-two-sorted-lists.cpp) | [✓](src/go/list/21.merge-two-sorted-lists.go) | [✓](src/java/list/21.merge-two-sorted-lists.java) | [📺](https://www.youtube.com/watch?v=XIdigk956u0) |
| [35](https://leetcode.com/problems/search-insert-position/description/) | Search Insert Position | binary_search | Easy | 4 | [✓](src/cpp/binary_search/35.search-insert-position.cpp) | [✓](src/go/binary_search/35.search-insert-position.go) | [✓](src/java/binary_search/35.search-insert-position.java) | - |
| [36](https://leetcode.com/problems/valid-sudoku/description/) | Valid Sudoku | hash | Medium | 2 | [✓](src/cpp/hash/36.valid-sudoku.cpp) | [✓](src/go/hash/36.valid-sudoku.go) | [✓](src/java/hash/36.valid-sudoku.java) | - |
| [42](https://leetcode.com/problems/trapping-rain-water/description/) | Trapping Rain Water | two_pointer | Hard | 6 | [✓](src/cpp/two_pointer/42.trapping-rain-water.cpp) | [✓](src/go/two_pointer/42.trapping-rain-water.go) | [✓](src/java/two_pointer/42.trapping-rain-water.java) | [📺](https://www.youtube.com/watch?v=ZI2z5pq0TqA) |
| [94](https://leetcode.com/problems/binary-tree-inorder-traversal/description/) | Binary Tree Inorder Traversal | tree | Easy | 5 | [✓](src/cpp/tree/94.binary-tree-inorder-traversal.cpp) | [✓](src/go/tree/94.binary-tree-inorder-traversal.go) | [✓](src/java/tree/94.binary-tree-inorder-traversal.java) | [📺](https://www.youtube.com/watch?v=g_S5WuasWUE) |
| [98](https://leetcode.com/problems/validate-binary-search-tree/description/) | Validate Binary Search Tree | tree | Medium | 6 | [✓](src/cpp/tree/98.validate-binary-search-tree.cpp) | [✓](src/go/tree/98.validate-binary-search-tree.go) | [✓](src/java/tree/98.validate-binary-search-tree.java) | - |
| [100](https://leetcode.com/problems/same-tree/description/) | Same Tree | tree | Easy | 5 | [✓](src/cpp/tree/100.same-tree.cpp) | [✓](src/go/tree/100.same-tree.go) | [✓](src/java/tree/100.same-tree.java) | [📺](https://www.youtube.com/watch?v=vRbbcKXCxOw) |
| [102](https://leetcode.com/problems/binary-tree-level-order-traversal/description/) | Binary Tree Level Order Traversal | tree | Medium | 5 | [✓](src/cpp/tree/102.binary-tree-level-order-traversal.cpp) | [✓](src/go/tree/102.binary-tree-level-order-traversal.go) | [✓](src/java/tree/102.binary-tree-level-order-traversal.java) | [📺](https://www.youtube.com/watch?v=6ZnyEApgFYg) |
| [103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/) | Binary Tree Zigzag Level Order Traversal | tree | Medium | 5 | [✓](src/cpp/tree/103.binary-tree-zigzag-level-order-traversal.cpp) | [✓](src/go/tree/103.binary-tree-zigzag-level-order-traversal.go) | [✓](src/java/tree/103.binary-tree-zigzag-level-order-traversal.java) | [📺](https://www.youtube.com/watch?v=s6ATEkipzow) |
| [104](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/) | Maximum Depth of Binary Tree | tree | Easy | 8 | [✓](src/cpp/tree/104.maximum-depth-of-binary-tree.cpp) | [✓](src/go/tree/104.maximum-depth-of-binary-tree.go) | [✓](src/java/tree/104.maximum-depth-of-binary-tree.java) | [📺](https://www.youtube.com/watch?v=hTM3phVI6YQ) |
| [110](https://leetcode.com/problems/balanced-binary-tree/description/) | Balanced Binary Tree | tree | Easy | 8 | [✓](src/cpp/tree/110.balanced-binary-tree.cpp) | [✓](src/go/tree/110.balanced-binary-tree.go) | [✓](src/java/tree/110.balanced-binary-tree.java) | [📺](https://www.youtube.com/watch?v=QfJsau0ItOY) |
| [139](https://leetcode.com/problems/word-break/description/) | Word Break | dp | Medium | 4 | [✓](src/cpp/dp/139.word-break.cpp) | [✓](src/go/dp/139.word-break.go) | [✓](src/java/dp/P139.java) | [📺](https://www.youtube.com/watch?v=Sx9NNgInc3A) |
| [160](https://leetcode.com/problems/intersection-of-two-linked-lists/description/) | Intersection of Two Linked Lists | list | Easy | 3 | [✓](src/cpp/list/160.intersection-of-two-linked-lists.cpp) | [✓](src/go/list/160.intersection-of-two-linked-lists.go) | [✓](src/java/list/160.intersection-of-two-linked-lists.java) | - |
| [200](https://leetcode.com/problems/number-of-islands/description/) | Number of Islands | graphs | Medium | 2 | [✓](src/cpp/graphs/200.number-of-islands.cpp) | [✓](src/go/graphs/200.number-of-islands.go) | [✓](src/java/graphs/200.number-of-islands.java) | - |
| [206](https://leetcode.com/problems/reverse-linked-list/description/) | Reverse Linked List | list | Easy | 3 | [✓](src/cpp/list/206.reverse-linked-list.cpp) | [✓](src/go/list/206.reverse-linked-list.go) | [✓](src/java/list/206.reverse-linked-list.java) | - |
| [226](https://leetcode.com/problems/invert-binary-tree/description/) | Invert Binary Tree | tree | Easy | 3 | [✓](src/cpp/tree/226.invert-binary-tree.cpp) | [✓](src/go/tree/226.invert-binary-tree.go) | [✓](src/java/tree/226.invert-binary-tree.java) | - |
| [238](https://leetcode.com/problems/product-of-array-except-self/description/) | Product of Array Except Self | prefix_sum | Medium | 2 | [✓](src/cpp/prefix_sum/238.product-of-array-except-self.cpp) | [✓](src/go/prefix_sum/238.product-of-array-except-self.go) | [✓](src/java/prefix_sum/238.product-of-array-except-self.java) | - |
| [424](https://leetcode.com/problems/longest-repeating-character-replacement/description/) | Longest Repeating Character Replacement | sliding_window | Medium | 5 | [✓](src/cpp/sliding_window/424.longest-repeating-character-replacement.cpp) | [✓](src/go/sliding_window/424.longest-repeating-character-replacement.go) | [✓](src/java/sliding_window/424.longest-repeating-character-replacement.java) | [📺](https://www.youtube.com/watch?v=gqXU1UyA8pk) |
| [438](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/) | Find All Anagrams in a String | sliding_window | Medium | 4 | [✓](src/cpp/sliding_window/438.find-all-anagrams-in-a-string.cpp) | [✓](src/go/sliding_window/438.find-all-anagrams-in-a-string.go) | [✓](src/java/sliding_window/438.find-all-anagrams-in-a-string.java) | [📺](https://www.youtube.com/watch?v=G8xtZy0fDKg) |
| [560](https://leetcode.com/problems/subarray-sum-equals-k/description/) | Subarray Sum Equals K | prefix_sum | Medium | 2 | [✓](src/cpp/prefix_sum/560.subarray-sum-equals-k.cpp) | [✓](src/go/prefix_sum/560.subarray-sum-equals-k.go) | [✓](src/java/prefix_sum/560.subarray-sum-equals-k.java) | - |
| [567](https://leetcode.com/problems/permutation-in-string/description/) | Permutation in String | sliding_window | Medium | 5 | [✓](src/cpp/sliding_window/567.permutation-in-string.cpp) | [✓](src/go/sliding_window/567.permutation-in-string.go) | [✓](src/java/sliding_window/567.permutation-in-string.java) | [📺](https://www.youtube.com/watch?v=UbyhOgBN834) |
| [739](https://leetcode.com/problems/daily-temperatures/description/) | Daily Temperatures | stack | Medium | 6 | [✓](src/cpp/stack/739.daily-temperatures.cpp) | [✓](src/go/stack/739.daily-temperatures.go) | [✓](src/java/stack/739.daily-temperatures.java) | [📺](https://www.youtube.com/watch?v=cTBiBSnjO3c) |

### Filter by Category
- **binary_search**: [35](#35)
- **dp**: [139](#139)
- **graphs**: [200](#200)
- **hash**: [1](#1), [36](#36)
- **list**: [2](#2), [21](#21), [160](#160), [206](#206)
- **misc**: [9](#9)
- **prefix_sum**: [238](#238), [560](#560)
- **sliding_window**: [3](#3), [424](#424), [438](#438), [567](#567)
- **stack**: [20](#20), [739](#739)
- **tree**: [94](#94), [98](#98), [100](#100), [102](#102), [103](#103), [104](#104), [110](#110), [226](#226)
- **two_pointer**: [11](#11), [15](#15), [42](#42)

> Use `./run -c <category>` to test problems by category. Problem counts reflect `testcases.json` entries.
### Categories
Current categories: `binary_search`, `dp`, `graphs`, `hash`, `list`, `misc`, `prefix_sum`, `sliding_window`, `stack`, `tree`, `two_pointer`.

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
