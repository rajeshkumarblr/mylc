# Design - Merge Intervals

## Problem Overview
Given an array of intervals, merge all overlapping intervals and return an array of the non-overlapping intervals.

## Key Design Choices

### 1. In-Place Merging (Zero Dynamic Allocation)
Instead of allocating a separate `result` vector and copying overlapping components, this implementation modifies the input vector in-place.
- A `writeIdx` pointer tracks the write boundary of the merged list.
- We iterate through the list using a fast linear scan. If there is an overlap, we expand the end of the interval at `intervals[writeIdx]`.
- If there is no overlap, we advance the `writeIdx` and transfer the next interval.

### 2. Move Semantics and Self-Move Safety
- **Moving over Copying:** `std::move` is used to transfer ownership of inner vectors without allocating new memory blocks, reducing latency.
- **Self-Move Guard:** When elements do not overlap, we might do `intervals[writeIdx] = std::move(intervals[i])`. If `writeIdx == i`, this results in a self-move which clears out the vector. We guard against this using `if (writeIdx != i)`.

## Alternate Approach (Sweep-Line / Difference Array)
If coordinate bounds are small (e.g., coordinates <= 10^4), we can scale coordinates by 2 (to separate adjacent bounds like [1,2] and [3,4]) and construct a difference array. 
- Scan the difference array linearly to find contiguous boundaries.
- **Complexity:** O(N + Range) time and O(Range) space. Avoids comparison sorting completely.

## Complexity (In-Place Solution)
- **Time Complexity:** O(N log N) dominated by `std::sort`.
- **Space Complexity:** O(1) auxiliary space (uses stack space for sorting recursion, but no heap allocations).
