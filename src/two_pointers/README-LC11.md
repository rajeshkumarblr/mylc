# LC11 — Container With Most Water

**LeetCode:** [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/)  
**Tags:** two-pointers, greedy  
**Time:** O(n) · **Space:** O(1)

---

## Problem
Given an array `height` where `height[i]` is the height of a line at index `i`, pick two lines that together with the x-axis form a container, and return the **maximum area** of water it can store.

The area for indices `l` and `r` is:
area = min(height[l], height[r]) * (r - l)

---

## Intuition
Width decreases as pointers move inward. To possibly increase `min(height[l], height[r])`, always move the pointer at the **shorter** line:
- If `height[l] < height[r]` → `l++`
- Else → `r--`

Moving the taller pointer can’t improve the limiting height and only shrinks width.

---

## Algorithm
1. Initialize `l = 0`, `r = n - 1`, and `maxarea = 0`.
2. While `l < r`:
   - Compute `a = (r - l) * min(height[l], height[r])`.
   - Update `maxarea = max(maxarea, a)`.
   - Move the pointer at the shorter height inward.
3. Return `maxarea`.

**Correctness sketch:**  
If you move the taller line, width decreases and the limiting height can’t improve, so the area cannot increase. Only moving the shorter line can raise the limiting height.

---

## Edge Cases
- `n < 2` → `0`
- All equal heights
- Strictly increasing/decreasing arrays
- Zeros present

---

## C++ Notes
- Take input as `const vector<int>&`.
- Add `#include <algorithm>` for `min`/`max`.
- `int` is sufficient for LeetCode constraints; `long long` is optional.

---

## Tests
- `[1,8,6,2,5,4,8,3,7]` → `49`
- `[1,1]` → `1`
- `[4,3,2,1,4]` → `16`
- `[1,2,1]` → `2`
- `[]` → `0`

---

## Complexity
- **Time:** `O(n)` — each pointer moves at most `n-1` steps.
- **Space:** `O(1)` — constant extra state.
