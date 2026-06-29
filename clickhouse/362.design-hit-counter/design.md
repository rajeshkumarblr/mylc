# Design - Design Hit Counter

## Problem Overview
Design a hit counter that records the number of hits received in the past 5 minutes (300 seconds).

## Key Design Choices

### 1. Fixed-Size Circular Buffer (Optimized for Cache & Memory)
A simple queue-based solution where incoming hits are pushed at the tail and old hits are popped from the head can consume unbounded memory under high traffic.
- **Solution:** Maintain two arrays of size 300 (since we only care about the last 300 seconds):
  - `times`: Stores the timestamp of the last update in each bucket.
  - `hits`: Stores the count of hits at that second.
- **Lookup/Update:** `idx = timestamp % 300`.
  - If the bucket has an old timestamp from a previous cycle, we reset the count to `1` and overwrite the timestamp.
  - Otherwise, we increment the count.

### 2. Thread Safety (Concurrency)
To prevent data races on concurrent queries and hits, a `std::mutex` is used to synchronize read and write access to the arrays.
- For higher-performance systems (like ClickHouse), mutex contention can be reduced further using **atomic counters** (`std::atomic<int>`) or **bucket segmentation** (sharding the mutexes).

## Complexity
- **Time Complexity:**
  - `hit`: O(1) time.
  - `getHits`: O(1) time (we only iterate over a fixed 300 buckets).
- **Space Complexity:** O(1) auxiliary space (uses only 2 arrays of size 300, which fit completely inside the CPU's L1 cache, avoiding cache misses).
