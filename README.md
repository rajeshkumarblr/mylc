# LeetCode Solutions

This repository contains categorized solutions to LeetCode problems. Each problem is organized in its own directory under a category (such as `array`, `linked_list`, `sliding_window`, `two_pointers`, etc.).

## Repository Structure

```
<category>/
    lc<id>.cpp
    lc<id2>.cpp
    Makefile
    ...
```
Each problem has a single C++ file (e.g., `lc3.cpp`) containing all solution variants for that problem.

## Problems

### array

- [1] [Two Sum](https://leetcode.com/problems/two-sum/) — *Easy* — tags: array, hash-table — file: `array/lc1.cpp`
- [2] [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) — *Medium* — tags: linked-list, math — file: `array/lc2.cpp`
- [9] lc9.cpp — *Unknown* — file: `array/lc9.cpp`

### linked_list

- [21] [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) — *Easy* — tags: linked-list, recursion — file: `linked_list/lc21.cpp`

### sliding_window

- [3] [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) — *Medium* — tags: sliding-window, string, hash-table — file: `sliding_window/lc3.cpp`
- [424] lc424.cpp — *Unknown* — file: `sliding_window/lc424.cpp`
- [438] [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) — *Medium* — tags: sliding-window, string, hash-table — file: `sliding_window/lc438.cpp`
- [567] [Permutation in String](https://leetcode.com/problems/permutation-in-string/) — *Medium* — tags: sliding-window, string, hash-table — file: `sliding_window/lc567.cpp`

### two_pointers

- [42] lc42.cpp — *Unknown* — file: `two_pointers/lc42.cpp`


## Features
- **Multiple Approaches:** Each problem may have several solution variants, all in a single file (e.g., different methods in `lc3.cpp`).
- **Category Organization:** Problems are grouped by topic for easy navigation.
- **Makefile Automation:** Each category includes a Makefile for easy building and testing.
- **Standardized Test Output:** All C++ solutions use a common test utility for readable, aligned output.

## How to Use
1. **Clone the repository:**
    ```bash
    git clone https://github.com/rajeshkumarblr/mylc.git
    cd mylc
    ```
2. **Build and run a C++ solution:**
    ```bash
    cd array
    make lc1
    ./build/lc1
    ```
    Or for other problems:
    ```bash
    cd sliding_window
    make lc3
    ./build/lc3
    ```
3. **Add your own solutions:**
    - Add a new file (e.g., `lc42.cpp`) in the appropriate category directory.
    - Add your solution variants as methods in that file.
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
