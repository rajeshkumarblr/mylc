# LeetCode Solutions

This repository contains categorized solutions to LeetCode problems. Each problem is organized in its own directory under a category (such as `array`, `linked_list`, `sliding_window`, `two_pointers`, etc.), and may include multiple solution approaches (e.g., using different data structures or algorithms).

## Repository Structure

```
<category>/
    <problem-id>.<problem-name>/cpp/
        solution-<approach>.cpp
        Makefile
        ...
```

## Problems

### array

- [1. Two Sum](https://leetcode.com/problems/two-sum/) — *Easy* — tags: array, hash-table — path: `array/1.two-sum/`
- [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) — *Medium* — tags: linked-list, math — path: `array/2.add-two-numbers/`
- [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/) — *Unknown* — path: `array/9.palindrome-number/`

### linked_list

- [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) — *Easy* — tags: linked-list, recursion — path: `linked_list/21.merge-two-sorted-lists/`

### sliding_window

- [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) — *Medium* — tags: sliding-window, string, hash-table — path: `sliding_window/3.longest-substring-without-repeating-characters/`
- [424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) — *Unknown* — path: `sliding_window/424.longest-repeating-character-replacement/`
- [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) — *Medium* — tags: sliding-window, string, hash-table — path: `sliding_window/438.find-all-anagrams-in-a-string/`
- [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/) — *Medium* — tags: sliding-window, string, hash-table — path: `sliding_window/567.permutation-in-string/`

### two_pointers

- [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) — *Unknown* — path: `two_pointers/42.trapping-rain-water/`


## Features
- **Multiple Approaches:** Each problem may have several solution files, demonstrating different techniques (e.g., map, set, vector).
- **Category Organization:** Problems are grouped by topic for easy navigation.
- **Makefile Automation:** Each problem and category includes a Makefile for easy building and testing.
- **Standardized Test Output:** All solutions use a common test utility for readable, aligned output.

## How to Use
1. **Clone the repository:**
     ```bash
     git clone https://github.com/rajeshkumarblr/mylc.git
     cd mylc
     ```
2. **Build and run a solution:**
     ```bash
     cd array/1.two-sum/cpp
     make
     ./solution
     ```
     Or for problems with multiple solutions:
     ```bash
     cd sliding_window/3.longest-substring-without-repeating-characters/cpp
     make
     ./solution-map
     ./solution-set
     ./solution-vector
     ```
3. **Add your own solutions:**
     - Create a new directory for the problem under the appropriate category.
     - Add your solution file(s) and a Makefile.
     - Use the provided `lc_test_utils.h` for standardized test output.

## Categories
- `array/` — Array and math problems
- `linked_list/` — Linked list problems
- `sliding_window/` — Sliding window techniques
- `two_pointers/` — Two pointers and related problems
- *(Add more categories as needed)*

## Contributing
Pull requests are welcome! Please follow the directory and naming conventions, and use the test utilities for consistency.

## License
This project is licensed under the MIT License.
