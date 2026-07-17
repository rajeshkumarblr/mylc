#include <unordered_set>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <utility>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
using namespace std;
using json = nlohmann::json;

bool lc_test_1188(const json &j);

using json = nlohmann::json;

bool lc_test_1188(const json &j);

using json = nlohmann::json;

bool lc_test_1188(const json &j);

using json = nlohmann::json;

bool lc_test_1188(const json &j);

using json = nlohmann::json;

vector<int> runBoundedBlockingQueue(int capacity, const vector<vector<int>> &producers, const vector<int> &consumers_calls);



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
















bool lc_test_1188(const json &j) {
  bool all = true;
  size_t idx = 0;
  for (const auto &tc : j.at("cases")) {
    int capacity = tc.at("capacity").get<int>();

    std::vector<std::vector<int>> producers;
    for (const auto &p : tc.at("producers")) {
      producers.push_back(p.get<std::vector<int>>());
    }

    std::vector<int> consumers_calls =
        tc.at("consumers_calls").get<std::vector<int>>();

    // Gather all enqueued elements for verification
    std::vector<int> expect;
    for (const auto &p : producers) {
      expect.insert(expect.end(), p.begin(), p.end());
    }
    std::sort(expect.begin(), expect.end());

    std::vector<int> got =
        runBoundedBlockingQueue(capacity, producers, consumers_calls);
    std::sort(got.begin(), got.end());

    bool ok = (got == expect);
    if (!ok) {
      std::cout << "  Case " << (++idx) << ": FAIL\n    got=";
      for (int x : got)
        std::cout << x << " ";
      std::cout << "\n    exp=";
      for (int x : expect)
        std::cout << x << " ";
      std::cout << "\n";
    } else {
      ++idx;
    }
    all &= ok;
  }
  return all;
}



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





int main() {
    try {
        nlohmann::json j = nlohmann::json::parse(R"raw({
  "cases": [
    {
      "capacity": 2,
      "producers": [
        [
          1,
          2,
          3
        ]
      ],
      "consumers_calls": [
        3
      ]
    },
    {
      "capacity": 3,
      "producers": [
        [
          1,
          2
        ],
        [
          3,
          4
        ]
      ],
      "consumers_calls": [
        2,
        2
      ]
    },
    {
      "capacity": 1,
      "producers": [
        [
          10
        ],
        [
          20
        ],
        [
          30
        ]
      ],
      "consumers_calls": [
        1,
        1,
        1
      ]
    }
  ]
})raw");
        return lc_test_1188(j) ? 0 : 1;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 4;
    }
}
