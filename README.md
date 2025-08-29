
# LeetCode C++ Solutions

This repository contains categorized C++ solutions to LeetCode problems. Each problem is organized in its own directory under a category (such as `array`, `linked_list`, `sliding_window`, `two_pointers`, etc.), and may include multiple solution approaches (e.g., using different data structures or algorithms).

## Repository Structure

```
<category>/
	<problem-id>.<problem-name>/
		solution-<approach>.cpp
		Makefile
		...
```

### Example
```
array/
	1.two-sum/
		solution.cpp
		Makefile
	2.add-two-numbers/
		solution.cpp
		Makefile
sliding_window/
	3.longest-substring-without-repeating-characters/
		solution-map.cpp
		solution-set.cpp
		solution-vector.cpp
		Makefile
```

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
	 cd array/1.two-sum
	 make
	 ./solution
	 ```
	 Or for problems with multiple solutions:
	 ```bash
	 cd sliding_window/3.longest-substring-without-repeating-characters
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
