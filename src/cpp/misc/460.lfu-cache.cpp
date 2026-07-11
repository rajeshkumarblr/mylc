/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 *
 * Problem Description:
 * Design and implement a data structure for a Least Frequently Used (LFU)
 * cache.
 *
 * Implement the LFUCache class:
 * - LFUCache(int capacity) Initializes the object with the capacity of the data
 * structure.
 * - int get(int key) Gets the value of the key if the key exists in the cache.
 *   Otherwise, returns -1.
 * - void put(int key, int value) Update the value of the key if present, or
 * inserts the key if not already present. When the cache reaches its capacity,
 * it should invalidate and remove the least frequently used key before
 * inserting a new item. For this problem, when there is a tie (i.e., two or
 * more keys with the same frequency), the least recently used key would be
 * invalidated.
 *
 * To determine the least frequently used key, a use counter is maintained for
 * each key in the cache. The element with the smallest use counter is the least
 * frequently used key. When a key is first inserted, its use counter is set to
 * 1 (due to the put operation). The use counter for a key in the cache is
 * incremented either a get or put operation is called on it.
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 * Examples:
 * Input:
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
 * "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * Output:
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 *
 * Constraints:
 * - 1 <= capacity <= 10^4
 * - 0 <= key <= 10^5
 * - 0 <= value <= 10^9
 * - At most 2 * 10^5 calls will be made to get and put.
 */

#include "../lc_test_utils.h"
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
struct Node {
  int key, value, freq;
  Node(int k, int v) : key(k), value(v), freq(1) {}
};

class LFUCache {
  int cap, min_freq;
  unordered_map<int, list<Node>::iterator> key_to_node; // Map key to iterator
  unordered_map<int, list<Node>> freq_to_list; // Map freq to list of nodes
public:
  LFUCache(int capacity) : cap(capacity), min_freq(0) {}

  int get(int key) {
    if (key_to_node.find(key) == key_to_node.end())
      return -1;

    // Retrieve node and update frequency
    auto it = key_to_node[key];
    int val = it->value;
    int freq = it->freq;

    // Remove from old freq list, move to freq + 1 list
    freq_to_list[freq].erase(it);
    if (freq_to_list[freq].empty()) {
      freq_to_list.erase(freq);
      if (min_freq == freq)
        min_freq++;
    }

    key_to_node[key] =
        freq_to_list[freq + 1].insert(freq_to_list[freq + 1].end(), {key, val});
    key_to_node[key]->freq = freq + 1;

    return val;
  }

  void put(int key, int value) {
    if (cap <= 0)
      return;

    // If key exists, update value and frequency
    if (key_to_node.find(key) != key_to_node.end()) {
      key_to_node[key]->value = value;
      get(key); // Helper to handle the frequency jump
      return;
    }

    // Evict if at capacity
    if (key_to_node.size() >= cap) {
      int evict_key = freq_to_list[min_freq].front().key;
      freq_to_list[min_freq].pop_front();
      if (freq_to_list[min_freq].empty())
        freq_to_list.erase(min_freq);
      key_to_node.erase(evict_key);
    }

    // Insert new key
    min_freq = 1;
    key_to_node[key] =
        freq_to_list[1].insert(freq_to_list[1].end(), {key, value});
  }
};
// @lc code=end

vector<string> runLFUCache(const vector<string> &cmds, const json &args) {
  LFUCache *cache = nullptr;
  vector<string> res;
  for (size_t i = 0; i < cmds.size(); ++i) {
    if (cmds[i] == "LFUCache") {
      int capacity = args[i][0].get<int>();
      cache = new LFUCache(capacity);
      res.push_back("null");
    } else if (cmds[i] == "put") {
      int key = args[i][0].get<int>();
      int value = args[i][1].get<int>();
      cache->put(key, value);
      res.push_back("null");
    } else if (cmds[i] == "get") {
      int key = args[i][0].get<int>();
      res.push_back(to_string(cache->get(key)));
    }
  }
  delete cache;
  return res;
}
