#include "../lc_test_utils.h"
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */
struct Data {
  int timestamp;
  string val;
};

// @lc code=start
class TimeMap {
private:
  unordered_map<string, vector<Data>> store;

public:
  TimeMap() : store() {}

  void set(string key, string value, int timestamp) {
    store[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    // check if the key is available in store first
    auto it = store.find(key);
    if (it == store.end()) {
      return "";
    }

    // key is available, get the values vector.
    const auto &values = it->second;

    // custom comparator for finding timestamp.
    auto cmp = [](int ts, const Data &data) { return ts < data.timestamp; };

    // upper_bound finds the first element strictly greater than timestamp
    auto upper = upper_bound(values.begin(), values.end(), timestamp, cmp);

    // If upper is at the beginning, all timestamps are strictly greater than
    // the target
    if (upper == values.begin()) {
      return "";
    }

    // The element just before upper has a timestamp <= target
    return prev(upper)->val;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

// Wrapper for test harness
vector<string> runTimeMap(const vector<string> &cmds, const json &args) {
  TimeMap *tm = nullptr;
  vector<string> res;

  for (size_t i = 0; i < cmds.size(); ++i) {
    if (cmds[i] == "TimeMap") {
      tm = new TimeMap();
      res.push_back("null");
    } else if (cmds[i] == "set") {
      string key = args[i][0].get<string>();
      string val = args[i][1].get<string>();
      int timestamp = args[i][2].get<int>();
      tm->set(key, val, timestamp);
      res.push_back("null");
    } else if (cmds[i] == "get") {
      string key = args[i][0].get<string>();
      int timestamp = args[i][1].get<int>();
      res.push_back(tm->get(key, timestamp));
    }
  }
  delete tm;
  return res;
}
