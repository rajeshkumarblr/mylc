# mylc — LeetCode practice (C++, Go & Java)

Central runner + shared test harness. Problems and test data live in **`testcases.json`** and are executed by language-specific drivers.

**Problems covered:** 47  
**Languages:** C++, Go, Java, Python  
**Status:** C++ ✅ 37/47 • Go ✅ 35/47 • Java ✅ 47/47 • Python ⚠️ 34/47

For complete usage, build, and troubleshooting details, see [USAGE.md](./USAGE.md).

## Quick start
```bash
# (optional) set a default language for the run helper
export LC_LANG=cpp   # or: go | java | python

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
    python/
      binary_search/ dp/ graphs/ hash/ list/ misc/ prefix_sum/ sliding_window/ stack/ tree/ two_pointer/
        <id>.*.py   # per-problem sources grouped by category
      main.py lc_test_utils.py Makefile
  build/           # build artifacts (created on demand)
```

## Prerequisites
- Linux/WSL/macOS with `make`
- C++20 compiler (`g++` or `clang++`)
- Go 1.21+ (module mode)
- (Optional) `nlohmann/json` single-header; vendored or system-wide
- Java 17+ (OpenJDK recommended). We use a pinned Gson jar (no Maven/Gradle required).
- Python 3.6+

## Problems & status

**All Languages:** All 33 problems fully implemented and tested ✅  

Use `./run -l` to list problems, `./run -c <category>` to run by category.

_Click problem ID to view LeetCode problem description (opens in new tab). Click ✓ to view source code. Click 📺 for NeetCode explanation videos._

| ID | Problem | Category | Difficulty | Test Cases | C++ | Go | Java | Python | NeetCode Explanation Video |
|---:|---|---|---|---:|---|---|---|---|---|
| <a href="https://leetcode.com/problems/two-sum/description/" target="_blank">1</a> | Two Sum | hash | Easy | 2 | [✓](src/cpp/hash/1.two-sum.cpp) | [✓](src/go/hash/1.two.sum.go) | [✓](src/java/hash/1.two-sum.java) | [📺](https://www.youtube.com/watch?v=KLlXCFG5TnA) |
| <a href="https://leetcode.com/problems/add-two-numbers/description/" target="_blank">2</a> | Add Two Numbers | list | Medium | 1 | [✓](src/cpp/list/2.add-two-numbers.cpp) | [✓](src/go/list/2.add-two-numbers.go) | [✓](src/java/list/2.add-two-numbers.java) | [📺](https://www.youtube.com/watch?v=wgFPrzTjm7s) |
| <a href="https://leetcode.com/problems/longest-substring-without-repeating-characters/description/" target="_blank">3</a> | Longest Substring Without Repeating Characters | sliding_window | Medium | 2 | [✓](src/cpp/sliding_window/3.longest-substring-without-repeating-characters.cpp) | [✓](src/go/sliding_window/3.longest-substring-without-repeating-characters.go) | [✓](src/java/sliding_window/3.longest-substring-without-repeating-characters.java) | [📺](https://www.youtube.com/watch?v=wiGpQwVHdE0) |
| <a href="https://leetcode.com/problems/palindrome-number/description/" target="_blank">9</a> | Palindrome Number | misc | Easy | 6 | [✓](src/cpp/misc/9.palindrome-number.cpp) | [✓](src/go/misc/9.palindrome-number.go) | [✓](src/java/misc/9.palindrome-number.java) | [📺](https://www.youtube.com/watch?v=f5qF2OowB5A) |
| <a href="https://leetcode.com/problems/container-with-most-water/description/" target="_blank">11</a> | Container With Most Water | two_pointer | Medium | 9 | [✓](src/cpp/two_pointer/11.container-with-most-water.cpp) | [✓](src/go/two_pointer/11.container-with-most-water.go) | [✓](src/java/two_pointer/11.container-with-most-water.java) | [📺](https://www.youtube.com/watch?v=UuiTKBwPgAo) |
| <a href="https://leetcode.com/problems/roman-to-integer/description/" target="_blank">13</a> | Roman to Integer | misc | Easy | 3 | | | [✓](src/java/misc/P13.java) | |
| <a href="https://leetcode.com/problems/3sum/description/" target="_blank">15</a> | 3Sum | two_pointer | Medium | 4 | [✓](src/cpp/two_pointer/15.3-sum.cpp) | [✓](src/go/two_pointer/15.3-sum.go) | [✓](src/java/two_pointer/15.3-sum.java) | [📺](https://www.youtube.com/watch?v=jzZsG8n2R9A) |
| <a href="https://leetcode.com/problems/valid-parentheses/description/" target="_blank">20</a> | Valid Parentheses | stack | Easy | 10 | [✓](src/cpp/stack/20.valid-parentheses.cpp) | [✓](src/go/stack/20.valid-parentheses.go) | [✓](src/java/stack/20.valid-parentheses.java) | [📺](https://www.youtube.com/watch?v=WTzjTskDFMg) |
| <a href="https://leetcode.com/problems/merge-two-sorted-lists/description/" target="_blank">21</a> | Merge Two Sorted Lists | list | Easy | 7 | [✓](src/cpp/list/21.merge-two-sorted-lists.cpp) | [✓](src/go/list/21.merge-two-sorted-lists.go) | [✓](src/java/list/21.merge-two-sorted-lists.java) | [📺](https://www.youtube.com/watch?v=XIdigk956u0) |
| <a href="https://leetcode.com/problems/search-in-rotated-sorted-array/description/" target="_blank">33</a> | Search in Rotated Sorted Array | binary_search | Medium | 3 | [✓](src/cpp/binary_search/33.search-in-rotated-sorted-array.cpp) | [✓](src/go/binary_search/33.search-in-rotated-sorted-array.go) | [✓](src/java/binary_search/33.search-in-rotated-sorted-array.java) | [📺](https://www.youtube.com/watch?v=U8XENwh8Oy8) |
| <a href="https://leetcode.com/problems/search-insert-position/description/" target="_blank">35</a> | Search Insert Position | binary_search | Easy | 4 | [✓](src/cpp/binary_search/35.search-insert-position.cpp) | [✓](src/go/binary_search/35.search-insert-position.go) | [✓](src/java/binary_search/35.search-insert-position.java) | [📺](https://www.youtube.com/watch?v=K-RYzDZkzCI) |
| <a href="https://leetcode.com/problems/valid-sudoku/description/" target="_blank">36</a> | Valid Sudoku | hash | Medium | 2 | [✓](src/cpp/hash/36.valid-sudoku.cpp) | [✓](src/go/hash/36.valid-sudoku.go) | [✓](src/java/hash/36.valid-sudoku.java) | [📺](https://www.youtube.com/watch?v=TjFXEUCMqI8) |
| <a href="https://leetcode.com/problems/trapping-rain-water/description/" target="_blank">42</a> | Trapping Rain Water | two_pointer | Hard | 6 | [✓](src/cpp/two_pointer/42.trapping-rain-water.cpp) | [✓](src/go/two_pointer/42.trapping-rain-water.go) | [✓](src/java/two_pointer/42.trapping-rain-water.java) | [📺](https://www.youtube.com/watch?v=ZI2z5pq0TqA) |
| <a href="https://leetcode.com/problems/climbing-stairs/description/" target="_blank">70</a> | Climbing Stairs | dp | Easy | 7 | [✓](src/cpp/dp/70.climbing-stairs.cpp) | [✓](src/go/dp/70.climbing-stairs.go) | [✓](src/java/dp/P70.java) | [📺](https://www.youtube.com/watch?v=Y0lT9Fck7qI) |
| <a href="https://leetcode.com/problems/minimum-window-substring/description/" target="_blank">76</a> | Minimum Window Substring | sliding_window | Hard | 3 | [✓](src/cpp/sliding_window/76.minimum-window-substring.cpp) | | [✓](src/java/sliding_window/P76.java) | |
| <a href="https://leetcode.com/problems/binary-tree-inorder-traversal/description/" target="_blank">94</a> | Binary Tree Inorder Traversal | tree | Easy | 5 | [✓](src/cpp/tree/94.binary-tree-inorder-traversal.cpp) | [✓](src/go/tree/94.binary-tree-inorder-traversal.go) | [✓](src/java/tree/94.binary-tree-inorder-traversal.java) | [📺](https://www.youtube.com/watch?v=g_S5WuasWUE) |
| <a href="https://leetcode.com/problems/validate-binary-search-tree/description/" target="_blank">98</a> | Validate Binary Search Tree | tree | Medium | 6 | [✓](src/cpp/tree/98.validate-binary-search-tree.cpp) | [✓](src/go/tree/98.validate-binary-search-tree.go) | [✓](src/java/tree/98.validate-binary-search-tree.java) | [📺](https://www.youtube.com/watch?v=s6ATEkipzow) |
| <a href="https://leetcode.com/problems/same-tree/description/" target="_blank">100</a> | Same Tree | tree | Easy | 5 | [✓](src/cpp/tree/100.same-tree.cpp) | [✓](src/go/tree/100.same-tree.go) | [✓](src/java/tree/100.same-tree.java) | [📺](https://www.youtube.com/watch?v=vRbbcKXCxOw) |
| <a href="https://leetcode.com/problems/binary-tree-level-order-traversal/description/" target="_blank">102</a> | Binary Tree Level Order Traversal | tree | Medium | 5 | [✓](src/cpp/tree/102.binary-tree-level-order-traversal.cpp) | [✓](src/go/tree/102.binary-tree-level-order-traversal.go) | [✓](src/java/tree/102.binary-tree-level-order-traversal.java) | [📺](https://www.youtube.com/watch?v=6ZnyEApgFYg) |
| <a href="https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/" target="_blank">103</a> | Binary Tree Zigzag Level Order Traversal | tree | Medium | 5 | [✓](src/cpp/tree/103.binary-tree-zigzag-level-order-traversal.cpp) | [✓](src/go/tree/103.binary-tree-zigzag-level-order-traversal.go) | [✓](src/java/tree/103.binary-tree-zigzag-level-order-traversal.java) | [📺](https://www.youtube.com/watch?v=s6ATEkipzow) |
| <a href="https://leetcode.com/problems/maximum-depth-of-binary-tree/description/" target="_blank">104</a> | Maximum Depth of Binary Tree | tree | Easy | 8 | [✓](src/cpp/tree/104.maximum-depth-of-binary-tree.cpp) | [✓](src/go/tree/104.maximum-depth-of-binary-tree.go) | [✓](src/java/tree/104.maximum-depth-of-binary-tree.java) | [📺](https://www.youtube.com/watch?v=hTM3phVI6YQ) |
| <a href="https://leetcode.com/problems/balanced-binary-tree/description/" target="_blank">110</a> | Balanced Binary Tree | tree | Easy | 8 | [✓](src/cpp/tree/110.balanced-binary-tree.cpp) | [✓](src/go/tree/110.balanced-binary-tree.go) | [✓](src/java/tree/110.balanced-binary-tree.java) | [📺](https://www.youtube.com/watch?v=QfJsau0ItOY) |
| <a href="https://leetcode.com/problems/word-break/description/" target="_blank">139</a> | Word Break | dp | Medium | 4 | [✓](src/cpp/dp/139.word-break.cpp) | [✓](src/go/dp/139.word-break.go) | [✓](src/java/dp/P139.java) | [📺](https://www.youtube.com/watch?v=Sx9NNgInc3A) |
| <a href="https://leetcode.com/problems/intersection-of-two-linked-lists/description/" target="_blank">160</a> | Intersection of Two Linked Lists | list | Easy | 4 | [✓](src/cpp/list/160.intersection-of-two-linked-lists.cpp) | [✓](src/go/list/160.intersection-of-two-linked-lists.go) | [✓](src/java/list/160.intersection-of-two-linked-lists.java) | [📺](https://www.youtube.com/watch?v=D0X0BONOQhI) |
| <a href="https://leetcode.com/problems/house-robber/description/" target="_blank">198</a> | House Robber | dp | Medium | 8 | [✓](src/cpp/dp/198.house-robber.cpp) | [✓](src/go/dp/198.house-robber.go) | [✓](src/java/dp/198.house-robber.java) | [📺](https://www.youtube.com/watch?v=73r3KWiEvyk) |
| <a href="https://leetcode.com/problems/number-of-islands/description/" target="_blank">200</a> | Number of Islands | graphs | Medium | 3 | [✓](src/cpp/graphs/200.number-of-islands.cpp) | [✓](src/go/graphs/200.number-of-islands.go) | [✓](src/java/graphs/200.number-of-islands.java) | [📺](https://www.youtube.com/watch?v=pV2kpPD66nE) |
| <a href="https://leetcode.com/problems/reverse-linked-list/description/" target="_blank">206</a> | Reverse Linked List | list | Easy | 3 | [✓](src/cpp/list/206.reverse-linked-list.cpp) | [✓](src/go/list/206.reverse-linked-list.go) | [✓](src/java/list/206.reverse-linked-list.java) | [📺](https://www.youtube.com/watch?v=G0_I-ZF0S38) |
| <a href="https://leetcode.com/problems/house-robber-ii/description/" target="_blank">213</a> | House Robber II | dp | Medium | 7 | [✓](src/cpp/dp/213.house-robber-ii.cpp) | [✓](src/go/dp/213.house-robber-ii.go) | [✓](src/java/dp/P213.java) | [📺](https://www.youtube.com/watch?v=rWAJCfYYOvM) |
| <a href="https://leetcode.com/problems/invert-binary-tree/description/" target="_blank">226</a> | Invert Binary Tree | tree | Easy | 3 | [✓](src/cpp/tree/226.invert-binary-tree.cpp) | [✓](src/go/tree/226.invert-binary-tree.go) | [✓](src/java/tree/226.invert-binary-tree.java) | [📺](https://www.youtube.com/watch?v=OnSn2XEQ4MY) |
| <a href="https://leetcode.com/problems/product-of-array-except-self/description/" target="_blank">238</a> | Product of Array Except Self | prefix_sum | Medium | 2 | [✓](src/cpp/prefix_sum/238.product-of-array-except-self.cpp) | [✓](src/go/prefix_sum/238.product-of-array-except-self.go) | [✓](src/java/prefix_sum/238.product-of-array-except-self.java) | [📺](https://www.youtube.com/watch?v=bNvIQI2wAjk) |
| <a href="https://leetcode.com/problems/longest-repeating-character-replacement/description/" target="_blank">424</a> | Longest Repeating Character Replacement | sliding_window | Medium | 5 | [✓](src/cpp/sliding_window/424.longest-repeating-character-replacement.cpp) | [✓](src/go/sliding_window/424.longest-repeating-character-replacement.go) | [✓](src/java/sliding_window/424.longest-repeating-character-replacement.java) | [📺](https://www.youtube.com/watch?v=gqXU1UyA8pk) |
| <a href="https://leetcode.com/problems/find-all-anagrams-in-a-string/description/" target="_blank">438</a> | Find All Anagrams in a String | sliding_window | Medium | 4 | [✓](src/cpp/sliding_window/438.find-all-anagrams-in-a-string.cpp) | [✓](src/go/sliding_window/438.find-all-anagrams-in-a-string.go) | [✓](src/java/sliding_window/438.find-all-anagrams-in-a-string.java) | [📺](https://www.youtube.com/watch?v=G8xtZy0fDKg) |
| <a href="https://leetcode.com/problems/subarray-sum-equals-k/description/" target="_blank">560</a> | Subarray Sum Equals K | prefix_sum | Medium | 2 | [✓](src/cpp/prefix_sum/560.subarray-sum-equals-k.cpp) | [✓](src/go/prefix_sum/560.subarray-sum-equals-k.go) | [✓](src/java/prefix_sum/560.subarray-sum-equals-k.java) | [📺](https://www.youtube.com/watch?v=HbbYPQc-Oo4) |
| <a href="https://leetcode.com/problems/permutation-in-string/description/" target="_blank">567</a> | Permutation in String | sliding_window | Medium | 5 | [✓](src/cpp/sliding_window/567.permutation-in-string.cpp) | [✓](src/go/sliding_window/567.permutation-in-string.go) | [✓](src/java/sliding_window/567.permutation-in-string.java) | [📺](https://www.youtube.com/watch?v=UbyhOgBN834) |
| <a href="https://leetcode.com/problems/daily-temperatures/description/" target="_blank">739</a> | Daily Temperatures | stack | Medium | 6 | [✓](src/cpp/stack/739.daily-temperatures.cpp) | [✓](src/go/stack/739.daily-temperatures.go) | [✓](src/java/stack/739.daily-temperatures.java) | [📺](https://www.youtube.com/watch?v=cTBiBSnjO3c) |
| <a href="https://leetcode.com/problems/top-k-frequent-elements/description/" target="_blank">347</a> | Top K Frequent Elements | hash | Medium | 3 | [✓](src/cpp/hash/347.top-k-frequent-elements.cpp) | | [✓](src/java/hash/P347.java) | [📺](https://www.youtube.com/watch?v=YPTqKIgVk-k) |
| <a href="https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/" target="_blank">1235</a> | Maximum Profit in Job Scheduling | dp | Hard | 4 | [✓](src/cpp/dp/1235.maximum-profit-in-job-scheduling.cpp) | [✓](src/go/dp/1235.maximum-profit-in-job-scheduling.go) | [✓](src/java/dp/P1235.java) | [📺](https://www.youtube.com/watch?v=JLoWc3v0SiE) |

### Filter by Category
- **binary_search**: [33](#33), [35](#35)
- **dp**: [70](#70), [139](#139), [198](#198), [213](#213), [1235](#1235)
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

---

## 📋 Problem Details

_Click to expand individual problem descriptions, examples, and test cases._

<details>
<summary><strong>LC1: Two Sum</strong> (Easy) - hash</summary>

**🔗 Problem Link**: https://leetcode.com/problems/two-sum/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=KLlXCFG5TnA

**💻 Solutions**:
- [C++](src/cpp/hash/1.two-sum.cpp)
- [Go](src/go/hash/1.two.sum.go)
- [Java](src/java/hash/1.two-sum.java)
- [Python](src/python/hash/1.two-sum.py)

**🧪 Test Cases** (2 cases):
1. `{"input": [2, 7, 11, 15], "target": 9, "expected": [0, 1]}`
2. `{"input": [3, 2, 4], "target": 6, "expected": [1, 2]}`

</details>

<details>
<summary><strong>LC2: Add Two Numbers</strong> (Medium) - list</summary>

**🔗 Problem Link**: https://leetcode.com/problems/add-two-numbers/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=wgFPrzTjm7s

**💻 Solutions**:
- [C++](src/cpp/list/2.add-two-numbers.cpp)
- [Go](src/go/list/2.add-two-numbers.go)
- [Java](src/java/list/2.add-two-numbers.java)
- [Python]()

**🧪 Test Cases** (1 cases):
1. `{"l1": [2, 4, 3], "l2": [5, 6, 4], "expected": [7, 0, 8]}`

</details>

<details>
<summary><strong>LC3: Longest Substring Without Repeating Characters</strong> (Medium) - sliding_window</summary>

**🔗 Problem Link**: https://leetcode.com/problems/longest-substring-without-repeating-characters/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=wiGpQwVHdE0

**💻 Solutions**:
- [C++](src/cpp/sliding_window/3.longest-substring-without-repeating-characters.cpp)
- [Go](src/go/sliding_window/3.longest-substring-without-repeating-characters.go)
- [Java](src/java/sliding_window/3.longest-substring-without-repeating-characters.java)

**🧪 Test Cases** (2 cases):
1. `{"input": "abcabcbb", "expected": 3}`
2. `{"input": "bbbbb", "expected": 1}`

</details>

<details>
<summary><strong>LC9: Palindrome Number</strong> (Easy) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/palindrome-number/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=f5qF2OowB5A

**💻 Solutions**:
- [C++](src/cpp/misc/9.palindrome-number.cpp)
- [Go](src/go/misc/9.palindrome-number.go)
- [Java](src/java/misc/9.palindrome-number.java)

**🧪 Test Cases** (6 cases):
1. `{"input": 121, "expected": True}`
2. `{"input": -121, "expected": False}`
3. `{"input": 10, "expected": False}`
   ... and 3 more cases

</details>

<details>
<summary><strong>LC11: Container With Most Water</strong> (Medium) - two_pointer</summary>

**🔗 Problem Link**: https://leetcode.com/problems/container-with-most-water/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=UuiTKBwPgAo

**💻 Solutions**:
- [C++](src/cpp/two_pointer/11.container-with-most-water.cpp)
- [Go](src/go/two_pointer/11.container-with-most-water.go)
- [Java](src/java/two_pointer/11.container-with-most-water.java)

**🧪 Test Cases** (9 cases):
1. `{"input": [8, 7, 2, 2], "expected": 7}`
2. `{"input": [1, 8, 6, 2, 5, 4, 8, 3, 7], "expected": 49}`
3. `{"input": [1, 1], "expected": 1}`
   ... and 6 more cases

</details>

<details>
<summary><strong>LC15: 3Sum</strong> (Medium) - two_pointer</summary>

**🔗 Problem Link**: https://leetcode.com/problems/3sum/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=jzZsG8n2R9A

**💻 Solutions**:
- [C++](src/cpp/two_pointer/15.3-sum.cpp)
- [Go](src/go/two_pointer/15.3-sum.go)
- [Java](src/java/two_pointer/15.3-sum.java)

**🧪 Test Cases** (4 cases):
1. `{"nums": [-1, 0, 1, 2, -1, -4], "expected": [[-1, -1, 2], [-1, 0, 1]]}`
2. `{"nums": [0, 1, 1], "expected": []}`
3. `{"nums": [0, 0, 0], "expected": [[0, 0, 0]]}`
   ... and 1 more cases

</details>

<details>
<summary><strong>LC20: Valid Parentheses</strong> (Easy) - stack</summary>

**🔗 Problem Link**: https://leetcode.com/problems/valid-parentheses/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=WTzjTskDFMg

**💻 Solutions**:
- [C++](src/cpp/stack/20.valid-parentheses.cpp)
- [Go](src/go/stack/20.valid-parentheses.go)
- [Java](src/java/stack/20.valid-parentheses.java)

**🧪 Test Cases** (10 cases):
1. `{"input": "()", "expected": True}`
2. `{"input": "()[]{}", "expected": True}`
3. `{"input": "(]", "expected": False}`
   ... and 7 more cases

</details>

<details>
<summary><strong>LC21: Merge Two Sorted Lists</strong> (Easy) - list</summary>

**🔗 Problem Link**: https://leetcode.com/problems/merge-two-sorted-lists/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=XIdigk956u0

**💻 Solutions**:
- [C++](src/cpp/list/21.merge-two-sorted-lists.cpp)
- [Go](src/go/list/21.merge-two-sorted-lists.go)
- [Java](src/java/list/21.merge-two-sorted-lists.java)

**🧪 Test Cases** (7 cases):
1. `{"l1": [1, 2, 4], "l2": [1, 3, 4], "expected": [1, 1, 2, 3, 4, 4]}`
2. `{"l1": [], "l2": [], "expected": []}`
3. `{"l1": [], "l2": [0], "expected": [0]}`
   ... and 4 more cases

</details>

<details>
<summary><strong>LC33: Search in Rotated Sorted Array</strong> (Medium) - binary_search</summary>

**🔗 Problem Link**: https://leetcode.com/problems/search-in-rotated-sorted-array/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=U8XENwh8Oy8

**💻 Solutions**:
- [C++](src/cpp/binary_search/33.search-in-rotated-sorted-array.cpp)
- [Go](src/go/binary_search/33.search-in-rotated-sorted-array.go)
- [Java](src/java/binary_search/33.search-in-rotated-sorted-array.java)

**🧪 Test Cases** (3 cases):
1. `{"nums": [4, 5, 6, 7, 0, 1, 2], "target": 0, "expected": 4}`
2. `{"nums": [4, 5, 6, 7, 0, 1, 2], "target": 3, "expected": -1}`
3. `{"nums": [1], "target": 0, "expected": -1}`

</details>

<details>
<summary><strong>LC35: Search Insert Position</strong> (Easy) - binary_search</summary>

**🔗 Problem Link**: https://leetcode.com/problems/search-insert-position/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=K-RYzDZkzCI

**💻 Solutions**:
- [C++](src/cpp/binary_search/35.search-insert-position.cpp)
- [Go](src/go/binary_search/35.search-insert-position.go)
- [Java](src/java/binary_search/35.search-insert-position.java)

**🧪 Test Cases** (4 cases):
1. `{"nums": [1, 3, 5, 6], "target": 5, "expected": 2}`
2. `{"nums": [1, 3, 5, 6], "target": 2, "expected": 1}`
3. `{"nums": [1, 3, 5, 6], "target": 7, "expected": 4}`
   ... and 1 more cases

</details>

<details>
<summary><strong>LC36: Valid Sudoku</strong> (Medium) - hash</summary>

**🔗 Problem Link**: https://leetcode.com/problems/valid-sudoku/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=TjFXEUCMqI8

**💻 Solutions**:
- [C++](src/cpp/hash/36.valid-sudoku.cpp)
- [Go](src/go/hash/36.valid-sudoku.go)
- [Java](src/java/hash/36.valid-sudoku.java)

**🧪 Test Cases** (2 cases):
1. `{"board": [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "...`
2. `{"board": [["8", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "...`

</details>

<details>
<summary><strong>LC42: Trapping Rain Water</strong> (Hard) - two_pointer</summary>

**🔗 Problem Link**: https://leetcode.com/problems/trapping-rain-water/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=ZI2z5pq0TqA

**💻 Solutions**:
- [C++](src/cpp/two_pointer/42.trapping-rain-water.cpp)
- [Go](src/go/two_pointer/42.trapping-rain-water.go)
- [Java](src/java/two_pointer/42.trapping-rain-water.java)

**🧪 Test Cases** (6 cases):
1. `{"input": [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], "expected": 6}`
2. `{"input": [4, 2, 0, 3, 2, 5], "expected": 9}`
3. `{"input": [1, 2, 3, 4, 5], "expected": 0}`
   ... and 3 more cases

</details>

<details>
<summary><strong>LC70: Climbing Stairs</strong> (Easy) - dp</summary>

**🔗 Problem Link**: https://leetcode.com/problems/climbing-stairs/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=Y0lT9Fck7qI

**💻 Solutions**:
- [C++](src/cpp/dp/70.climbing-stairs.cpp)
- [Go](src/go/dp/70.climbing-stairs.go)
- [Java](src/java/dp/P70.java)

**🧪 Test Cases** (7 cases):
1. `{"input": 1, "expected": 1}`
2. `{"input": 2, "expected": 2}`
3. `{"input": 3, "expected": 3}`
   ... and 4 more cases

</details>

<details>
<summary><strong>LC94: Binary Tree Inorder Traversal</strong> (Easy) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/binary-tree-inorder-traversal/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=g_S5WuasWUE

**💻 Solutions**:
- [C++](src/cpp/tree/94.binary-tree-inorder-traversal.cpp)
- [Go](src/go/tree/94.binary-tree-inorder-traversal.go)
- [Java](src/java/tree/94.binary-tree-inorder-traversal.java)

**🧪 Test Cases** (5 cases):
1. `{"tree": [1, None, 2, 3], "expected": [1, 3, 2]}`
2. `{"tree": [], "expected": []}`
3. `{"tree": [1], "expected": [1]}`
   ... and 2 more cases

</details>

<details>
<summary><strong>LC98: Validate Binary Search Tree</strong> (Medium) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/validate-binary-search-tree/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=s6ATEkipzow

**💻 Solutions**:
- [C++](src/cpp/tree/98.validate-binary-search-tree.cpp)
- [Go](src/go/tree/98.validate-binary-search-tree.go)
- [Java](src/java/tree/98.validate-binary-search-tree.java)

**🧪 Test Cases** (6 cases):
1. `{"tree": [2, 1, 3], "expected": True}`
2. `{"tree": [5, 1, 4, None, None, 3, 6], "expected": False}`
3. `{"tree": [], "expected": True}`
   ... and 3 more cases

</details>

<details>
<summary><strong>LC100: Same Tree</strong> (Easy) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/same-tree/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=vRbbcKXCxOw

**💻 Solutions**:
- [C++](src/cpp/tree/100.same-tree.cpp)
- [Go](src/go/tree/100.same-tree.go)
- [Java](src/java/tree/100.same-tree.java)

**🧪 Test Cases** (5 cases):
1. `{"p": [], "q": [], "expected": True}`
2. `{"p": [1, 2, 3], "q": [1, 2, 3], "expected": True}`
3. `{"p": [1, 2], "q": [1, None, 2], "expected": False}`
   ... and 2 more cases

</details>

<details>
<summary><strong>LC102: Binary Tree Level Order Traversal</strong> (Medium) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/binary-tree-level-order-traversal/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=6ZnyEApgFYg

**💻 Solutions**:
- [C++](src/cpp/tree/102.binary-tree-level-order-traversal.cpp)
- [Go](src/go/tree/102.binary-tree-level-order-traversal.go)
- [Java](src/java/tree/102.binary-tree-level-order-traversal.java)

**🧪 Test Cases** (5 cases):
1. `{"tree": [], "expected": []}`
2. `{"tree": [1], "expected": [[1]]}`
3. `{"tree": [3, 9, 20, None, None, 15, 7], "expected": [[3], [9, 20], [15, 7]]}`
   ... and 2 more cases

</details>

<details>
<summary><strong>LC103: Binary Tree Zigzag Level Order Traversal</strong> (Medium) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=s6ATEkipzow

**💻 Solutions**:
- [C++](src/cpp/tree/103.binary-tree-zigzag-level-order-traversal.cpp)
- [Go](src/go/tree/103.binary-tree-zigzag-level-order-traversal.go)
- [Java](src/java/tree/103.binary-tree-zigzag-level-order-traversal.java)

**🧪 Test Cases** (5 cases):
1. `{"tree": [], "expected": []}`
2. `{"tree": [1], "expected": [[1]]}`
3. `{"tree": [3, 9, 20, None, None, 15, 7], "expected": [[3], [20, 9], [15, 7]]}`
   ... and 2 more cases

</details>

<details>
<summary><strong>LC104: Maximum Depth of Binary Tree</strong> (Easy) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/maximum-depth-of-binary-tree/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=hTM3phVI6YQ

**💻 Solutions**:
- [C++](src/cpp/tree/104.maximum-depth-of-binary-tree.cpp)
- [Go](src/go/tree/104.maximum-depth-of-binary-tree.go)
- [Java](src/java/tree/104.maximum-depth-of-binary-tree.java)

**🧪 Test Cases** (8 cases):
1. `{"tree": [3, 9, 20, None, None, 15, 7], "expected": 3}`
2. `{"tree": [], "expected": 0}`
3. `{"tree": [1], "expected": 1}`
   ... and 5 more cases

</details>

<details>
<summary><strong>LC110: Balanced Binary Tree</strong> (Easy) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/balanced-binary-tree/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=QfJsau0ItOY

**💻 Solutions**:
- [C++](src/cpp/tree/110.balanced-binary-tree.cpp)
- [Go](src/go/tree/110.balanced-binary-tree.go)
- [Java](src/java/tree/110.balanced-binary-tree.java)

**🧪 Test Cases** (8 cases):
1. `{"tree": [3, 9, 20, None, None, 15, 7], "expected": True}`
2. `{"tree": [], "expected": True}`
3. `{"tree": [1], "expected": True}`
   ... and 5 more cases

</details>

<details>
<summary><strong>LC139: Word Break</strong> (Medium) - dp</summary>

**🔗 Problem Link**: https://leetcode.com/problems/word-break/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=Sx9NNgInc3A

**💻 Solutions**:
- [C++](src/cpp/dp/139.word-break.cpp)
- [Go](src/go/dp/139.word-break.go)
- [Java](src/java/dp/P139.java)

**🧪 Test Cases** (4 cases):
1. `{"s": "leetcode", "wordDict": ["leet", "code"], "expected": True}`
2. `{"s": "applepenapple", "wordDict": ["apple", "pen"], "expected": True}`
3. `{"s": "catsandog", "wordDict": ["cats", "dog", "sand", "and", "cat"], "expected": False}`
   ... and 1 more cases

</details>

<details>
<summary><strong>LC160: Intersection of Two Linked Lists</strong> (Easy) - list</summary>

**🔗 Problem Link**: https://leetcode.com/problems/intersection-of-two-linked-lists/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=D0X0BONOQhI

**💻 Solutions**:
- [C++](src/cpp/list/160.intersection-of-two-linked-lists.cpp)
- [Go](src/go/list/160.intersection-of-two-linked-lists.go)
- [Java](src/java/list/160.intersection-of-two-linked-lists.java)

**🧪 Test Cases** (3 cases):
1. `{"listA": [4, 1, 8, 4, 5], "listB": [5, 6, 1, 8, 4, 5], "intersectVal": 8, "skipA": 2, "skipB": 3, "...`
2. `{"listA": [1, 9, 1, 2, 4], "listB": [3, 2, 4], "intersectVal": 2, "skipA": 3, "skipB": 1, "expected"...`
3. `{"listA": [2, 6, 4], "listB": [1, 5], "intersectVal": 0, "skipA": 3, "skipB": 2, "expected": None}`

</details>

<details>
<summary><strong>LC198: House Robber</strong> (Medium) - dp</summary>

**🔗 Problem Link**: https://leetcode.com/problems/house-robber/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=73r3KWiEvyk

**💻 Solutions**:
- [C++](src/cpp/dp/198.house-robber.cpp)
- [Go](src/go/dp/198.house-robber.go)
- [Java](src/java/dp/198.house-robber.java)

**🧪 Test Cases** (8 cases):
1. `{"input": [1, 2, 3, 1], "expected": 4}`
2. `{"input": [2, 7, 9, 3, 1], "expected": 12}`
3. `{"input": [5, 1, 3, 9], "expected": 14}`
   ... and 5 more cases

</details>

<details>
<summary><strong>LC200: Number of Islands</strong> (Medium) - graphs</summary>

**🔗 Problem Link**: https://leetcode.com/problems/number-of-islands/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=pV2kpPD66nE

**💻 Solutions**:
- [C++](src/cpp/graphs/200.number-of-islands.cpp)
- [Go](src/go/graphs/200.number-of-islands.go)
- [Java](src/java/graphs/200.number-of-islands.java)

**🧪 Test Cases** (2 cases):
1. `{"grid": [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"], ["1", "1", "0", "0", "0"], ["0", "0"...`
2. `{"grid": [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "1", "0", "0"], ["0", "0"...`

</details>

<details>
<summary><strong>LC206: Reverse Linked List</strong> (Easy) - list</summary>

**🔗 Problem Link**: https://leetcode.com/problems/reverse-linked-list/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=G0_I-ZF0S38

**💻 Solutions**:
- [C++](src/cpp/list/206.reverse-linked-list.cpp)
- [Go](src/go/list/206.reverse-linked-list.go)
- [Java](src/java/list/206.reverse-linked-list.java)

**🧪 Test Cases** (3 cases):
1. `{"head": [1, 2, 3, 4, 5], "expected": [5, 4, 3, 2, 1]}`
2. `{"head": [1, 2], "expected": [2, 1]}`
3. `{"head": [], "expected": []}`

</details>

<details>
<summary><strong>LC213: House Robber II</strong> (Medium) - dp</summary>

**🔗 Problem Link**: https://leetcode.com/problems/house-robber-ii/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=rWAJCfYYOvM

**💻 Solutions**:
- [C++](src/cpp/dp/213.house-robber-ii.cpp)
- [Go](src/go/dp/213.house-robber-ii.go)
- [Java](src/java/dp/P213.java)

**🧪 Test Cases** (7 cases):
1. `{"nums": [2, 3, 2], "expected": 3}`
2. `{"nums": [1, 2, 3, 1], "expected": 4}`
3. `{"nums": [1, 2, 3], "expected": 3}`
   ... and 4 more cases

</details>

<details>
<summary><strong>LC226: Invert Binary Tree</strong> (Easy) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/invert-binary-tree/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=OnSn2XEQ4MY

**💻 Solutions**:
- [C++](src/cpp/tree/226.invert-binary-tree.cpp)
- [Go](src/go/tree/226.invert-binary-tree.go)
- [Java](src/java/tree/226.invert-binary-tree.java)

**🧪 Test Cases** (3 cases):
1. `{"root": [4, 2, 7, 1, 3, 6, 9], "expected": [4, 7, 2, 9, 6, 3, 1]}`
2. `{"root": [2, 1, 3], "expected": [2, 3, 1]}`
3. `{"root": [], "expected": []}`

</details>

<details>
<summary><strong>LC238: Product of Array Except Self</strong> (Medium) - prefix_sum</summary>

**🔗 Problem Link**: https://leetcode.com/problems/product-of-array-except-self/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=bNvIQI2wAjk

**💻 Solutions**:
- [C++](src/cpp/prefix_sum/238.product-of-array-except-self.cpp)
- [Go](src/go/prefix_sum/238.product-of-array-except-self.go)
- [Java](src/java/prefix_sum/238.product-of-array-except-self.java)

**🧪 Test Cases** (2 cases):
1. `{"nums": [1, 2, 3, 4], "expected": [24, 12, 8, 6]}`
2. `{"nums": [-1, 1, 0, -3, 3], "expected": [0, 0, 9, 0, 0]}`

</details>

<details>
<summary><strong>LC424: Longest Repeating Character Replacement</strong> (Medium) - sliding_window</summary>

**🔗 Problem Link**: https://leetcode.com/problems/longest-repeating-character-replacement/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=gqXU1UyA8pk

**💻 Solutions**:
- [C++](src/cpp/sliding_window/424.longest-repeating-character-replacement.cpp)
- [Go](src/go/sliding_window/424.longest-repeating-character-replacement.go)
- [Java](src/java/sliding_window/424.longest-repeating-character-replacement.java)

**🧪 Test Cases** (5 cases):
1. `{"input": "AABABBA", "k": 1, "expected": 4}`
2. `{"input": "ABAB", "k": 2, "expected": 4}`
3. `{"input": "AAAA", "k": 2, "expected": 4}`
   ... and 2 more cases

</details>

<details>
<summary><strong>LC438: Find All Anagrams in a String</strong> (Medium) - sliding_window</summary>

**🔗 Problem Link**: https://leetcode.com/problems/find-all-anagrams-in-a-string/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=G8xtZy0fDKg

**💻 Solutions**:
- [C++](src/cpp/sliding_window/438.find-all-anagrams-in-a-string.cpp)
- [Go](src/go/sliding_window/438.find-all-anagrams-in-a-string.go)
- [Java](src/java/sliding_window/438.find-all-anagrams-in-a-string.java)

**🧪 Test Cases** (4 cases):
1. `{"s": "cbaebabacd", "p": "abc", "expected": [0, 6]}`
2. `{"s": "abab", "p": "ab", "expected": [0, 1, 2]}`
3. `{"s": "baa", "p": "aa", "expected": [1]}`
   ... and 1 more cases

</details>

<details>
<summary><strong>LC560: Subarray Sum Equals K</strong> (Medium) - prefix_sum</summary>

**🔗 Problem Link**: https://leetcode.com/problems/subarray-sum-equals-k/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=HbbYPQc-Oo4

**💻 Solutions**:
- [C++](src/cpp/prefix_sum/560.subarray-sum-equals-k.cpp)
- [Go](src/go/prefix_sum/560.subarray-sum-equals-k.go)
- [Java](src/java/prefix_sum/560.subarray-sum-equals-k.java)

**🧪 Test Cases** (2 cases):
1. `{"nums": [1, 1, 1], "k": 2, "expected": 2}`
2. `{"nums": [1, 2, 3], "k": 3, "expected": 2}`

</details>

<details>
<summary><strong>LC567: Permutation in String</strong> (Medium) - sliding_window</summary>

**🔗 Problem Link**: https://leetcode.com/problems/permutation-in-string/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=UbyhOgBN834

**💻 Solutions**:
- [C++](src/cpp/sliding_window/567.permutation-in-string.cpp)
- [Go](src/go/sliding_window/567.permutation-in-string.go)
- [Java](src/java/sliding_window/567.permutation-in-string.java)

**🧪 Test Cases** (5 cases):
1. `{"s1": "ab", "s2": "eidbaooo", "expected": True}`
2. `{"s1": "ab", "s2": "eidboaoo", "expected": False}`
3. `{"s1": "adc", "s2": "dcda", "expected": True}`
   ... and 2 more cases

</details>

<details>
<summary><strong>LC739: Daily Temperatures</strong> (Medium) - stack</summary>

**🔗 Problem Link**: https://leetcode.com/problems/daily-temperatures/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=cTBiBSnjO3c

**💻 Solutions**:
- [C++](src/cpp/stack/739.daily-temperatures.cpp)
- [Go](src/go/stack/739.daily-temperatures.go)
- [Java](src/java/stack/739.daily-temperatures.java)

**🧪 Test Cases** (6 cases):
1. `{"input": [73, 74, 75, 71, 69, 72, 76, 73], "expected": [1, 1, 4, 2, 1, 1, 0, 0]}`
2. `{"input": [30, 40, 50, 60], "expected": [1, 1, 1, 0]}`
3. `{"input": [30, 60, 90], "expected": [1, 1, 0]}`
   ... and 3 more cases

</details>

<details>
<summary><strong>LC1235: Maximum Profit in Job Scheduling</strong> (Hard) - dp</summary>

**🔗 Problem Link**: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=JLoWc3v0SiE

**💻 Solutions**:
- [C++](src/cpp/dp/1235.maximum-profit-in-job-scheduling.cpp)
- [Go](src/go/dp/1235.maximum-profit-in-job-scheduling.go)
- [Java](src/java/dp/P1235.java)
- [Python](src/python/dp/1235.maximum-profit-in-job-scheduling.py)

**🧪 Test Cases** (4 cases):
1. `{"startTime": [1,2,3,3], "endTime": [3,4,5,6], "profit": [50,10,40,70], "expected": 120}`
2. `{"startTime": [1,2,3,4,6], "endTime": [3,5,10,6,9], "profit": [20,20,100,70,60], "expected": 150}`
3. `{"startTime": [1,1,1], "endTime": [2,3,4], "profit": [5,6,4], "expected": 6}`
   ... and 1 more case

</details>

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
