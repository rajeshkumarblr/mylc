#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <nlohmann/json.hpp>
#include <unordered_set>
#include <unordered_map>
#include <thread>
#include <cmath>
#include <map>
#include <stack>
#include <condition_variable>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=362 lang=cpp
 *
 * [362] Design Hit Counter
 *
 * Design a hit counter which counts the number of hits received in the past 5
 * minutes (i.e., 300 seconds).
 */

#include <vector>
#include <string>
using namespace std;
using json = nlohmann::json;

bool lc_test_362(const json &j);

using json = nlohmann::json;

bool lc_test_362(const json &j);

using json = nlohmann::json;

bool lc_test_362(const json &j);

using json = nlohmann::json;

bool lc_test_362(const json &j);

using json = nlohmann::json;

vector<string> runHitCounter(const vector<string> &cmds, const json &args);



// @lc code=start
#include <mutex>

class HitCounter {
private:
  vector<int> times;
  vector<int> hits;
  mutex mtx;

public:
  HitCounter() : times(300, 0), hits(300, 0) {}

  void hit(int timestamp) {
    lock_guard<mutex> lock(mtx);
    int idx = timestamp % 300;
    if (times[idx] != timestamp) {
      times[idx] = timestamp;
      hits[idx] = 1;
    } else {
      hits[idx]++;
    }
  }

  int getHits(int timestamp) {
    lock_guard<mutex> lock(mtx);
    int total = 0;
    for (int i = 0; i < 300; ++i) {
      if (timestamp - times[i] < 300) {
        total += hits[i];
      }
    }
    return total;
  }
};
// @lc code=end
















bool lc_test_362(const json &j) {
  bool all = true;
  size_t idx = 0;
  for (const auto &tc : j.at("cases")) {
    const auto &commandsIf = tc.at("commands");
    const auto &argsIf = tc.at("args");
    const auto &expectedIf = tc.at("expected");

    std::vector<std::string> commands;
    for (const auto &cmd : commandsIf) {
      commands.push_back(cmd.get<std::string>());
    }

    std::vector<std::string> got = runHitCounter(commands, argsIf);

    std::vector<std::string> expect;
    for (const auto &e : expectedIf) {
      if (e.is_null()) {
        expect.push_back("null");
      } else if (e.is_number()) {
        expect.push_back(std::to_string(e.get<int>()));
      } else if (e.is_boolean()) {
        expect.push_back(e.get<bool>() ? "true" : "false");
      } else {
        expect.push_back(e.get<std::string>());
      }
    }

    bool ok = (got == expect);
    if (!ok) {
      std::cout << "  Case " << (++idx) << ": FAIL\n    got=";
      for (const auto &s : got)
        std::cout << s << ",";
      std::cout << "\n    exp=";
      for (const auto &s : expect)
        std::cout << s << ",";
      std::cout << "\n";
    } else {
      ++idx;
    }
    all &= ok;
  }
  return all;
}



vector<string> runHitCounter(const vector<string> &cmds, const json &args) {
  HitCounter *hc = nullptr;
  vector<string> res;

  for (size_t i = 0; i < cmds.size(); ++i) {
    if (cmds[i] == "HitCounter") {
      hc = new HitCounter();
      res.push_back("null");
    } else if (cmds[i] == "hit") {
      int timestamp = args[i][0].get<int>();
      hc->hit(timestamp);
      res.push_back("null");
    } else if (cmds[i] == "getHits") {
      int timestamp = args[i][0].get<int>();
      res.push_back(to_string(hc->getHits(timestamp)));
    }
  }
  delete hc;
  return res;
}





int main() {
    try {
        nlohmann::json j = nlohmann::json::parse(R"raw({
  "cases": [
    {
      "commands": [
        "HitCounter",
        "hit",
        "hit",
        "hit",
        "getHits",
        "hit",
        "getHits",
        "getHits"
      ],
      "args": [
        [],
        [
          1
        ],
        [
          2
        ],
        [
          3
        ],
        [
          4
        ],
        [
          300
        ],
        [
          300
        ],
        [
          301
        ]
      ],
      "expected": [
        null,
        null,
        null,
        null,
        3,
        null,
        4,
        3
      ]
    }
  ]
})raw");
        return lc_test_362(j) ? 0 : 1;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 4;
    }
}
