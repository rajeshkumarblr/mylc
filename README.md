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

# run an STL reference example (1=vector, 2=list, ..., 10=priority_queue)
./run -e 1
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

All 173 problems implemented across C++, Go, and Java. Use `./run -l` to list problems, `./run -c <category>` to run by category.

_Click problem ID to view LeetCode problem description (opens in new tab). Click ✓ to view source code. Click 📺 for NeetCode explanation videos._

| ID | Problem | Category | Difficulty | Test Cases | C++ | Go | Java | NeetCode Explanation Video |
|---:|---|---|---|---:|---|---|---|---|
| <a href="https://leetcode.com/problems/two-sum/description/" target="_blank">1</a> | Two Sum | hash | Easy | 2 | [✓](src/cpp/hash/1.two-sum.cpp) | [✓](src/go/hash/1.two.sum.go) | - | [📺](https://www.youtube.com/watch?v=KLlXCFG5TnA) |
| <a href="https://leetcode.com/problems/add-two-numbers/description/" target="_blank">2</a> | Add Two Numbers | list | Medium | 1 | [✓](src/cpp/list/2.add-two-numbers.cpp) | [✓](src/go/list/2.add-two-numbers.go) | - | [📺](https://www.youtube.com/watch?v=wgFPrzTjm7s) |
| <a href="https://leetcode.com/problems/longest-substring-without-repeating-characters/description/" target="_blank">3</a> | Longest Substring Without Repeating Characters | sliding_window | Medium | 2 | [✓](src/cpp/sliding_window/3.longest-substring-without-repeating-characters.cpp) | [✓](src/go/sliding_window/3.longest-substring-without-repeating-characters.go) | - | [📺](https://www.youtube.com/watch?v=wiGpQwVHdE0) |
| <a href="https://leetcode.com/problems/median-of-two-sorted-arrays/description/" target="_blank">4</a> | Median of Two Sorted Arrays | neet150 | Hard | 0 | [✓](src/cpp/neet150/4.median-of-two-sorted-arrays.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/longest-palindromic-substring/description/" target="_blank">5</a> | Longest Palindromic Substring | neet150 | Medium | 0 | [✓](src/cpp/neet150/5.longest-palindromic-substring.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/reverse-integer/description/" target="_blank">7</a> | Reverse Integer | neet150 | Medium | 0 | [✓](src/cpp/neet150/7.reverse-integer.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/palindrome-number/description/" target="_blank">9</a> | Palindrome Number | misc | Easy | 6 | [✓](src/cpp/misc/9.palindrome-number.cpp) | [✓](src/go/misc/9.palindrome-number.go) | - | [📺](https://www.youtube.com/watch?v=f5qF2OowB5A) |
| <a href="https://leetcode.com/problems/regular-expression-matching/description/" target="_blank">10</a> | Regular Expression Matching | neet150 | Hard | 0 | [✓](src/cpp/neet150/10.regular-expression-matching.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/container-with-most-water/description/" target="_blank">11</a> | Container With Most Water | two_pointer | Medium | 9 | [✓](src/cpp/two_pointer/11.container-with-most-water.cpp) | [✓](src/go/two_pointer/11.container-with-most-water.go) | - | [📺](https://www.youtube.com/watch?v=UuiTKBwPgAo) |
| <a href="https://leetcode.com/problems/roman-to-integer/description/" target="_blank">13</a> | Roman to Integer | misc | Easy | 3 | - | - | - | - |
| <a href="https://leetcode.com/problems/3sum/description/" target="_blank">15</a> | 3Sum | two_pointer | Medium | 4 | [✓](src/cpp/two_pointer/15.3-sum.cpp) | [✓](src/go/two_pointer/15.3-sum.go) | - | [📺](https://www.youtube.com/watch?v=jzZsG8n2R9A) |
| <a href="https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/" target="_blank">17</a> | Letter Combinations of a Phone Number | neet150 | Medium | 0 | [✓](src/cpp/neet150/17.letter-combinations-of-a-phone-number.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/" target="_blank">19</a> | Remove Nth Node From End of List | neet150 | Medium | 0 | [✓](src/cpp/neet150/19.remove-nth-node-from-end-of-list.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/valid-parentheses/description/" target="_blank">20</a> | Valid Parentheses | stack | Easy | 10 | [✓](src/cpp/stack/20.valid-parentheses.cpp) | [✓](src/go/stack/20.valid-parentheses.go) | - | [📺](https://www.youtube.com/watch?v=WTzjTskDFMg) |
| <a href="https://leetcode.com/problems/merge-two-sorted-lists/description/" target="_blank">21</a> | Merge Two Sorted Lists | list | Easy | 7 | [✓](src/cpp/list/21.merge-two-sorted-lists.cpp) | [✓](src/go/list/21.merge-two-sorted-lists.go) | - | [📺](https://www.youtube.com/watch?v=XIdigk956u0) |
| <a href="https://leetcode.com/problems/generate-parentheses/description/" target="_blank">22</a> | Generate Parentheses | neet150 | Medium | 0 | [✓](src/cpp/neet150/22.generate-parentheses.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/merge-k-sorted-lists/description/" target="_blank">23</a> | Merge K Sorted Lists | neet150 | Hard | 0 | [✓](src/cpp/neet150/23.merge-k-sorted-lists.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/reverse-nodes-in-k-group/description/" target="_blank">25</a> | Reverse Nodes In K Group | neet150 | Hard | 0 | [✓](src/cpp/neet150/25.reverse-nodes-in-k-group.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/search-in-rotated-sorted-array/description/" target="_blank">33</a> | Search in Rotated Sorted Array | binary_search | Medium | 3 | [✓](src/cpp/binary_search/33.search-in-rotated-sorted-array.cpp) | [✓](src/go/binary_search/33.search-in-rotated-sorted-array.go) | - | [📺](https://www.youtube.com/watch?v=U8XENwh8Oy8) |
| <a href="https://leetcode.com/problems/search-insert-position/description/" target="_blank">35</a> | Search Insert Position | binary_search | Easy | 4 | [✓](src/cpp/binary_search/35.search-insert-position.cpp) | [✓](src/go/binary_search/35.search-insert-position.go) | - | [📺](https://www.youtube.com/watch?v=K-RYzDZkzCI) |
| <a href="https://leetcode.com/problems/valid-sudoku/description/" target="_blank">36</a> | Valid Sudoku | hash | Medium | 2 | [✓](src/cpp/hash/36.valid-sudoku.cpp) | [✓](src/go/hash/36.valid-sudoku.go) | - | [📺](https://www.youtube.com/watch?v=TjFXEUCMqI8) |
| <a href="https://leetcode.com/problems/combination-sum/description/" target="_blank">39</a> | Combination Sum | neet150 | Medium | 0 | [✓](src/cpp/neet150/39.combination-sum.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/combination-sum-ii/description/" target="_blank">40</a> | Combination Sum II | neet150 | Medium | 0 | [✓](src/cpp/neet150/40.combination-sum-ii.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/trapping-rain-water/description/" target="_blank">42</a> | Trapping Rain Water | two_pointer | Hard | 6 | [✓](src/cpp/two_pointer/42.trapping-rain-water.cpp) | [✓](src/go/two_pointer/42.trapping-rain-water.go) | - | [📺](https://www.youtube.com/watch?v=ZI2z5pq0TqA) |
| <a href="https://leetcode.com/problems/multiply-strings/description/" target="_blank">43</a> | Multiply Strings | neet150 | Medium | 0 | [✓](src/cpp/neet150/43.multiply-strings.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/jump-game-ii/description/" target="_blank">45</a> | Jump Game II | neet150 | Medium | 0 | [✓](src/cpp/neet150/45.jump-game-ii.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/permutations/description/" target="_blank">46</a> | Permutations | neet150 | Medium | 0 | [✓](src/cpp/neet150/46.permutations.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/rotate-image/description/" target="_blank">48</a> | Rotate Image | neet150 | Medium | 0 | [✓](src/cpp/neet150/48.rotate-image.cpp) | - | - | - |
| 49 | Group Anagrams | hash | Medium | 3 | [✓](src/cpp/neet150/49.group-anagrams.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/powx-n/description/" target="_blank">50</a> | Pow(x, n) | neet150 | Medium | 0 | [✓](src/cpp/neet150/50.powx-n.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/n-queens/description/" target="_blank">51</a> | N Queens | neet150 | Hard | 0 | [✓](src/cpp/neet150/51.n-queens.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/maximum-subarray/description/" target="_blank">53</a> | Maximum Subarray | neet150 | Medium | 0 | [✓](src/cpp/neet150/53.maximum-subarray.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/spiral-matrix/description/" target="_blank">54</a> | Spiral Matrix | neet150 | Medium | 0 | [✓](src/cpp/neet150/54.spiral-matrix.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/jump-game/description/" target="_blank">55</a> | Jump Game | neet150 | Medium | 0 | [✓](src/cpp/neet150/55.jump-game.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/merge-intervals/description/" target="_blank">56</a> | Merge Intervals | misc | Medium | 3 | [✓](src/cpp/misc/56.merge-intervals.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/insert-interval/description/" target="_blank">57</a> | Insert Interval | neet150 | Medium | 0 | [✓](src/cpp/neet150/57.insert-interval.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/unique-paths/description/" target="_blank">62</a> | Unique Paths | neet150 | Medium | 0 | [✓](src/cpp/neet150/62.unique-paths.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/plus-one/description/" target="_blank">66</a> | Plus One | neet150 | Easy | 0 | [✓](src/cpp/neet150/66.plus-one.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/climbing-stairs/description/" target="_blank">70</a> | Climbing Stairs | dp | Easy | 7 | [✓](src/cpp/dp/70.climbing-stairs.cpp) | [✓](src/go/dp/70.climbing-stairs.go) | [✓](src/java/dp/P70.java) | [📺](https://www.youtube.com/watch?v=Y0lT9Fck7qI) |
| <a href="https://leetcode.com/problems/edit-distance/description/" target="_blank">72</a> | Edit Distance | neet150 | Medium | 0 | [✓](src/cpp/neet150/72.edit-distance.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/set-matrix-zeroes/description/" target="_blank">73</a> | Set Matrix Zeroes | neet150 | Medium | 0 | [✓](src/cpp/neet150/73.set-matrix-zeroes.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/search-a-2d-matrix/description/" target="_blank">74</a> | Search a 2D Matrix | neet150 | Medium | 0 | [✓](src/cpp/neet150/74.search-a-2d-matrix.cpp) | - | - | - |
| 76 | Minimum Window Substring | sliding_window | - | 3 | [✓](src/cpp/sliding_window/76.minimum-window-substring.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/subsets/description/" target="_blank">78</a> | Subsets | neet150 | Medium | 0 | [✓](src/cpp/neet150/78.subsets.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/word-search/description/" target="_blank">79</a> | Word Search | neet150 | Medium | 0 | [✓](src/cpp/neet150/79.word-search.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/largest-rectangle-in-histogram/description/" target="_blank">84</a> | Largest Rectangle In Histogram | neet150 | Hard | 0 | [✓](src/cpp/neet150/84.largest-rectangle-in-histogram.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/subsets-ii/description/" target="_blank">90</a> | Subsets II | neet150 | Medium | 0 | [✓](src/cpp/neet150/90.subsets-ii.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/decode-ways/description/" target="_blank">91</a> | Decode Ways | neet150 | Medium | 0 | [✓](src/cpp/neet150/91.decode-ways.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/binary-tree-inorder-traversal/description/" target="_blank">94</a> | Binary Tree Inorder Traversal | tree | Easy | 5 | [✓](src/cpp/tree/94.binary-tree-inorder-traversal.cpp) | [✓](src/go/tree/94.binary-tree-inorder-traversal.go) | - | [📺](https://www.youtube.com/watch?v=g_S5WuasWUE) |
| <a href="https://leetcode.com/problems/interleaving-string/description/" target="_blank">97</a> | Interleaving String | neet150 | Medium | 0 | [✓](src/cpp/neet150/97.interleaving-string.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/validate-binary-search-tree/description/" target="_blank">98</a> | Validate Binary Search Tree | tree | Medium | 6 | [✓](src/cpp/tree/98.validate-binary-search-tree.cpp) | [✓](src/go/tree/98.validate-binary-search-tree.go) | - | [📺](https://www.youtube.com/watch?v=s6ATEkipzow) |
| <a href="https://leetcode.com/problems/same-tree/description/" target="_blank">100</a> | Same Tree | tree | Easy | 5 | [✓](src/cpp/tree/100.same-tree.cpp) | [✓](src/go/tree/100.same-tree.go) | - | [📺](https://www.youtube.com/watch?v=vRbbcKXCxOw) |
| <a href="https://leetcode.com/problems/binary-tree-level-order-traversal/description/" target="_blank">102</a> | Binary Tree Level Order Traversal | tree | Medium | 5 | [✓](src/cpp/tree/102.binary-tree-level-order-traversal.cpp) | [✓](src/go/tree/102.binary-tree-level-order-traversal.go) | - | [📺](https://www.youtube.com/watch?v=6ZnyEApgFYg) |
| <a href="https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/" target="_blank">103</a> | Binary Tree Zigzag Level Order Traversal | tree | Medium | 5 | [✓](src/cpp/tree/103.binary-tree-zigzag-level-order-traversal.cpp) | [✓](src/go/tree/103.binary-tree-zigzag-level-order-traversal.go) | - | [📺](https://www.youtube.com/watch?v=s6ATEkipzow) |
| <a href="https://leetcode.com/problems/maximum-depth-of-binary-tree/description/" target="_blank">104</a> | Maximum Depth of Binary Tree | tree | Easy | 8 | [✓](src/cpp/tree/104.maximum-depth-of-binary-tree.cpp) | [✓](src/go/tree/104.maximum-depth-of-binary-tree.go) | - | [📺](https://www.youtube.com/watch?v=hTM3phVI6YQ) |
| <a href="https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/" target="_blank">105</a> | Construct Binary Tree From Preorder And Inorder Traversal | neet150 | Medium | 0 | [✓](src/cpp/neet150/105.construct-binary-tree-from-preorder-and-inorder-traversal.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/balanced-binary-tree/description/" target="_blank">110</a> | Balanced Binary Tree | tree | Easy | 8 | [✓](src/cpp/tree/110.balanced-binary-tree.cpp) | [✓](src/go/tree/110.balanced-binary-tree.go) | - | [📺](https://www.youtube.com/watch?v=QfJsau0ItOY) |
| <a href="https://leetcode.com/problems/distinct-subsequences/description/" target="_blank">115</a> | Distinct Subsequences | neet150 | Hard | 0 | [✓](src/cpp/neet150/115.distinct-subsequences.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/" target="_blank">121</a> | Best Time to Buy And Sell Stock | neet150 | Easy | 0 | [✓](src/cpp/neet150/121.best-time-to-buy-and-sell-stock.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/binary-tree-maximum-path-sum/description/" target="_blank">124</a> | Binary Tree Maximum Path Sum | neet150 | Hard | 0 | [✓](src/cpp/neet150/124.binary-tree-maximum-path-sum.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/valid-palindrome/description/" target="_blank">125</a> | Valid Palindrome | neet150 | Easy | 0 | [✓](src/cpp/neet150/125.valid-palindrome.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/word-ladder/description/" target="_blank">127</a> | Word Ladder | neet150 | Hard | 0 | [✓](src/cpp/neet150/127.word-ladder.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/longest-consecutive-sequence/description/" target="_blank">128</a> | Longest Consecutive Sequence | neet150 | Medium | 0 | [✓](src/cpp/neet150/128.longest-consecutive-sequence.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/surrounded-regions/description/" target="_blank">130</a> | Surrounded Regions | neet150 | Medium | 0 | [✓](src/cpp/neet150/130.surrounded-regions.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/palindrome-partitioning/description/" target="_blank">131</a> | Palindrome Partitioning | neet150 | Medium | 0 | [✓](src/cpp/neet150/131.palindrome-partitioning.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/clone-graph/description/" target="_blank">133</a> | Clone Graph | neet150 | Medium | 0 | [✓](src/cpp/neet150/133.clone-graph.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/gas-station/description/" target="_blank">134</a> | Gas Station | neet150 | Medium | 0 | [✓](src/cpp/neet150/134.gas-station.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/single-number/description/" target="_blank">136</a> | Single Number | neet150 | Easy | 0 | [✓](src/cpp/neet150/136.single-number.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/copy-list-with-random-pointer/description/" target="_blank">138</a> | Copy List With Random Pointer | neet150 | Medium | 0 | [✓](src/cpp/neet150/138.copy-list-with-random-pointer.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/word-break/description/" target="_blank">139</a> | Word Break | dp | Medium | 4 | [✓](src/cpp/dp/139.word-break.cpp) | [✓](src/go/dp/139.word-break.go) | [✓](src/java/dp/P139.java) | [📺](https://www.youtube.com/watch?v=Sx9NNgInc3A) |
| <a href="https://leetcode.com/problems/linked-list-cycle/description/" target="_blank">141</a> | Linked List Cycle | neet150 | Easy | 0 | [✓](src/cpp/neet150/141.linked-list-cycle.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/reorder-list/description/" target="_blank">143</a> | Reorder List | neet150 | Medium | 0 | [✓](src/cpp/neet150/143.reorder-list.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/lru-cache/description/" target="_blank">146</a> | LRU Cache | misc | Medium | 2 | [✓](src/cpp/neet150/146.lru-cache.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/evaluate-reverse-polish-notation/description/" target="_blank">150</a> | Evaluate Reverse Polish Notation | neet150 | Medium | 0 | [✓](src/cpp/neet150/150.evaluate-reverse-polish-notation.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/maximum-product-subarray/description/" target="_blank">152</a> | Maximum Product Subarray | neet150 | Medium | 0 | [✓](src/cpp/neet150/152.maximum-product-subarray.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/" target="_blank">153</a> | Find Minimum In Rotated Sorted Array | neet150 | Medium | 0 | [✓](src/cpp/neet150/153.find-minimum-in-rotated-sorted-array.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/min-stack/description/" target="_blank">155</a> | Min Stack | neet150 | Medium | 0 | [✓](src/cpp/neet150/155.min-stack.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/intersection-of-two-linked-lists/description/" target="_blank">160</a> | Intersection of Two Linked Lists | list | Easy | 3 | [✓](src/cpp/list/160.intersection-of-two-linked-lists.cpp) | [✓](src/go/list/160.intersection-of-two-linked-lists.go) | - | [📺](https://www.youtube.com/watch?v=D0X0BONOQhI) |
| <a href="https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/" target="_blank">167</a> | Two Sum II Input Array Is Sorted | neet150 | Medium | 0 | [✓](src/cpp/neet150/167.two-sum-ii-input-array-is-sorted.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/reverse-bits/description/" target="_blank">190</a> | Reverse Bits | neet150 | Easy | 0 | [✓](src/cpp/neet150/190.reverse-bits.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/number-of-1-bits/description/" target="_blank">191</a> | Number of 1 Bits | neet150 | Easy | 0 | [✓](src/cpp/neet150/191.number-of-1-bits.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/house-robber/description/" target="_blank">198</a> | House Robber | dp | Medium | 8 | [✓](src/cpp/dp/198.house-robber.cpp) | [✓](src/go/dp/198.house-robber.go) | [✓](src/java/dp/P198.java) | [📺](https://www.youtube.com/watch?v=73r3KWiEvyk) |
| <a href="https://leetcode.com/problems/binary-tree-right-side-view/description/" target="_blank">199</a> | Binary Tree Right Side View | tree | Medium | 3 | [✓](src/cpp/neet150/199.binary-tree-right-side-view.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/number-of-islands/description/" target="_blank">200</a> | Number of Islands | graphs | Medium | 2 | [✓](src/cpp/graphs/200.number-of-islands.cpp) | [✓](src/go/graphs/200.number-of-islands.go) | - | [📺](https://www.youtube.com/watch?v=pV2kpPD66nE) |
| <a href="https://leetcode.com/problems/happy-number/description/" target="_blank">202</a> | Happy Number | neet150 | Easy | 0 | [✓](src/cpp/neet150/202.happy-number.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/isomorphic-strings/description/" target="_blank">205</a> | Isomorphic Strings | hash | Easy | 3 | - | - | - | - |
| <a href="https://leetcode.com/problems/reverse-linked-list/description/" target="_blank">206</a> | Reverse Linked List | list | Easy | 3 | [✓](src/cpp/list/206.reverse-linked-list.cpp) | [✓](src/go/list/206.reverse-linked-list.go) | - | [📺](https://www.youtube.com/watch?v=G0_I-ZF0S38) |
| <a href="https://leetcode.com/problems/course-schedule/description/" target="_blank">207</a> | Course Schedule | graphs | Medium | 3 | [✓](src/cpp/neet150/207.course-schedule.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/implement-trie-prefix-tree/description/" target="_blank">208</a> | Implement Trie Prefix Tree | neet150 | Medium | 0 | [✓](src/cpp/neet150/208.implement-trie-prefix-tree.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/course-schedule-ii/description/" target="_blank">210</a> | Course Schedule II | graphs | Medium | 4 | [✓](src/cpp/neet150/210.course-schedule-ii.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/design-add-and-search-words-data-structure/description/" target="_blank">211</a> | Design Add And Search Words Data Structure | neet150 | Medium | 0 | [✓](src/cpp/neet150/211.design-add-and-search-words-data-structure.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/word-search-ii/description/" target="_blank">212</a> | Word Search II | neet150 | Hard | 0 | [✓](src/cpp/neet150/212.word-search-ii.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/house-robber-ii/description/" target="_blank">213</a> | House Robber II | dp | Medium | 7 | [✓](src/cpp/neet150/213.house-robber-ii.cpp) | [✓](src/go/dp/213.house-robber-ii.go) | [✓](src/java/dp/P213.java) | [📺](https://www.youtube.com/watch?v=rWAJCfYYOvM) |
| <a href="https://leetcode.com/problems/kth-largest-element-in-an-array/description/" target="_blank">215</a> | Kth Largest Element in an Array | misc | Medium | 2 | [✓](src/cpp/misc/215.kth-largest-element-in-an-array.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/kth-smallest-element-in-an-array/description/" target="_blank">216</a> | Kth Smallest Element in an Array | misc | Medium | 2 | [✓](src/cpp/misc/216.kth-smallest-element-in-an-array.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/contains-duplicate/description/" target="_blank">217</a> | Contains Duplicate | neet150 | Easy | 0 | [✓](src/cpp/neet150/217.contains-duplicate.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/invert-binary-tree/description/" target="_blank">226</a> | Invert Binary Tree | tree | Easy | 3 | [✓](src/cpp/tree/226.invert-binary-tree.cpp) | [✓](src/go/tree/226.invert-binary-tree.go) | - | [📺](https://www.youtube.com/watch?v=OnSn2XEQ4MY) |
| <a href="https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/" target="_blank">230</a> | Kth Smallest Element In a Bst | neet150 | Medium | 0 | [✓](src/cpp/neet150/230.kth-smallest-element-in-a-bst.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/" target="_blank">235</a> | Lowest Common Ancestor of a Binary Search Tree | neet150 | Medium | 0 | [✓](src/cpp/neet150/235.lowest-common-ancestor-of-a-binary-search-tree.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/product-of-array-except-self/description/" target="_blank">238</a> | Product of Array Except Self | prefix_sum | Medium | 2 | [✓](src/cpp/prefix_sum/238.product-of-array-except-self.cpp) | [✓](src/go/prefix_sum/238.product-of-array-except-self.go) | - | [📺](https://www.youtube.com/watch?v=bNvIQI2wAjk) |
| <a href="https://leetcode.com/problems/sliding-window-maximum/description/" target="_blank">239</a> | Sliding Window Maximum | neet150 | Hard | 0 | [✓](src/cpp/neet150/239.sliding-window-maximum.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/valid-anagram/description/" target="_blank">242</a> | Valid Anagram | hash | Easy | 2 | [✓](src/cpp/neet150/242.valid-anagram.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/meeting-rooms/description/" target="_blank">252</a> | Meeting Rooms | neet150 | Easy | 0 | [✓](src/cpp/neet150/252.meeting-rooms.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/meeting-rooms-ii/description/" target="_blank">253</a> | Meeting Rooms II | neet150 | Medium | 0 | [✓](src/cpp/neet150/253.meeting-rooms-ii.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/graph-valid-tree/description/" target="_blank">261</a> | Graph Valid Tree | neet150 | Medium | 0 | [✓](src/cpp/neet150/261.graph-valid-tree.cpp) | - | - | - |
| 268 | Missing Number | misc | - | 3 | [✓](src/cpp/neet150/268.missing-number.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/alien-dictionary/description/" target="_blank">269</a> | Alien Dictionary | neet150 | Hard | 0 | [✓](src/cpp/neet150/269.alien-dictionary.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/encode-and-decode-strings/description/" target="_blank">271</a> | Encode and Decode Strings | neet150 | Medium | 0 | [✓](src/cpp/neet150/271.encode-and-decode-strings.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/walls-and-gates/description/" target="_blank">286</a> | Walls And Gates | neet150 | Medium | 0 | [✓](src/cpp/neet150/286.walls-and-gates.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/find-the-duplicate-number/description/" target="_blank">287</a> | Find The Duplicate Number | neet150 | Medium | 0 | [✓](src/cpp/neet150/287.find-the-duplicate-number.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/find-median-from-data-stream/description/" target="_blank">295</a> | Find Median from Data Stream | misc | Hard | 1 | [✓](src/cpp/neet150/295.find-median-from-data-stream.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/" target="_blank">297</a> | Serialize And Deserialize Binary Tree | neet150 | Hard | 0 | [✓](src/cpp/neet150/297.serialize-and-deserialize-binary-tree.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/longest-increasing-subsequence/description/" target="_blank">300</a> | Longest Increasing Subsequence | neet150 | Medium | 0 | [✓](src/cpp/neet150/300.longest-increasing-subsequence.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/range-sum-query-mutable/description/" target="_blank">307</a> | Range Sum Query - Mutable | misc | Medium | 1 | [✓](src/cpp/misc/307.range-sum-query-mutable.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/" target="_blank">309</a> | Best Time to Buy And Sell Stock With Cooldown | neet150 | Medium | 0 | [✓](src/cpp/neet150/309.best-time-to-buy-and-sell-stock-with-cooldown.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/burst-balloons/description/" target="_blank">312</a> | Burst Balloons | neet150 | Hard | 0 | [✓](src/cpp/neet150/312.burst-balloons.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/" target="_blank">315</a> | Count of Smaller Numbers After Self | misc | Hard | 3 | [✓](src/cpp/misc/315.count-of-smaller-numbers-after-self.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/coin-change/description/" target="_blank">322</a> | Coin Change | neet150 | Medium | 0 | [✓](src/cpp/neet150/322.coin-change.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/" target="_blank">323</a> | Number of Connected Components In An Undirected Graph | neet150 | Medium | 0 | [✓](src/cpp/neet150/323.number-of-connected-components-in-an-undirected-graph.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/" target="_blank">329</a> | Longest Increasing Path In a Matrix | neet150 | Hard | 0 | [✓](src/cpp/neet150/329.longest-increasing-path-in-a-matrix.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/reconstruct-itinerary/description/" target="_blank">332</a> | Reconstruct Itinerary | neet150 | Hard | 0 | [✓](src/cpp/neet150/332.reconstruct-itinerary.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/counting-bits/description/" target="_blank">338</a> | Counting Bits | neet150 | Easy | 0 | [✓](src/cpp/neet150/338.counting-bits.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/top-k-frequent-elements/description/" target="_blank">347</a> | Top K Frequent Elements | hash | Medium | 3 | [✓](src/cpp/hash/347.top-k-frequent-elements.cpp) | - | - | [📺](https://www.youtube.com/watch?v=YPTqKIgVk-k) |
| <a href="https://leetcode.com/problems/intersection-of-two-arrays-ii/description/" target="_blank">350</a> | Intersection of Two Arrays II | hash | Easy | 2 | - | - | - | - |
| <a href="https://leetcode.com/problems/design-twitter/description/" target="_blank">355</a> | Design Twitter | neet150 | Medium | 0 | [✓](src/cpp/neet150/355.design-twitter.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/logger-rate-limiter/description/" target="_blank">359</a> | Logger Rate Limiter | hash | Easy | 1 | - | - | - | - |
| <a href="https://leetcode.com/problems/design-hit-counter/description/" target="_blank">362</a> | Design Hit Counter | hash | Medium | 1 | [✓](src/cpp/hash/362.design-hit-counter.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/sum-of-two-integers/description/" target="_blank">371</a> | Sum of Two Integers | neet150 | Medium | 0 | [✓](src/cpp/neet150/371.sum-of-two-integers.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/partition-equal-subset-sum/description/" target="_blank">416</a> | Partition Equal Subset Sum | neet150 | Medium | 0 | [✓](src/cpp/neet150/416.partition-equal-subset-sum.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/pacific-atlantic-water-flow/description/" target="_blank">417</a> | Pacific Atlantic Water Flow | neet150 | Medium | 0 | [✓](src/cpp/neet150/417.pacific-atlantic-water-flow.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/longest-repeating-character-replacement/description/" target="_blank">424</a> | Longest Repeating Character Replacement | sliding_window | Medium | 5 | [✓](src/cpp/sliding_window/424.longest-repeating-character-replacement.cpp) | [✓](src/go/sliding_window/424.longest-repeating-character-replacement.go) | - | [📺](https://www.youtube.com/watch?v=gqXU1UyA8pk) |
| <a href="https://leetcode.com/problems/non-overlapping-intervals/description/" target="_blank">435</a> | Non Overlapping Intervals | neet150 | Medium | 0 | [✓](src/cpp/neet150/435.non-overlapping-intervals.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/find-all-anagrams-in-a-string/description/" target="_blank">438</a> | Find All Anagrams in a String | sliding_window | Medium | 4 | [✓](src/cpp/sliding_window/438.find-all-anagrams-in-a-string.cpp) | [✓](src/go/sliding_window/438.find-all-anagrams-in-a-string.go) | - | [📺](https://www.youtube.com/watch?v=G8xtZy0fDKg) |
| <a href="https://leetcode.com/problems/lfu-cache/description/" target="_blank">460</a> | LFU Cache | misc | Hard | 1 | [✓](src/cpp/misc/460.lfu-cache.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/target-sum/description/" target="_blank">494</a> | Target Sum | neet150 | Medium | 0 | [✓](src/cpp/neet150/494.target-sum.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/coin-change-ii/description/" target="_blank">518</a> | Coin Change II | neet150 | Medium | 0 | [✓](src/cpp/neet150/518.coin-change-ii.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/diameter-of-binary-tree/description/" target="_blank">543</a> | Diameter of Binary Tree | neet150 | Easy | 0 | [✓](src/cpp/neet150/543.diameter-of-binary-tree.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/subarray-sum-equals-k/description/" target="_blank">560</a> | Subarray Sum Equals K | prefix_sum | Medium | 2 | [✓](src/cpp/prefix_sum/560.subarray-sum-equals-k.cpp) | [✓](src/go/prefix_sum/560.subarray-sum-equals-k.go) | - | [📺](https://www.youtube.com/watch?v=HbbYPQc-Oo4) |
| <a href="https://leetcode.com/problems/permutation-in-string/description/" target="_blank">567</a> | Permutation in String | sliding_window | Medium | 5 | [✓](src/cpp/sliding_window/567.permutation-in-string.cpp) | [✓](src/go/sliding_window/567.permutation-in-string.go) | - | [📺](https://www.youtube.com/watch?v=UbyhOgBN834) |
| <a href="https://leetcode.com/problems/subtree-of-another-tree/description/" target="_blank">572</a> | Subtree of Another Tree | neet150 | Easy | 0 | [✓](src/cpp/neet150/572.subtree-of-another-tree.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/task-scheduler/description/" target="_blank">621</a> | Task Scheduler | neet150 | Medium | 0 | [✓](src/cpp/neet150/621.task-scheduler.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/palindromic-substrings/description/" target="_blank">647</a> | Palindromic Substrings | neet150 | Medium | 0 | [✓](src/cpp/neet150/647.palindromic-substrings.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/valid-parenthesis-string/description/" target="_blank">678</a> | Valid Parenthesis String | neet150 | Medium | 0 | [✓](src/cpp/neet150/678.valid-parenthesis-string.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/redundant-connection/description/" target="_blank">684</a> | Redundant Connection | neet150 | Medium | 0 | [✓](src/cpp/neet150/684.redundant-connection.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/max-area-of-island/description/" target="_blank">695</a> | Max Area of Island | neet150 | Medium | 0 | [✓](src/cpp/neet150/695.max-area-of-island.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/kth-largest-element-in-a-stream/description/" target="_blank">703</a> | Kth Largest Element In a Stream | neet150 | Easy | 0 | [✓](src/cpp/neet150/703.kth-largest-element-in-a-stream.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/binary-search/description/" target="_blank">704</a> | Binary Search | neet150 | Easy | 0 | [✓](src/cpp/neet150/704.binary-search.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/daily-temperatures/description/" target="_blank">739</a> | Daily Temperatures | stack | Medium | 6 | [✓](src/cpp/stack/739.daily-temperatures.cpp) | [✓](src/go/stack/739.daily-temperatures.go) | - | [📺](https://www.youtube.com/watch?v=cTBiBSnjO3c) |
| <a href="https://leetcode.com/problems/network-delay-time/description/" target="_blank">743</a> | Network Delay Time | neet150 | Medium | 0 | [✓](src/cpp/neet150/743.network-delay-time.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/min-cost-climbing-stairs/description/" target="_blank">746</a> | Min Cost Climbing Stairs | neet150 | Easy | 0 | [✓](src/cpp/neet150/746.min-cost-climbing-stairs.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/partition-labels/description/" target="_blank">763</a> | Partition Labels | neet150 | Medium | 0 | [✓](src/cpp/neet150/763.partition-labels.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/swim-in-rising-water/description/" target="_blank">778</a> | Swim In Rising Water | neet150 | Hard | 0 | [✓](src/cpp/neet150/778.swim-in-rising-water.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/cheapest-flights-within-k-stops/description/" target="_blank">787</a> | Cheapest Flights Within K Stops | neet150 | Medium | 0 | [✓](src/cpp/neet150/787.cheapest-flights-within-k-stops.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/hand-of-straights/description/" target="_blank">846</a> | Hand of Straights | neet150 | Medium | 0 | [✓](src/cpp/neet150/846.hand-of-straights.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/car-fleet/description/" target="_blank">853</a> | Car Fleet | neet150 | Medium | 0 | [✓](src/cpp/neet150/853.car-fleet.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/koko-eating-bananas/description/" target="_blank">875</a> | Koko Eating Bananas | neet150 | Medium | 0 | [✓](src/cpp/neet150/875.koko-eating-bananas.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/k-closest-points-to-origin/description/" target="_blank">973</a> | K Closest Points to Origin | misc | Medium | 2 | [✓](src/cpp/neet150/973.k-closest-points-to-origin.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/time-based-key-value-store/description/" target="_blank">981</a> | Time Based Key-Value Store | binary_search | Medium | 1 | [✓](src/cpp/binary_search/981.time-based-key-value-store.cpp) | [✓](src/go/binary_search/981.time-based-key-value-store.go) | - | [📺](https://www.youtube.com/watch?v=fu2cD_6E8Hw) |
| <a href="https://leetcode.com/problems/rotting-oranges/description/" target="_blank">994</a> | Rotting Oranges | neet150 | Medium | 0 | [✓](src/cpp/neet150/994.rotting-oranges.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/last-stone-weight/description/" target="_blank">1046</a> | Last Stone Weight | neet150 | Easy | 0 | [✓](src/cpp/neet150/1046.last-stone-weight.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/building-h2o/description/" target="_blank">1117</a> | Building H2O | concurrency | Medium | 6 | [✓](src/cpp/concurrency/1117.building-h2o.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/longest-common-subsequence/description/" target="_blank">1143</a> | Longest Common Subsequence | neet150 | Medium | 0 | [✓](src/cpp/neet150/1143.longest-common-subsequence.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/snapshot-array/description/" target="_blank">1146</a> | Snapshot Array | misc | Medium | 1 | [✓](src/cpp/misc/1146.snapshot-array.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/bounded-blocking-queue/description/" target="_blank">1188</a> | Design Bounded Blocking Queue | concurrency | Medium | 3 | [✓](src/cpp/concurrency/1188.bounded-blocking-queue.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/" target="_blank">1203</a> | Sort Items by Groups Respecting Dependencies | graphs | Hard | 2 | [✓](src/cpp/graphs/1203.sort-items-by-groups-respecting-dependencies.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/" target="_blank">1235</a> | Maximum Profit in Job Scheduling | dp | Hard | 4 | [✓](src/cpp/dp/1235.maximum-profit-in-job-scheduling.cpp) | [✓](src/go/dp/1235.maximum-profit-in-job-scheduling.go) | [✓](src/java/dp/P1235.java) | [📺](https://www.youtube.com/watch?v=JLoWc3v0SiE) |
| <a href="https://leetcode.com/problems/web-crawler-multithreaded/description/" target="_blank">1242</a> | Web Crawler Multithreaded | concurrency | Medium | 1 | [✓](src/cpp/concurrency/1242.web-crawler-multithreaded.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/" target="_blank">1448</a> | Count Good Nodes In Binary Tree | neet150 | Medium | 0 | [✓](src/cpp/neet150/1448.count-good-nodes-in-binary-tree.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/min-cost-to-connect-all-points/description/" target="_blank">1584</a> | Min Cost to Connect All Points | neet150 | Medium | 0 | [✓](src/cpp/neet150/1584.min-cost-to-connect-all-points.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/minimum-interval-to-include-each-query/description/" target="_blank">1851</a> | Minimum Interval to Include Each Query | neet150 | Hard | 0 | [✓](src/cpp/neet150/1851.minimum-interval-to-include-each-query.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/" target="_blank">1899</a> | Merge Triplets to Form Target Triplet | neet150 | Medium | 0 | [✓](src/cpp/neet150/1899.merge-triplets-to-form-target-triplet.cpp) | - | - | - |
| <a href="https://leetcode.com/problems/detect-squares/description/" target="_blank">2013</a> | Detect Squares | neet150 | Medium | 0 | [✓](src/cpp/neet150/2013.detect-squares.cpp) | - | - | - |
| 10000 | Shortest Cycle of a Target Node | graphs | Medium | 3 | [✓](src/cpp/graphs/10000.shortest-cycle-of-target-node.cpp) | - | - | - |

### Filter by Category
- **binary_search**: [33](#33), [35](#35), [981](#981)
- **concurrency**: [1117](#1117), [1188](#1188), [1242](#1242)
- **dp**: [70](#70), [139](#139), [198](#198), [213](#213), [1235](#1235)
- **graphs**: [200](#200), [207](#207), [210](#210), [1203](#1203), [10000](#10000)
- **hash**: [1](#1), [36](#36), [49](#49), [205](#205), [242](#242), [347](#347), [350](#350), [359](#359), [362](#362)
- **list**: [2](#2), [21](#21), [160](#160), [206](#206)
- **misc**: [9](#9), [13](#13), [56](#56), [146](#146), [215](#215), [216](#216), [268](#268), [295](#295), [307](#307), [315](#315), [460](#460), [973](#973), [1146](#1146)
- **neet150**: [4](#4), [5](#5), [7](#7), [10](#10), [17](#17), [19](#19), [22](#22), [23](#23), [25](#25), [39](#39), [40](#40), [43](#43), [45](#45), [46](#46), [48](#48), [50](#50), [51](#51), [53](#53), [54](#54), [55](#55), [57](#57), [62](#62), [66](#66), [72](#72), [73](#73), [74](#74), [78](#78), [79](#79), [84](#84), [90](#90), [91](#91), [97](#97), [105](#105), [115](#115), [121](#121), [124](#124), [125](#125), [127](#127), [128](#128), [130](#130), [131](#131), [133](#133), [134](#134), [136](#136), [138](#138), [141](#141), [143](#143), [150](#150), [152](#152), [153](#153), [155](#155), [167](#167), [190](#190), [191](#191), [202](#202), [208](#208), [211](#211), [212](#212), [217](#217), [230](#230), [235](#235), [239](#239), [252](#252), [253](#253), [261](#261), [269](#269), [271](#271), [286](#286), [287](#287), [297](#297), [300](#300), [309](#309), [312](#312), [322](#322), [323](#323), [329](#329), [332](#332), [338](#338), [355](#355), [371](#371), [416](#416), [417](#417), [435](#435), [494](#494), [518](#518), [543](#543), [572](#572), [621](#621), [647](#647), [678](#678), [684](#684), [695](#695), [703](#703), [704](#704), [743](#743), [746](#746), [763](#763), [778](#778), [787](#787), [846](#846), [853](#853), [875](#875), [994](#994), [1046](#1046), [1143](#1143), [1448](#1448), [1584](#1584), [1851](#1851), [1899](#1899), [2013](#2013)
- **prefix_sum**: [238](#238), [560](#560)
- **sliding_window**: [3](#3), [76](#76), [424](#424), [438](#438), [567](#567)
- **stack**: [20](#20), [739](#739)
- **tree**: [94](#94), [98](#98), [100](#100), [102](#102), [103](#103), [104](#104), [110](#110), [199](#199), [226](#226)
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

**🧪 Test Cases** (2 cases):
1. `{"input": "abcabcbb", "expected": 3}`
2. `{"input": "bbbbb", "expected": 1}`

</details>

<details>
<summary><strong>LC4: Median of Two Sorted Arrays</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/median-of-two-sorted-arrays/

**💻 Solutions**:
- [C++](src/cpp/neet150/4.median-of-two-sorted-arrays.cpp)

</details>

<details>
<summary><strong>LC5: Longest Palindromic Substring</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/longest-palindromic-substring/

**💻 Solutions**:
- [C++](src/cpp/neet150/5.longest-palindromic-substring.cpp)

</details>

<details>
<summary><strong>LC7: Reverse Integer</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/reverse-integer/

**💻 Solutions**:
- [C++](src/cpp/neet150/7.reverse-integer.cpp)

</details>

<details>
<summary><strong>LC9: Palindrome Number</strong> (Easy) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/palindrome-number/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=f5qF2OowB5A

**💻 Solutions**:
- [C++](src/cpp/misc/9.palindrome-number.cpp)
- [Go](src/go/misc/9.palindrome-number.go)

**🧪 Test Cases** (6 cases):
1. `{"input": 121, "expected": True}`
2. `{"input": -121, "expected": False}`
3. `{"input": 10, "expected": False}`
   ... and 3 more cases

</details>

<details>
<summary><strong>LC10: Regular Expression Matching</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/regular-expression-matching/

**💻 Solutions**:
- [C++](src/cpp/neet150/10.regular-expression-matching.cpp)

</details>

<details>
<summary><strong>LC11: Container With Most Water</strong> (Medium) - two_pointer</summary>

**🔗 Problem Link**: https://leetcode.com/problems/container-with-most-water/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=UuiTKBwPgAo

**💻 Solutions**:
- [C++](src/cpp/two_pointer/11.container-with-most-water.cpp)
- [Go](src/go/two_pointer/11.container-with-most-water.go)

**🧪 Test Cases** (9 cases):
1. `{"input": [8, 7, 2, 2], "expected": 7}`
2. `{"input": [1, 8, 6, 2, 5, 4, 8, 3, 7], "expected": 49}`
3. `{"input": [1, 1], "expected": 1}`
   ... and 6 more cases

</details>

<details>
<summary><strong>LC13: Roman to Integer</strong> (Easy) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/roman-to-integer/

**💻 Solutions**:

**🧪 Test Cases** (3 cases):
1. `{"s": "III", "expected": 3}`
2. `{"s": "LVIII", "expected": 58}`
3. `{"s": "MCMXCIV", "expected": 1994}`

</details>

<details>
<summary><strong>LC15: 3Sum</strong> (Medium) - two_pointer</summary>

**🔗 Problem Link**: https://leetcode.com/problems/3sum/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=jzZsG8n2R9A

**💻 Solutions**:
- [C++](src/cpp/two_pointer/15.3-sum.cpp)
- [Go](src/go/two_pointer/15.3-sum.go)

**🧪 Test Cases** (4 cases):
1. `{"nums": [-1, 0, 1, 2, -1, -4], "expected": [[-1, -1, 2], [-1, 0, 1]]}`
2. `{"nums": [0, 1, 1], "expected": []}`
3. `{"nums": [0, 0, 0], "expected": [[0, 0, 0]]}`
   ... and 1 more cases

</details>

<details>
<summary><strong>LC17: Letter Combinations of a Phone Number</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

**💻 Solutions**:
- [C++](src/cpp/neet150/17.letter-combinations-of-a-phone-number.cpp)

</details>

<details>
<summary><strong>LC19: Remove Nth Node From End of List</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

**💻 Solutions**:
- [C++](src/cpp/neet150/19.remove-nth-node-from-end-of-list.cpp)

</details>

<details>
<summary><strong>LC20: Valid Parentheses</strong> (Easy) - stack</summary>

**🔗 Problem Link**: https://leetcode.com/problems/valid-parentheses/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=WTzjTskDFMg

**💻 Solutions**:
- [C++](src/cpp/stack/20.valid-parentheses.cpp)
- [Go](src/go/stack/20.valid-parentheses.go)

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

**🧪 Test Cases** (7 cases):
1. `{"l1": [1, 2, 4], "l2": [1, 3, 4], "expected": [1, 1, 2, 3, 4, 4]}`
2. `{"l1": [], "l2": [], "expected": []}`
3. `{"l1": [], "l2": [0], "expected": [0]}`
   ... and 4 more cases

</details>

<details>
<summary><strong>LC22: Generate Parentheses</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/generate-parentheses/

**💻 Solutions**:
- [C++](src/cpp/neet150/22.generate-parentheses.cpp)

</details>

<details>
<summary><strong>LC23: Merge K Sorted Lists</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/merge-k-sorted-lists/

**💻 Solutions**:
- [C++](src/cpp/neet150/23.merge-k-sorted-lists.cpp)

</details>

<details>
<summary><strong>LC25: Reverse Nodes In K Group</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/reverse-nodes-in-k-group/

**💻 Solutions**:
- [C++](src/cpp/neet150/25.reverse-nodes-in-k-group.cpp)

</details>

<details>
<summary><strong>LC33: Search in Rotated Sorted Array</strong> (Medium) - binary_search</summary>

**🔗 Problem Link**: https://leetcode.com/problems/search-in-rotated-sorted-array/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=U8XENwh8Oy8

**💻 Solutions**:
- [C++](src/cpp/binary_search/33.search-in-rotated-sorted-array.cpp)
- [Go](src/go/binary_search/33.search-in-rotated-sorted-array.go)

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

**🧪 Test Cases** (2 cases):
1. `{"board": [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "...`
2. `{"board": [["8", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "...`

</details>

<details>
<summary><strong>LC39: Combination Sum</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/combination-sum/

**💻 Solutions**:
- [C++](src/cpp/neet150/39.combination-sum.cpp)

</details>

<details>
<summary><strong>LC40: Combination Sum II</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/combination-sum-ii/

**💻 Solutions**:
- [C++](src/cpp/neet150/40.combination-sum-ii.cpp)

</details>

<details>
<summary><strong>LC42: Trapping Rain Water</strong> (Hard) - two_pointer</summary>

**🔗 Problem Link**: https://leetcode.com/problems/trapping-rain-water/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=ZI2z5pq0TqA

**💻 Solutions**:
- [C++](src/cpp/two_pointer/42.trapping-rain-water.cpp)
- [Go](src/go/two_pointer/42.trapping-rain-water.go)

**🧪 Test Cases** (6 cases):
1. `{"input": [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], "expected": 6}`
2. `{"input": [4, 2, 0, 3, 2, 5], "expected": 9}`
3. `{"input": [1, 2, 3, 4, 5], "expected": 0}`
   ... and 3 more cases

</details>

<details>
<summary><strong>LC43: Multiply Strings</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/multiply-strings/

**💻 Solutions**:
- [C++](src/cpp/neet150/43.multiply-strings.cpp)

</details>

<details>
<summary><strong>LC45: Jump Game II</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/jump-game-ii/

**💻 Solutions**:
- [C++](src/cpp/neet150/45.jump-game-ii.cpp)

</details>

<details>
<summary><strong>LC46: Permutations</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/permutations/

**💻 Solutions**:
- [C++](src/cpp/neet150/46.permutations.cpp)

</details>

<details>
<summary><strong>LC48: Rotate Image</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/rotate-image/

**💻 Solutions**:
- [C++](src/cpp/neet150/48.rotate-image.cpp)

</details>

<details>
<summary><strong>LC49: Group Anagrams</strong> (Medium) - hash</summary>

**💻 Solutions**:
- [C++](src/cpp/neet150/49.group-anagrams.cpp)

**🧪 Test Cases** (3 cases):
1. `{"strs": ["eat", "tea", "tan", "ate", "nat", "bat"], "expected": [["bat"], ["nat", "tan"], ["ate", "...`
2. `{"strs": [""], "expected": [[""]]}`
3. `{"strs": ["a"], "expected": [["a"]]}`

</details>

<details>
<summary><strong>LC50: Pow(x, n)</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/powx-n/

**💻 Solutions**:
- [C++](src/cpp/neet150/50.powx-n.cpp)

</details>

<details>
<summary><strong>LC51: N Queens</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/n-queens/

**💻 Solutions**:
- [C++](src/cpp/neet150/51.n-queens.cpp)

</details>

<details>
<summary><strong>LC53: Maximum Subarray</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/maximum-subarray/

**💻 Solutions**:
- [C++](src/cpp/neet150/53.maximum-subarray.cpp)

</details>

<details>
<summary><strong>LC54: Spiral Matrix</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/spiral-matrix/

**💻 Solutions**:
- [C++](src/cpp/neet150/54.spiral-matrix.cpp)

</details>

<details>
<summary><strong>LC55: Jump Game</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/jump-game/

**💻 Solutions**:
- [C++](src/cpp/neet150/55.jump-game.cpp)

</details>

<details>
<summary><strong>LC56: Merge Intervals</strong> (Medium) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/merge-intervals/

**💻 Solutions**:
- [C++](src/cpp/misc/56.merge-intervals.cpp)

**🧪 Test Cases** (3 cases):
1. `{"input": [[1, 3], [2, 6], [8, 10], [15, 18]], "expected": [[1, 6], [8, 10], [15, 18]]}`
2. `{"input": [[1, 4], [4, 5]], "expected": [[1, 5]]}`
3. `{"input": [[1, 4], [5, 6]], "expected": [[1, 4], [5, 6]]}`

</details>

<details>
<summary><strong>LC57: Insert Interval</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/insert-interval/

**💻 Solutions**:
- [C++](src/cpp/neet150/57.insert-interval.cpp)

</details>

<details>
<summary><strong>LC62: Unique Paths</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/unique-paths/

**💻 Solutions**:
- [C++](src/cpp/neet150/62.unique-paths.cpp)

</details>

<details>
<summary><strong>LC66: Plus One</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/plus-one/

**💻 Solutions**:
- [C++](src/cpp/neet150/66.plus-one.cpp)

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
1. `{"n": 2, "expected": 2}`
2. `{"n": 3, "expected": 3}`
3. `{"n": 1, "expected": 1}`
   ... and 4 more cases

</details>

<details>
<summary><strong>LC72: Edit Distance</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/edit-distance/

**💻 Solutions**:
- [C++](src/cpp/neet150/72.edit-distance.cpp)

</details>

<details>
<summary><strong>LC73: Set Matrix Zeroes</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/set-matrix-zeroes/

**💻 Solutions**:
- [C++](src/cpp/neet150/73.set-matrix-zeroes.cpp)

</details>

<details>
<summary><strong>LC74: Search a 2D Matrix</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/search-a-2d-matrix/

**💻 Solutions**:
- [C++](src/cpp/neet150/74.search-a-2d-matrix.cpp)

</details>

<details>
<summary><strong>LC76: Minimum Window Substring</strong> (-) - sliding_window</summary>

**💻 Solutions**:
- [C++](src/cpp/sliding_window/76.minimum-window-substring.cpp)

**🧪 Test Cases** (3 cases):
1. `{"s": "ADOBECODEBANC", "t": "ABC", "expected": "BANC"}`
2. `{"s": "a", "t": "a", "expected": "a"}`
3. `{"s": "a", "t": "aa", "expected": ""}`

</details>

<details>
<summary><strong>LC78: Subsets</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/subsets/

**💻 Solutions**:
- [C++](src/cpp/neet150/78.subsets.cpp)

</details>

<details>
<summary><strong>LC79: Word Search</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/word-search/

**💻 Solutions**:
- [C++](src/cpp/neet150/79.word-search.cpp)

</details>

<details>
<summary><strong>LC84: Largest Rectangle In Histogram</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/largest-rectangle-in-histogram/

**💻 Solutions**:
- [C++](src/cpp/neet150/84.largest-rectangle-in-histogram.cpp)

</details>

<details>
<summary><strong>LC90: Subsets II</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/subsets-ii/

**💻 Solutions**:
- [C++](src/cpp/neet150/90.subsets-ii.cpp)

</details>

<details>
<summary><strong>LC91: Decode Ways</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/decode-ways/

**💻 Solutions**:
- [C++](src/cpp/neet150/91.decode-ways.cpp)

</details>

<details>
<summary><strong>LC94: Binary Tree Inorder Traversal</strong> (Easy) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/binary-tree-inorder-traversal/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=g_S5WuasWUE

**💻 Solutions**:
- [C++](src/cpp/tree/94.binary-tree-inorder-traversal.cpp)
- [Go](src/go/tree/94.binary-tree-inorder-traversal.go)

**🧪 Test Cases** (5 cases):
1. `{"tree": [1, None, 2, 3], "expected": [1, 3, 2]}`
2. `{"tree": [], "expected": []}`
3. `{"tree": [1], "expected": [1]}`
   ... and 2 more cases

</details>

<details>
<summary><strong>LC97: Interleaving String</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/interleaving-string/

**💻 Solutions**:
- [C++](src/cpp/neet150/97.interleaving-string.cpp)

</details>

<details>
<summary><strong>LC98: Validate Binary Search Tree</strong> (Medium) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/validate-binary-search-tree/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=s6ATEkipzow

**💻 Solutions**:
- [C++](src/cpp/tree/98.validate-binary-search-tree.cpp)
- [Go](src/go/tree/98.validate-binary-search-tree.go)

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

**🧪 Test Cases** (8 cases):
1. `{"tree": [3, 9, 20, None, None, 15, 7], "expected": 3}`
2. `{"tree": [], "expected": 0}`
3. `{"tree": [1], "expected": 1}`
   ... and 5 more cases

</details>

<details>
<summary><strong>LC105: Construct Binary Tree From Preorder And Inorder Traversal</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

**💻 Solutions**:
- [C++](src/cpp/neet150/105.construct-binary-tree-from-preorder-and-inorder-traversal.cpp)

</details>

<details>
<summary><strong>LC110: Balanced Binary Tree</strong> (Easy) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/balanced-binary-tree/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=QfJsau0ItOY

**💻 Solutions**:
- [C++](src/cpp/tree/110.balanced-binary-tree.cpp)
- [Go](src/go/tree/110.balanced-binary-tree.go)

**🧪 Test Cases** (8 cases):
1. `{"tree": [3, 9, 20, None, None, 15, 7], "expected": True}`
2. `{"tree": [], "expected": True}`
3. `{"tree": [1], "expected": True}`
   ... and 5 more cases

</details>

<details>
<summary><strong>LC115: Distinct Subsequences</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/distinct-subsequences/

**💻 Solutions**:
- [C++](src/cpp/neet150/115.distinct-subsequences.cpp)

</details>

<details>
<summary><strong>LC121: Best Time to Buy And Sell Stock</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

**💻 Solutions**:
- [C++](src/cpp/neet150/121.best-time-to-buy-and-sell-stock.cpp)

</details>

<details>
<summary><strong>LC124: Binary Tree Maximum Path Sum</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/binary-tree-maximum-path-sum/

**💻 Solutions**:
- [C++](src/cpp/neet150/124.binary-tree-maximum-path-sum.cpp)

</details>

<details>
<summary><strong>LC125: Valid Palindrome</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/valid-palindrome/

**💻 Solutions**:
- [C++](src/cpp/neet150/125.valid-palindrome.cpp)

</details>

<details>
<summary><strong>LC127: Word Ladder</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/word-ladder/

**💻 Solutions**:
- [C++](src/cpp/neet150/127.word-ladder.cpp)

</details>

<details>
<summary><strong>LC128: Longest Consecutive Sequence</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/longest-consecutive-sequence/

**💻 Solutions**:
- [C++](src/cpp/neet150/128.longest-consecutive-sequence.cpp)

</details>

<details>
<summary><strong>LC130: Surrounded Regions</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/surrounded-regions/

**💻 Solutions**:
- [C++](src/cpp/neet150/130.surrounded-regions.cpp)

</details>

<details>
<summary><strong>LC131: Palindrome Partitioning</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/palindrome-partitioning/

**💻 Solutions**:
- [C++](src/cpp/neet150/131.palindrome-partitioning.cpp)

</details>

<details>
<summary><strong>LC133: Clone Graph</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/clone-graph/

**💻 Solutions**:
- [C++](src/cpp/neet150/133.clone-graph.cpp)

</details>

<details>
<summary><strong>LC134: Gas Station</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/gas-station/

**💻 Solutions**:
- [C++](src/cpp/neet150/134.gas-station.cpp)

</details>

<details>
<summary><strong>LC136: Single Number</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/single-number/

**💻 Solutions**:
- [C++](src/cpp/neet150/136.single-number.cpp)

</details>

<details>
<summary><strong>LC138: Copy List With Random Pointer</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/copy-list-with-random-pointer/

**💻 Solutions**:
- [C++](src/cpp/neet150/138.copy-list-with-random-pointer.cpp)

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
<summary><strong>LC141: Linked List Cycle</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/linked-list-cycle/

**💻 Solutions**:
- [C++](src/cpp/neet150/141.linked-list-cycle.cpp)

</details>

<details>
<summary><strong>LC143: Reorder List</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/reorder-list/

**💻 Solutions**:
- [C++](src/cpp/neet150/143.reorder-list.cpp)

</details>

<details>
<summary><strong>LC146: LRU Cache</strong> (Medium) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/lru-cache/

**💻 Solutions**:
- [C++](src/cpp/neet150/146.lru-cache.cpp)

**🧪 Test Cases** (2 cases):
1. `{"commands": ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"], "arguments...`
2. `{"commands": ["LRUCache", "put", "put", "get", "put", "put", "get"], "arguments": [[2], [2, 1], [2, ...`

</details>

<details>
<summary><strong>LC150: Evaluate Reverse Polish Notation</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/evaluate-reverse-polish-notation/

**💻 Solutions**:
- [C++](src/cpp/neet150/150.evaluate-reverse-polish-notation.cpp)

</details>

<details>
<summary><strong>LC152: Maximum Product Subarray</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/maximum-product-subarray/

**💻 Solutions**:
- [C++](src/cpp/neet150/152.maximum-product-subarray.cpp)

</details>

<details>
<summary><strong>LC153: Find Minimum In Rotated Sorted Array</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

**💻 Solutions**:
- [C++](src/cpp/neet150/153.find-minimum-in-rotated-sorted-array.cpp)

</details>

<details>
<summary><strong>LC155: Min Stack</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/min-stack/

**💻 Solutions**:
- [C++](src/cpp/neet150/155.min-stack.cpp)

</details>

<details>
<summary><strong>LC160: Intersection of Two Linked Lists</strong> (Easy) - list</summary>

**🔗 Problem Link**: https://leetcode.com/problems/intersection-of-two-linked-lists/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=D0X0BONOQhI

**💻 Solutions**:
- [C++](src/cpp/list/160.intersection-of-two-linked-lists.cpp)
- [Go](src/go/list/160.intersection-of-two-linked-lists.go)

**🧪 Test Cases** (3 cases):
1. `{"listA": [4, 1, 8, 4, 5], "listB": [5, 6, 1, 8, 4, 5], "intersectVal": 8, "skipA": 2, "skipB": 3, "...`
2. `{"listA": [1, 9, 1, 2, 4], "listB": [3, 2, 4], "intersectVal": 2, "skipA": 3, "skipB": 1, "expected"...`
3. `{"listA": [2, 6, 4], "listB": [1, 5], "intersectVal": 0, "skipA": 3, "skipB": 2, "expected": None}`

</details>

<details>
<summary><strong>LC167: Two Sum II Input Array Is Sorted</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

**💻 Solutions**:
- [C++](src/cpp/neet150/167.two-sum-ii-input-array-is-sorted.cpp)

</details>

<details>
<summary><strong>LC190: Reverse Bits</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/reverse-bits/

**💻 Solutions**:
- [C++](src/cpp/neet150/190.reverse-bits.cpp)

</details>

<details>
<summary><strong>LC191: Number of 1 Bits</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/number-of-1-bits/

**💻 Solutions**:
- [C++](src/cpp/neet150/191.number-of-1-bits.cpp)

</details>

<details>
<summary><strong>LC198: House Robber</strong> (Medium) - dp</summary>

**🔗 Problem Link**: https://leetcode.com/problems/house-robber/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=73r3KWiEvyk

**💻 Solutions**:
- [C++](src/cpp/dp/198.house-robber.cpp)
- [Go](src/go/dp/198.house-robber.go)
- [Java](src/java/dp/P198.java)

**🧪 Test Cases** (8 cases):
1. `{"nums": [1], "expected": 1}`
2. `{"nums": [2, 1], "expected": 2}`
3. `{"nums": [1, 2], "expected": 2}`
   ... and 5 more cases

</details>

<details>
<summary><strong>LC199: Binary Tree Right Side View</strong> (Medium) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/binary-tree-right-side-view/

**💻 Solutions**:
- [C++](src/cpp/neet150/199.binary-tree-right-side-view.cpp)

**🧪 Test Cases** (3 cases):
1. `{"tree": [1, 2, 3, None, 5, None, 4], "expected": [1, 3, 4]}`
2. `{"tree": [1, None, 3], "expected": [1, 3]}`
3. `{"tree": [], "expected": []}`

</details>

<details>
<summary><strong>LC200: Number of Islands</strong> (Medium) - graphs</summary>

**🔗 Problem Link**: https://leetcode.com/problems/number-of-islands/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=pV2kpPD66nE

**💻 Solutions**:
- [C++](src/cpp/graphs/200.number-of-islands.cpp)
- [Go](src/go/graphs/200.number-of-islands.go)

**🧪 Test Cases** (2 cases):
1. `{"grid": [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"], ["1", "1", "0", "0", "0"], ["0", "0"...`
2. `{"grid": [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "1", "0", "0"], ["0", "0"...`

</details>

<details>
<summary><strong>LC202: Happy Number</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/happy-number/

**💻 Solutions**:
- [C++](src/cpp/neet150/202.happy-number.cpp)

</details>

<details>
<summary><strong>LC205: Isomorphic Strings</strong> (Easy) - hash</summary>

**🔗 Problem Link**: https://leetcode.com/problems/isomorphic-strings/

**💻 Solutions**:

**🧪 Test Cases** (3 cases):
1. `{"s": "egg", "t": "add", "expected": True}`
2. `{"s": "foo", "t": "bar", "expected": False}`
3. `{"s": "paper", "t": "title", "expected": True}`

</details>

<details>
<summary><strong>LC206: Reverse Linked List</strong> (Easy) - list</summary>

**🔗 Problem Link**: https://leetcode.com/problems/reverse-linked-list/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=G0_I-ZF0S38

**💻 Solutions**:
- [C++](src/cpp/list/206.reverse-linked-list.cpp)
- [Go](src/go/list/206.reverse-linked-list.go)

**🧪 Test Cases** (3 cases):
1. `{"head": [1, 2, 3, 4, 5], "expected": [5, 4, 3, 2, 1]}`
2. `{"head": [1, 2], "expected": [2, 1]}`
3. `{"head": [], "expected": []}`

</details>

<details>
<summary><strong>LC207: Course Schedule</strong> (Medium) - graphs</summary>

**🔗 Problem Link**: https://leetcode.com/problems/course-schedule/

**💻 Solutions**:
- [C++](src/cpp/neet150/207.course-schedule.cpp)

**🧪 Test Cases** (3 cases):
1. `{"numCourses": 5, "prerequisites": [[1, 0], [2, 0], [3, 1], [3, 2], [4, 3]], "expected": True}`
2. `{"numCourses": 2, "prerequisites": [[1, 0]], "expected": True}`
3. `{"numCourses": 2, "prerequisites": [[1, 0], [0, 1]], "expected": False}`

</details>

<details>
<summary><strong>LC208: Implement Trie Prefix Tree</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/implement-trie-prefix-tree/

**💻 Solutions**:
- [C++](src/cpp/neet150/208.implement-trie-prefix-tree.cpp)

</details>

<details>
<summary><strong>LC210: Course Schedule II</strong> (Medium) - graphs</summary>

**🔗 Problem Link**: https://leetcode.com/problems/course-schedule-ii/

**💻 Solutions**:
- [C++](src/cpp/neet150/210.course-schedule-ii.cpp)

**🧪 Test Cases** (4 cases):
1. `{"numCourses": 2, "prerequisites": [[1, 0]], "expected": [0, 1]}`
2. `{"numCourses": 4, "prerequisites": [[1, 0], [2, 0], [3, 1], [3, 2]], "expected": [0, 1, 2, 3]}`
3. `{"numCourses": 1, "prerequisites": [], "expected": [0]}`
   ... and 1 more cases

</details>

<details>
<summary><strong>LC211: Design Add And Search Words Data Structure</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/design-add-and-search-words-data-structure/

**💻 Solutions**:
- [C++](src/cpp/neet150/211.design-add-and-search-words-data-structure.cpp)

</details>

<details>
<summary><strong>LC212: Word Search II</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/word-search-ii/

**💻 Solutions**:
- [C++](src/cpp/neet150/212.word-search-ii.cpp)

</details>

<details>
<summary><strong>LC213: House Robber II</strong> (Medium) - dp</summary>

**🔗 Problem Link**: https://leetcode.com/problems/house-robber-ii/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=rWAJCfYYOvM

**💻 Solutions**:
- [C++](src/cpp/neet150/213.house-robber-ii.cpp)
- [Go](src/go/dp/213.house-robber-ii.go)
- [Java](src/java/dp/P213.java)

**🧪 Test Cases** (7 cases):
1. `{"nums": [2, 3, 2], "expected": 3}`
2. `{"nums": [1, 2, 3, 1], "expected": 4}`
3. `{"nums": [1, 2, 3], "expected": 3}`
   ... and 4 more cases

</details>

<details>
<summary><strong>LC215: Kth Largest Element in an Array</strong> (Medium) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/kth-largest-element-in-an-array/

**💻 Solutions**:
- [C++](src/cpp/misc/215.kth-largest-element-in-an-array.cpp)

**🧪 Test Cases** (2 cases):
1. `{"nums": [3, 2, 1, 5, 6, 4], "k": 2, "expected": 5}`
2. `{"nums": [3, 2, 3, 1, 2, 4, 5, 5, 6], "k": 4, "expected": 4}`

</details>

<details>
<summary><strong>LC216: Kth Smallest Element in an Array</strong> (Medium) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/kth-smallest-element-in-an-array/

**💻 Solutions**:
- [C++](src/cpp/misc/216.kth-smallest-element-in-an-array.cpp)

**🧪 Test Cases** (2 cases):
1. `{"nums": [3, 2, 1, 5, 6, 4], "k": 2, "expected": 2}`
2. `{"nums": [3, 2, 3, 1, 2, 4, 5, 5, 6], "k": 4, "expected": 3}`

</details>

<details>
<summary><strong>LC217: Contains Duplicate</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/contains-duplicate/

**💻 Solutions**:
- [C++](src/cpp/neet150/217.contains-duplicate.cpp)

</details>

<details>
<summary><strong>LC226: Invert Binary Tree</strong> (Easy) - tree</summary>

**🔗 Problem Link**: https://leetcode.com/problems/invert-binary-tree/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=OnSn2XEQ4MY

**💻 Solutions**:
- [C++](src/cpp/tree/226.invert-binary-tree.cpp)
- [Go](src/go/tree/226.invert-binary-tree.go)

**🧪 Test Cases** (3 cases):
1. `{"root": [4, 2, 7, 1, 3, 6, 9], "expected": [4, 7, 2, 9, 6, 3, 1]}`
2. `{"root": [2, 1, 3], "expected": [2, 3, 1]}`
3. `{"root": [], "expected": []}`

</details>

<details>
<summary><strong>LC230: Kth Smallest Element In a Bst</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

**💻 Solutions**:
- [C++](src/cpp/neet150/230.kth-smallest-element-in-a-bst.cpp)

</details>

<details>
<summary><strong>LC235: Lowest Common Ancestor of a Binary Search Tree</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

**💻 Solutions**:
- [C++](src/cpp/neet150/235.lowest-common-ancestor-of-a-binary-search-tree.cpp)

</details>

<details>
<summary><strong>LC238: Product of Array Except Self</strong> (Medium) - prefix_sum</summary>

**🔗 Problem Link**: https://leetcode.com/problems/product-of-array-except-self/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=bNvIQI2wAjk

**💻 Solutions**:
- [C++](src/cpp/prefix_sum/238.product-of-array-except-self.cpp)
- [Go](src/go/prefix_sum/238.product-of-array-except-self.go)

**🧪 Test Cases** (2 cases):
1. `{"nums": [1, 2, 3, 4], "expected": [24, 12, 8, 6]}`
2. `{"nums": [-1, 1, 0, -3, 3], "expected": [0, 0, 9, 0, 0]}`

</details>

<details>
<summary><strong>LC239: Sliding Window Maximum</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/sliding-window-maximum/

**💻 Solutions**:
- [C++](src/cpp/neet150/239.sliding-window-maximum.cpp)

</details>

<details>
<summary><strong>LC242: Valid Anagram</strong> (Easy) - hash</summary>

**🔗 Problem Link**: https://leetcode.com/problems/valid-anagram/

**💻 Solutions**:
- [C++](src/cpp/neet150/242.valid-anagram.cpp)

**🧪 Test Cases** (2 cases):
1. `{"s": "anagram", "t": "nagaram", "expected": True}`
2. `{"s": "rat", "t": "car", "expected": False}`

</details>

<details>
<summary><strong>LC252: Meeting Rooms</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/meeting-rooms/

**💻 Solutions**:
- [C++](src/cpp/neet150/252.meeting-rooms.cpp)

</details>

<details>
<summary><strong>LC253: Meeting Rooms II</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/meeting-rooms-ii/

**💻 Solutions**:
- [C++](src/cpp/neet150/253.meeting-rooms-ii.cpp)

</details>

<details>
<summary><strong>LC261: Graph Valid Tree</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/graph-valid-tree/

**💻 Solutions**:
- [C++](src/cpp/neet150/261.graph-valid-tree.cpp)

</details>

<details>
<summary><strong>LC268: Missing Number</strong> (-) - misc</summary>

**💻 Solutions**:
- [C++](src/cpp/neet150/268.missing-number.cpp)

**🧪 Test Cases** (3 cases):
1. `{"nums": [3, 0, 1], "expected": 2}`
2. `{"nums": [0, 1], "expected": 2}`
3. `{"nums": [9, 6, 4, 2, 3, 5, 7, 0, 1], "expected": 8}`

</details>

<details>
<summary><strong>LC269: Alien Dictionary</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/alien-dictionary/

**💻 Solutions**:
- [C++](src/cpp/neet150/269.alien-dictionary.cpp)

</details>

<details>
<summary><strong>LC271: Encode and Decode Strings</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/encode-and-decode-strings/

**💻 Solutions**:
- [C++](src/cpp/neet150/271.encode-and-decode-strings.cpp)

</details>

<details>
<summary><strong>LC286: Walls And Gates</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/walls-and-gates/

**💻 Solutions**:
- [C++](src/cpp/neet150/286.walls-and-gates.cpp)

</details>

<details>
<summary><strong>LC287: Find The Duplicate Number</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/find-the-duplicate-number/

**💻 Solutions**:
- [C++](src/cpp/neet150/287.find-the-duplicate-number.cpp)

</details>

<details>
<summary><strong>LC295: Find Median from Data Stream</strong> (Hard) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/find-median-from-data-stream/

**💻 Solutions**:
- [C++](src/cpp/neet150/295.find-median-from-data-stream.cpp)

**🧪 Test Cases** (1 cases):
1. `{"commands": ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"], "arguments"...`

</details>

<details>
<summary><strong>LC297: Serialize And Deserialize Binary Tree</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

**💻 Solutions**:
- [C++](src/cpp/neet150/297.serialize-and-deserialize-binary-tree.cpp)

</details>

<details>
<summary><strong>LC300: Longest Increasing Subsequence</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/longest-increasing-subsequence/

**💻 Solutions**:
- [C++](src/cpp/neet150/300.longest-increasing-subsequence.cpp)

</details>

<details>
<summary><strong>LC307: Range Sum Query - Mutable</strong> (Medium) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/range-sum-query-mutable/

**💻 Solutions**:
- [C++](src/cpp/misc/307.range-sum-query-mutable.cpp)

**🧪 Test Cases** (1 cases):
1. `{"commands": ["NumArray", "sumRange", "update", "sumRange"], "arguments": [[[1, 3, 5]], [0, 2], [1, ...`

</details>

<details>
<summary><strong>LC309: Best Time to Buy And Sell Stock With Cooldown</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

**💻 Solutions**:
- [C++](src/cpp/neet150/309.best-time-to-buy-and-sell-stock-with-cooldown.cpp)

</details>

<details>
<summary><strong>LC312: Burst Balloons</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/burst-balloons/

**💻 Solutions**:
- [C++](src/cpp/neet150/312.burst-balloons.cpp)

</details>

<details>
<summary><strong>LC315: Count of Smaller Numbers After Self</strong> (Hard) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

**💻 Solutions**:
- [C++](src/cpp/misc/315.count-of-smaller-numbers-after-self.cpp)

**🧪 Test Cases** (3 cases):
1. `{"nums": [5, 2, 6, 1], "expected": [2, 1, 1, 0]}`
2. `{"nums": [-1], "expected": [0]}`
3. `{"nums": [-1, -1], "expected": [0, 0]}`

</details>

<details>
<summary><strong>LC322: Coin Change</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/coin-change/

**💻 Solutions**:
- [C++](src/cpp/neet150/322.coin-change.cpp)

</details>

<details>
<summary><strong>LC323: Number of Connected Components In An Undirected Graph</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

**💻 Solutions**:
- [C++](src/cpp/neet150/323.number-of-connected-components-in-an-undirected-graph.cpp)

</details>

<details>
<summary><strong>LC329: Longest Increasing Path In a Matrix</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

**💻 Solutions**:
- [C++](src/cpp/neet150/329.longest-increasing-path-in-a-matrix.cpp)

</details>

<details>
<summary><strong>LC332: Reconstruct Itinerary</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/reconstruct-itinerary/

**💻 Solutions**:
- [C++](src/cpp/neet150/332.reconstruct-itinerary.cpp)

</details>

<details>
<summary><strong>LC338: Counting Bits</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/counting-bits/

**💻 Solutions**:
- [C++](src/cpp/neet150/338.counting-bits.cpp)

</details>

<details>
<summary><strong>LC347: Top K Frequent Elements</strong> (Medium) - hash</summary>

**🔗 Problem Link**: https://leetcode.com/problems/top-k-frequent-elements/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=YPTqKIgVk-k

**💻 Solutions**:
- [C++](src/cpp/hash/347.top-k-frequent-elements.cpp)

**🧪 Test Cases** (3 cases):
1. `{"nums": [1, 1, 1, 2, 2, 3], "k": 2, "expected": [1, 2]}`
2. `{"nums": [1], "k": 1, "expected": [1]}`
3. `{"nums": [4, 1, -1, 2, -1, 2, 3], "k": 2, "expected": [-1, 2]}`

</details>

<details>
<summary><strong>LC350: Intersection of Two Arrays II</strong> (Easy) - hash</summary>

**🔗 Problem Link**: https://leetcode.com/problems/intersection-of-two-arrays-ii/

**💻 Solutions**:

**🧪 Test Cases** (2 cases):
1. `{"nums1": [1, 2, 2, 1], "nums2": [2, 2], "expected": [2, 2]}`
2. `{"nums1": [4, 9, 5], "nums2": [9, 4, 9, 8, 4], "expected": [4, 9]}`

</details>

<details>
<summary><strong>LC355: Design Twitter</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/design-twitter/

**💻 Solutions**:
- [C++](src/cpp/neet150/355.design-twitter.cpp)

</details>

<details>
<summary><strong>LC359: Logger Rate Limiter</strong> (Easy) - hash</summary>

**🔗 Problem Link**: https://leetcode.com/problems/logger-rate-limiter/

**💻 Solutions**:

**🧪 Test Cases** (1 cases):
1. `{"commands": ["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPri...`

</details>

<details>
<summary><strong>LC362: Design Hit Counter</strong> (Medium) - hash</summary>

**🔗 Problem Link**: https://leetcode.com/problems/design-hit-counter/

**💻 Solutions**:
- [C++](src/cpp/hash/362.design-hit-counter.cpp)

**🧪 Test Cases** (1 cases):
1. `{"commands": ["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"], "args": [[...`

</details>

<details>
<summary><strong>LC371: Sum of Two Integers</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/sum-of-two-integers/

**💻 Solutions**:
- [C++](src/cpp/neet150/371.sum-of-two-integers.cpp)

</details>

<details>
<summary><strong>LC416: Partition Equal Subset Sum</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/partition-equal-subset-sum/

**💻 Solutions**:
- [C++](src/cpp/neet150/416.partition-equal-subset-sum.cpp)

</details>

<details>
<summary><strong>LC417: Pacific Atlantic Water Flow</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/pacific-atlantic-water-flow/

**💻 Solutions**:
- [C++](src/cpp/neet150/417.pacific-atlantic-water-flow.cpp)

</details>

<details>
<summary><strong>LC424: Longest Repeating Character Replacement</strong> (Medium) - sliding_window</summary>

**🔗 Problem Link**: https://leetcode.com/problems/longest-repeating-character-replacement/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=gqXU1UyA8pk

**💻 Solutions**:
- [C++](src/cpp/sliding_window/424.longest-repeating-character-replacement.cpp)
- [Go](src/go/sliding_window/424.longest-repeating-character-replacement.go)

**🧪 Test Cases** (5 cases):
1. `{"input": "AABABBA", "k": 1, "expected": 4}`
2. `{"input": "ABAB", "k": 2, "expected": 4}`
3. `{"input": "AAAA", "k": 2, "expected": 4}`
   ... and 2 more cases

</details>

<details>
<summary><strong>LC435: Non Overlapping Intervals</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/non-overlapping-intervals/

**💻 Solutions**:
- [C++](src/cpp/neet150/435.non-overlapping-intervals.cpp)

</details>

<details>
<summary><strong>LC438: Find All Anagrams in a String</strong> (Medium) - sliding_window</summary>

**🔗 Problem Link**: https://leetcode.com/problems/find-all-anagrams-in-a-string/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=G8xtZy0fDKg

**💻 Solutions**:
- [C++](src/cpp/sliding_window/438.find-all-anagrams-in-a-string.cpp)
- [Go](src/go/sliding_window/438.find-all-anagrams-in-a-string.go)

**🧪 Test Cases** (4 cases):
1. `{"s": "cbaebabacd", "p": "abc", "expected": [0, 6]}`
2. `{"s": "abab", "p": "ab", "expected": [0, 1, 2]}`
3. `{"s": "baa", "p": "aa", "expected": [1]}`
   ... and 1 more cases

</details>

<details>
<summary><strong>LC460: LFU Cache</strong> (Hard) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/lfu-cache/

**💻 Solutions**:
- [C++](src/cpp/misc/460.lfu-cache.cpp)

**🧪 Test Cases** (1 cases):
1. `{"commands": ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"], "ar...`

</details>

<details>
<summary><strong>LC494: Target Sum</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/target-sum/

**💻 Solutions**:
- [C++](src/cpp/neet150/494.target-sum.cpp)

</details>

<details>
<summary><strong>LC518: Coin Change II</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/coin-change-ii/

**💻 Solutions**:
- [C++](src/cpp/neet150/518.coin-change-ii.cpp)

</details>

<details>
<summary><strong>LC543: Diameter of Binary Tree</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/diameter-of-binary-tree/

**💻 Solutions**:
- [C++](src/cpp/neet150/543.diameter-of-binary-tree.cpp)

</details>

<details>
<summary><strong>LC560: Subarray Sum Equals K</strong> (Medium) - prefix_sum</summary>

**🔗 Problem Link**: https://leetcode.com/problems/subarray-sum-equals-k/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=HbbYPQc-Oo4

**💻 Solutions**:
- [C++](src/cpp/prefix_sum/560.subarray-sum-equals-k.cpp)
- [Go](src/go/prefix_sum/560.subarray-sum-equals-k.go)

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

**🧪 Test Cases** (5 cases):
1. `{"s1": "ab", "s2": "eidbaooo", "expected": True}`
2. `{"s1": "ab", "s2": "eidboaoo", "expected": False}`
3. `{"s1": "adc", "s2": "dcda", "expected": True}`
   ... and 2 more cases

</details>

<details>
<summary><strong>LC572: Subtree of Another Tree</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/subtree-of-another-tree/

**💻 Solutions**:
- [C++](src/cpp/neet150/572.subtree-of-another-tree.cpp)

</details>

<details>
<summary><strong>LC621: Task Scheduler</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/task-scheduler/

**💻 Solutions**:
- [C++](src/cpp/neet150/621.task-scheduler.cpp)

</details>

<details>
<summary><strong>LC647: Palindromic Substrings</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/palindromic-substrings/

**💻 Solutions**:
- [C++](src/cpp/neet150/647.palindromic-substrings.cpp)

</details>

<details>
<summary><strong>LC678: Valid Parenthesis String</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/valid-parenthesis-string/

**💻 Solutions**:
- [C++](src/cpp/neet150/678.valid-parenthesis-string.cpp)

</details>

<details>
<summary><strong>LC684: Redundant Connection</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/redundant-connection/

**💻 Solutions**:
- [C++](src/cpp/neet150/684.redundant-connection.cpp)

</details>

<details>
<summary><strong>LC695: Max Area of Island</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/max-area-of-island/

**💻 Solutions**:
- [C++](src/cpp/neet150/695.max-area-of-island.cpp)

</details>

<details>
<summary><strong>LC703: Kth Largest Element In a Stream</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/kth-largest-element-in-a-stream/

**💻 Solutions**:
- [C++](src/cpp/neet150/703.kth-largest-element-in-a-stream.cpp)

</details>

<details>
<summary><strong>LC704: Binary Search</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/binary-search/

**💻 Solutions**:
- [C++](src/cpp/neet150/704.binary-search.cpp)

</details>

<details>
<summary><strong>LC739: Daily Temperatures</strong> (Medium) - stack</summary>

**🔗 Problem Link**: https://leetcode.com/problems/daily-temperatures/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=cTBiBSnjO3c

**💻 Solutions**:
- [C++](src/cpp/stack/739.daily-temperatures.cpp)
- [Go](src/go/stack/739.daily-temperatures.go)

**🧪 Test Cases** (6 cases):
1. `{"input": [73, 74, 75, 71, 69, 72, 76, 73], "expected": [1, 1, 4, 2, 1, 1, 0, 0]}`
2. `{"input": [30, 40, 50, 60], "expected": [1, 1, 1, 0]}`
3. `{"input": [30, 60, 90], "expected": [1, 1, 0]}`
   ... and 3 more cases

</details>

<details>
<summary><strong>LC743: Network Delay Time</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/network-delay-time/

**💻 Solutions**:
- [C++](src/cpp/neet150/743.network-delay-time.cpp)

</details>

<details>
<summary><strong>LC746: Min Cost Climbing Stairs</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/min-cost-climbing-stairs/

**💻 Solutions**:
- [C++](src/cpp/neet150/746.min-cost-climbing-stairs.cpp)

</details>

<details>
<summary><strong>LC763: Partition Labels</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/partition-labels/

**💻 Solutions**:
- [C++](src/cpp/neet150/763.partition-labels.cpp)

</details>

<details>
<summary><strong>LC778: Swim In Rising Water</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/swim-in-rising-water/

**💻 Solutions**:
- [C++](src/cpp/neet150/778.swim-in-rising-water.cpp)

</details>

<details>
<summary><strong>LC787: Cheapest Flights Within K Stops</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/cheapest-flights-within-k-stops/

**💻 Solutions**:
- [C++](src/cpp/neet150/787.cheapest-flights-within-k-stops.cpp)

</details>

<details>
<summary><strong>LC846: Hand of Straights</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/hand-of-straights/

**💻 Solutions**:
- [C++](src/cpp/neet150/846.hand-of-straights.cpp)

</details>

<details>
<summary><strong>LC853: Car Fleet</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/car-fleet/

**💻 Solutions**:
- [C++](src/cpp/neet150/853.car-fleet.cpp)

</details>

<details>
<summary><strong>LC875: Koko Eating Bananas</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/koko-eating-bananas/

**💻 Solutions**:
- [C++](src/cpp/neet150/875.koko-eating-bananas.cpp)

</details>

<details>
<summary><strong>LC973: K Closest Points to Origin</strong> (Medium) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/k-closest-points-to-origin/

**💻 Solutions**:
- [C++](src/cpp/neet150/973.k-closest-points-to-origin.cpp)

**🧪 Test Cases** (2 cases):
1. `{"points": [[1, 3], [-2, 2]], "k": 1, "expected": [[-2, 2]]}`
2. `{"points": [[3, 3], [5, -1], [-2, 4]], "k": 2, "expected": [[-2, 4], [3, 3]]}`

</details>

<details>
<summary><strong>LC981: Time Based Key-Value Store</strong> (Medium) - binary_search</summary>

**🔗 Problem Link**: https://leetcode.com/problems/time-based-key-value-store/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=fu2cD_6E8Hw

**💻 Solutions**:
- [C++](src/cpp/binary_search/981.time-based-key-value-store.cpp)
- [Go](src/go/binary_search/981.time-based-key-value-store.go)

**🧪 Test Cases** (1 cases):
1. `{"commands": ["TimeMap", "set", "get", "get", "set", "get", "get"], "args": [[], ["foo", "bar", 1], ...`

</details>

<details>
<summary><strong>LC994: Rotting Oranges</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/rotting-oranges/

**💻 Solutions**:
- [C++](src/cpp/neet150/994.rotting-oranges.cpp)

</details>

<details>
<summary><strong>LC1046: Last Stone Weight</strong> (Easy) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/last-stone-weight/

**💻 Solutions**:
- [C++](src/cpp/neet150/1046.last-stone-weight.cpp)

</details>

<details>
<summary><strong>LC1117: Building H2O</strong> (Medium) - concurrency</summary>

**🔗 Problem Link**: https://leetcode.com/problems/building-h2o/

**💻 Solutions**:
- [C++](src/cpp/concurrency/1117.building-h2o.cpp)

**🧪 Test Cases** (6 cases):
1. `{"input": "OOHHHH"}`
2. `{"input": "HOH"}`
3. `{"input": "HOHHOH"}`
   ... and 3 more cases

</details>

<details>
<summary><strong>LC1143: Longest Common Subsequence</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/longest-common-subsequence/

**💻 Solutions**:
- [C++](src/cpp/neet150/1143.longest-common-subsequence.cpp)

</details>

<details>
<summary><strong>LC1146: Snapshot Array</strong> (Medium) - misc</summary>

**🔗 Problem Link**: https://leetcode.com/problems/snapshot-array/

**💻 Solutions**:
- [C++](src/cpp/misc/1146.snapshot-array.cpp)

**🧪 Test Cases** (1 cases):
1. `{"commands": ["SnapshotArray", "set", "snap", "set", "get"], "arguments": [[3], [0, 5], [], [0, 6], ...`

</details>

<details>
<summary><strong>LC1188: Design Bounded Blocking Queue</strong> (Medium) - concurrency</summary>

**🔗 Problem Link**: https://leetcode.com/problems/bounded-blocking-queue/

**💻 Solutions**:
- [C++](src/cpp/concurrency/1188.bounded-blocking-queue.cpp)

**🧪 Test Cases** (3 cases):
1. `{"capacity": 2, "producers": [[1, 2, 3]], "consumers_calls": [3]}`
2. `{"capacity": 3, "producers": [[1, 2], [3, 4]], "consumers_calls": [2, 2]}`
3. `{"capacity": 1, "producers": [[10], [20], [30]], "consumers_calls": [1, 1, 1]}`

</details>

<details>
<summary><strong>LC1203: Sort Items by Groups Respecting Dependencies</strong> (Hard) - graphs</summary>

**🔗 Problem Link**: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

**💻 Solutions**:
- [C++](src/cpp/graphs/1203.sort-items-by-groups-respecting-dependencies.cpp)

**🧪 Test Cases** (2 cases):
1. `{"n": 8, "m": 2, "group": [-1, -1, 1, 0, 0, 1, 0, -1], "beforeItems": [[], [6], [5], [6], [3, 6], []...`
2. `{"n": 8, "m": 2, "group": [-1, -1, 1, 0, 0, 1, 0, -1], "beforeItems": [[], [6], [5], [6], [3], [], [...`

</details>

<details>
<summary><strong>LC1235: Maximum Profit in Job Scheduling</strong> (Hard) - dp</summary>

**🔗 Problem Link**: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

**📺 NeetCode Explanation**: https://www.youtube.com/watch?v=JLoWc3v0SiE

**💻 Solutions**:
- [C++](src/cpp/dp/1235.maximum-profit-in-job-scheduling.cpp)
- [Go](src/go/dp/1235.maximum-profit-in-job-scheduling.go)
- [Java](src/java/dp/P1235.java)

**🧪 Test Cases** (4 cases):
1. `{"startTime": [1, 2, 3, 3], "endTime": [3, 4, 5, 6], "profit": [50, 10, 40, 70], "expected": 120}`
2. `{"startTime": [1, 2, 3, 4, 6], "endTime": [3, 5, 10, 6, 9], "profit": [20, 20, 100, 70, 60], "expect...`
3. `{"startTime": [1, 1, 1], "endTime": [2, 3, 4], "profit": [5, 6, 4], "expected": 6}`
   ... and 1 more cases

</details>

<details>
<summary><strong>LC1242: Web Crawler Multithreaded</strong> (Medium) - concurrency</summary>

**🔗 Problem Link**: https://leetcode.com/problems/web-crawler-multithreaded/

**💻 Solutions**:
- [C++](src/cpp/concurrency/1242.web-crawler-multithreaded.cpp)

**🧪 Test Cases** (1 cases):
1. `{"urls": ["http://news.yahoo.com", "http://news.yahoo.com/news", "http://news.yahoo.com/news/topics/...`

</details>

<details>
<summary><strong>LC1448: Count Good Nodes In Binary Tree</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

**💻 Solutions**:
- [C++](src/cpp/neet150/1448.count-good-nodes-in-binary-tree.cpp)

</details>

<details>
<summary><strong>LC1584: Min Cost to Connect All Points</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/min-cost-to-connect-all-points/

**💻 Solutions**:
- [C++](src/cpp/neet150/1584.min-cost-to-connect-all-points.cpp)

</details>

<details>
<summary><strong>LC1851: Minimum Interval to Include Each Query</strong> (Hard) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/minimum-interval-to-include-each-query/

**💻 Solutions**:
- [C++](src/cpp/neet150/1851.minimum-interval-to-include-each-query.cpp)

</details>

<details>
<summary><strong>LC1899: Merge Triplets to Form Target Triplet</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

**💻 Solutions**:
- [C++](src/cpp/neet150/1899.merge-triplets-to-form-target-triplet.cpp)

</details>

<details>
<summary><strong>LC2013: Detect Squares</strong> (Medium) - neet150</summary>

**🔗 Problem Link**: https://leetcode.com/problems/detect-squares/

**💻 Solutions**:
- [C++](src/cpp/neet150/2013.detect-squares.cpp)

</details>

<details>
<summary><strong>LC10000: Shortest Cycle of a Target Node</strong> (Medium) - graphs</summary>

**💻 Solutions**:
- [C++](src/cpp/graphs/10000.shortest-cycle-of-target-node.cpp)

**🧪 Test Cases** (3 cases):
1. `{"n": 4, "edges": [[0, 1], [1, 2], [2, 0], [2, 3]], "target": 0, "expected": 3}`
2. `{"n": 4, "edges": [[0, 1], [1, 2], [2, 3]], "target": 0, "expected": -1}`
3. `{"n": 3, "edges": [[0, 1], [1, 0], [1, 2], [2, 1]], "target": 1, "expected": 2}`

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
