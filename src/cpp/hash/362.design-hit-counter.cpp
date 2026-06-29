/*
 * @lc app=leetcode id=362 lang=cpp
 *
 * [362] Design Hit Counter
 *
 * Design a hit counter which counts the number of hits received in the past 5
 * minutes (i.e., 300 seconds).
 */

#include "../lc_test_utils.h"
#include <vector>
#include <string>

using namespace std;

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
