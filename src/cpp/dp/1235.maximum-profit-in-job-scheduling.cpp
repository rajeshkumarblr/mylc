#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <cmath>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 *
 * https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
 *
 * We have n jobs, where every job is scheduled to be done from startTime[i]
 * to endTime[i], obtaining a profit of profit[i].
 *
 * You're given the startTime, endTime and profit arrays, return the maximum
 * profit you can take such that there are no two jobs in the subset with
 * overlapping time range.
 *
 * If you choose a job that ends at time X you will be able to start another
 * job that starts at time X.
 *
 * Example 1:
 * Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 * Output: 120
 * Explanation: The subset chosen is the first and fourth job.
 * Time range [1-3] + [3-6] , we get profit of 50 + 70 = 120.
 *
 * Example 2:
 * Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
 * [20,20,100,70,60]
 * Output: 150
 * Explanation: The subset chosen is the first, fourth and fifth job.
 * Profit obtained 20 + 70 + 60 = 150.
 *
 * Example 3:
 * Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
 * Output: 6
 *
 * Constraints:
 * - 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
 * - 1 <= startTime[i] < endTime[i] <= 10^9
 * - 1 <= profit[i] <= 10^4
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





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> startTime = {1, 2, 3, 3};
        vector<int> endTime = {3, 4, 5, 6};
        vector<int> profit = {50, 10, 40, 70};
        auto got = sol.jobScheduling(startTime, endTime, profit);
        if (got != 120) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> startTime = {1, 2, 3, 4, 6};
        vector<int> endTime = {3, 5, 10, 6, 9};
        vector<int> profit = {20, 20, 100, 70, 60};
        auto got = sol.jobScheduling(startTime, endTime, profit);
        if (got != 150) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> startTime = {1, 1, 1};
        vector<int> endTime = {2, 3, 4};
        vector<int> profit = {5, 6, 4};
        auto got = sol.jobScheduling(startTime, endTime, profit);
        if (got != 6) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> startTime = {4, 2, 4, 8, 2};
        vector<int> endTime = {5, 5, 5, 10, 8};
        vector<int> profit = {1, 2, 8, 10, 4};
        auto got = sol.jobScheduling(startTime, endTime, profit);
        if (got != 18) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
