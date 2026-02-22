/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  struct Job {
    int end, start, p;
  };

  // Returns the number of jobs (from sorted jobs[0..hi)) whose end <= start.
  // i.e. the index of the first job with end > start.
  int latestNonOverlapping(const vector<Job> &jobs, int hi, int start) {
    int lo = 0;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (jobs[mid].end <= start)
        lo = mid + 1;
      else
        hi = mid;
    }
    return lo;
  }

public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    int n = startTime.size();
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
      jobs[i] = {endTime[i], startTime[i], profit[i]};
    sort(jobs.begin(), jobs.end(),
         [](const Job &a, const Job &b) { return a.end < b.end; });

    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int lo = latestNonOverlapping(jobs, i, jobs[i].start);
      dp[i + 1] = max(dp[i], dp[lo] + jobs[i].p);
    }
    return dp[n];
  }
};
// @lc code=end

int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                  vector<int> &profit) {
  Solution sol;
  return sol.jobScheduling(startTime, endTime, profit);
}
