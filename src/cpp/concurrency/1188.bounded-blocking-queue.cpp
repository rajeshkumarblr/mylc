#include "../lc_test_utils.h"
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=1188 lang=cpp
 *
 * [1188] Design Bounded Blocking Queue
 *
 * Implement a thread-safe bounded blocking queue with the following methods:
 * - BoundedBlockingQueue(int capacity): Initializes the queue with a maximum
 * capacity.
 * - void enqueue(int element): Adds an element to the back of the queue. If the
 * queue is full, the calling thread must block until the queue has space.
 * - int dequeue(): Removes and returns an element from the front of the queue.
 * If the queue is empty, the calling thread must block until the queue has an
 * element.
 * - int size(): Returns the number of elements currently in the queue.
 */

// @lc code=start
class BoundedBlockingQueue {
private:
  // TODO: Add member variables for synchronization (mutexes, condition
  // variables) and storage
  std::vector<int> q;
  std::mutex mtx;
  std::condition_variable cv_full, cv_empty;
  int capacity;
  int sz;

public:
  BoundedBlockingQueue(int capacity) {
    // TODO: Initialize your queue and capacity
    this->capacity = capacity;
    sz = 0;
  }

  void enqueue(int element) {
    // TODO: Implement thread-safe enqueue with blocking when full
    std::unique_lock<std::mutex> lck(mtx);
    cv_full.wait(lck, [this] { return sz < capacity; });
    q.push_back(element);
    ++sz;
    cv_empty.notify_one();
  }

  int dequeue() {
    // TODO: Implement thread-safe dequeue with blocking when empty
    std::unique_lock<std::mutex> lck(mtx);
    cv_empty.wait(lck, [this] { return sz > 0; });
    int val = q.front();
    q.erase(q.begin());
    --sz;
    cv_full.notify_one();
    return val;
  }

  int size() {
    // TODO: Implement thread-safe size query
    std::unique_lock<std::mutex> lck(mtx);
    return sz;
  }
};
// @lc code=end

// Test harness wrapper function
vector<int> runBoundedBlockingQueue(int capacity,
                                    const vector<vector<int>> &producers,
                                    const vector<int> &consumers_calls) {
  BoundedBlockingQueue bbq(capacity);
  vector<int> dequeued_elements;
  mutex output_mtx;

  vector<thread> prod_threads;
  vector<thread> cons_threads;

  // Spawn producer threads
  for (const auto &p_list : producers) {
    prod_threads.emplace_back([&bbq, p_list]() {
      for (int val : p_list) {
        bbq.enqueue(val);
      }
    });
  }

  // Spawn consumer threads
  for (int calls : consumers_calls) {
    cons_threads.emplace_back([&bbq, &dequeued_elements, &output_mtx, calls]() {
      for (int i = 0; i < calls; ++i) {
        int val = bbq.dequeue();
        lock_guard<mutex> lock(output_mtx);
        dequeued_elements.push_back(val);
      }
    });
  }

  // Join all threads
  for (auto &t : prod_threads) {
    t.join();
  }
  for (auto &t : cons_threads) {
    t.join();
  }

  return dequeued_elements;
}
