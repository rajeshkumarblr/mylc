#include "../lc_test_utils.h"
#include <condition_variable>
#include <functional>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std;

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
