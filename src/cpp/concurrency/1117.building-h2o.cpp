#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <nlohmann/json.hpp>
#include <iostream>
#include <utility>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
using namespace std;
using json = nlohmann::json;

static bool isValidH2OSequence(const std::string &s);

using json = nlohmann::json;

static bool isValidH2OSequence(const std::string &s);

using json = nlohmann::json;

static bool isValidH2OSequence(const std::string &s);

using json = nlohmann::json;

static bool isValidH2OSequence(const std::string &s);

using json = nlohmann::json;

string runH2O(const string &input);



/*
 * @lc app=leetcode id=1117 lang=cpp
 *
 * [1117] Building H2O
 *
 * Synchronize hydrogen and oxygen threads to output water molecules in a valid
 * ratio (2 H : 1 O).
 */

class H2O_state {
  std::mutex m;
  std::condition_variable h_cond, o_cond;

  enum { INIT, HYDROGEN1_EMITTED, HYDROGEN2_EMITTED } state;

public:
  H2O_state() { state = INIT; }

  void hydrogen(function<void()> releaseHydrogen) {
    std::unique_lock<mutex> lock(m);
    h_cond.wait(lock, [this] { return state != HYDROGEN2_EMITTED; });
    releaseHydrogen();
    if (state == INIT)
      state = HYDROGEN1_EMITTED;
    else if (state == HYDROGEN1_EMITTED)
      state = HYDROGEN2_EMITTED;
    o_cond.notify_one();
  }

  void oxygen(function<void()> releaseOxygen) {
    std::unique_lock<mutex> lock(m);
    o_cond.wait(lock, [this] { return state == HYDROGEN2_EMITTED; });
    releaseOxygen();
    state = INIT;
    h_cond.notify_all();
  }
};

#include <semaphore>

class H2O_vars {
private:
  std::mutex m;
  std::condition_variable h_cond, o_cond;
  int h_cnt;
  int o_cnt;

public:
  H2O_vars() { h_cnt = o_cnt = 0; }

  inline void tryResetGroup() {
    if (h_cnt == 2 && o_cnt == 1) {
      h_cnt = 0;
      o_cnt = 0;
      h_cond.notify_all();
      o_cond.notify_one();
    }
  }

  void hydrogen(function<void()> releaseHydrogen) {
    std::unique_lock<mutex> lock(m);
    h_cond.wait(lock, [this] { return h_cnt < 2; });
    releaseHydrogen();
    h_cnt++;
    tryResetGroup();
  }

  void oxygen(function<void()> releaseOxygen) {
    std::unique_lock<mutex> lock(m);
    o_cond.wait(lock, [this] { return o_cnt < 1; });
    releaseOxygen();
    o_cnt++;
    tryResetGroup();
  }
};

// @lc code=start
class H2O {
private:
  std::counting_semaphore<2> h_sem{2};
  std::counting_semaphore<2> o_sem{0};
  std::binary_semaphore o_mutex{1};

public:
  H2O() {}

  void hydrogen(function<void()> releaseHydrogen) {
    h_sem.acquire();
    releaseHydrogen();
    o_sem.release();
  }

  void oxygen(function<void()> releaseOxygen) {
    o_mutex.acquire();
    o_sem.acquire();
    o_sem.acquire();
    o_mutex.release();

    releaseOxygen();
    h_sem.release(2);
  }
};
// @lc code=end
















static bool isValidH2OSequence(const std::string &s) {
  if (s.length() % 3 != 0)
    return false;
  for (size_t i = 0; i < s.length(); i += 3) {
    int h_count = 0;
    int o_count = 0;
    for (int j = 0; j < 3; ++j) {
      if (s[i + j] == 'H')
        h_count++;
      else if (s[i + j] == 'O')
        o_count++;
    }
    if (h_count != 2 || o_count != 1)
      return false;
  }
  return true;
}

bool lc_test_1117(const json &j) {
  bool all = true;
  size_t idx = 0;
  for (const auto &tc : j.at("cases")) {
    std::string input = tc.at("input").get<std::string>();
    std::string got = runH2O(input);
    bool ok = isValidH2OSequence(got);
    if (!ok) {
      std::cout << "  Case " << (++idx) << ": FAIL\n    input=\"" << input
                << "\"\n    got=\"" << got << "\"\n";
    } else {
      ++idx;
    }
    all &= ok;
  }
  return all;
}



// Test harness wrapper function
string runH2O(const string &input) {
  H2O h2o;
  string output;
  mutex output_mtx;

  cout << "input:" << input << endl;

  auto releaseHydrogen = [&output, &output_mtx]() {
    lock_guard<mutex> lock(output_mtx);
    output += "H";
  };

  auto releaseOxygen = [&output, &output_mtx]() {
    lock_guard<mutex> lock(output_mtx);
    output += "O";
  };

  vector<thread> threads;
  for (char c : input) {
    if (c == 'H') {
      threads.emplace_back(
          [&h2o, releaseHydrogen]() { h2o.hydrogen(releaseHydrogen); });
    } else if (c == 'O') {
      threads.emplace_back(
          [&h2o, releaseOxygen]() { h2o.oxygen(releaseOxygen); });
    }
  }
  for (auto &t : threads) {
    t.join();
  }
  cout << "output: " << output << endl;

  return output;
}





int main() {
    try {
        nlohmann::json j = nlohmann::json::parse(R"raw({
  "cases": [
    {
      "input": "OOHHHH"
    },
    {
      "input": "HOH"
    },
    {
      "input": "HOHHOH"
    },
    {
      "input": "HHHHHHHHHHOOOOO"
    },
    {
      "input": "OHH"
    },
    {
      "input": "HOHOHHOHOHHH"
    }
  ]
})raw");
        return lc_test_1117(j) ? 0 : 1;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 4;
    }
}
