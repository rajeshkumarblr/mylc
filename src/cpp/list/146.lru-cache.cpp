#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include <set>
#include <cmath>
#include <map>
#include <nlohmann/json.hpp>
#include <iostream>
#include <utility>
#include "../lc_types.h"
/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * Difficulty: Medium
 * Category: list
 * URL: https://leetcode.com/problems/lru-cache/
 *
 * Description:
 * Design a data structure that follows the constraints of a   Least Recently
 * Used (LRU) cache  .
 *  Implement the  LRUCache  class:
 *           LRUCache(int capacity)  Initialize the LRU cache with  positive
 * size  capacity .
 *           int get(int key)  Return the value of the  key  if the key
 * exists, otherwise return  -1 .
 *           void put(int key, int value)  Update the value of the  key  if
 * the  key  exists. Otherwise, add the  key-value  pair to the cache. If the
 * number of keys exceeds the  capacity  from this operation,  evict  the
 * least recently used key.
 *  The functions  get  and  put  must each run in  O(1)  average time
 * complexity.
 *   Example 1:
 *  Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 *  Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *  Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *   Constraints:
 *           1 <= capacity <= 3000
 *           0 <= key <= 10 4
 *           0 <= value <= 10 5
 *          At most  2 * 10 5   calls will be made to  get  and  put .
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;


// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
        
    }
    
    int get(int key) {
        return -1;
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


int main() {
    try {
        json j = json::parse(R"raw({
  "cases": [
    {
      "commands": [
        "LRUCache",
        "put",
        "put",
        "get",
        "put",
        "get",
        "put",
        "get",
        "get",
        "get"
      ],
      "arguments": [
        [
          2
        ],
        [
          1,
          1
        ],
        [
          2,
          2
        ],
        [
          1
        ],
        [
          3,
          3
        ],
        [
          2
        ],
        [
          4,
          4
        ],
        [
          1
        ],
        [
          3
        ],
        [
          4
        ]
      ],
      "expected": [
        null,
        null,
        null,
        1,
        null,
        -1,
        null,
        -1,
        3,
        4
      ]
    },
    {
      "commands": [
        "LRUCache",
        "put",
        "put",
        "get",
        "put",
        "put",
        "get"
      ],
      "arguments": [
        [
          2
        ],
        [
          2,
          1
        ],
        [
          2,
          2
        ],
        [
          2
        ],
        [
          1,
          1
        ],
        [
          4,
          1
        ],
        [
          2
        ]
      ],
      "expected": [
        null,
        null,
        null,
        2,
        null,
        null,
        -1
      ]
    }
  ]
})raw");
        for (const auto &tc : j.at("cases")) {
            const auto &commands = tc.at("commands");
            const auto &args = tc.contains("arguments") ? tc.at("arguments") : tc.at("args");
            const auto &expected = tc.at("expected");
            LRUCache* obj = nullptr;
            for (size_t i = 0; i < commands.size(); ++i) {
                string cmd = commands[i].get<string>();
                if (cmd == "LRUCache") {
                    if (obj) delete obj;
                    obj = new LRUCache(args[i][0].get<int>());
                } else if (cmd == "get") {
                    int got = obj->get(args[i][0].get<int>());
                    int exp = expected[i].get<int>();
                    if (got != exp) { cerr << "FAIL get" << endl; return 1; }
                } else if (cmd == "put") {
                    obj->put(args[i][0].get<int>(), args[i][1].get<int>());
                }
            }
            if (obj) delete obj;
        }
        cout << "PASS" << endl;
        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 4;
    }
}
