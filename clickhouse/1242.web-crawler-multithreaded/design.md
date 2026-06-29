# Design - Multithreaded Web Crawler

## Problem Overview
Implement a multi-threaded web crawler to crawl all links under the same domain name (hostname) as the `startUrl`.

## Key Design Choices

### 1. Synchronization and Thread Safety (Monitor Pattern)
- A **shared queue** (`std::queue<std::string>`) stores the URLs that are ready to be parsed.
- A **hash set** (`std::unordered_set<std::string>`) acts as the registry of visited URLs to prevent redundant work and cyclic parsing loops.
- Access to the queue and the set is synchronized using a `std::mutex` and coordinated via a `std::condition_variable`.

### 2. Lock-free Expensive Calls (Crucial for Concurrency)
If we call the expensive parser function (`HtmlParser::getUrls`) while holding the lock, the threads would execute completely sequentially, eliminating any performance gain from multithreading.
- **Solution:** A thread pops a URL from the queue, increments the count of `active_workers`, **releases the mutex lock**, and then calls `getUrls` concurrently.
- Once the parsing completes, it re-acquires the lock to update the shared data structure.

### 3. Termination Condition
A simple check for `q.empty()` is insufficient for termination. A thread might find the queue empty temporarily while other workers are actively parsing and about to insert new URLs.
- **Correct Criteria:** The crawl is complete only if the queue is empty **and** the count of `active_workers` is `0`.
- When this condition is met, `done` is set to `true`, and all threads are notified via `cv.notify_all()` to exit.

## Complexity
- **Time Complexity:** O(N / T + E) where N is the total unique URLs, T is the number of threads, and E is the domain matching overhead.
- **Space Complexity:** O(N) to store visited URLs in the hash set and queue.
