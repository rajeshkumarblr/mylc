#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 *
 * Difficulty: Easy
 * Category: dp
 * URL: https://leetcode.com/problems/min-cost-climbing-stairs/
 *
 * Description:
 * You are given an integer array  cost  where  cost[i]  is the cost of  i th
 * step on a staircase. Once you pay the cost, you can either climb one or two
 * steps.
 *  You can either start from the step with index  0 , or the step with index
 * 1 .
 *  Return  the minimum cost to reach the top of the floor .
 *   Example 1:
 *  Input:  cost = [10, 15 ,20]
 *  Output:  15
 *  Explanation:  You will start at index 1.
 * - Pay 15 and climb two steps to reach the top.
 * The total cost is 15.
 *   Example 2:
 *  Input:  cost = [ 1 ,100, 1 ,1, 1 ,100, 1 , 1 ,100, 1 ]
 *  Output:  6
 *  Explanation:  You will start at index 0.
 * - Pay 1 and climb two steps to reach index 2.
 * - Pay 1 and climb two steps to reach index 4.
 * - Pay 1 and climb two steps to reach index 6.
 * - Pay 1 and climb one step to reach index 7.
 * - Pay 1 and climb two steps to reach index 9.
 * - Pay 1 and climb one step to reach the top.
 * The total cost is 6.
 *   Constraints:
 *           2 <= cost.length <= 1000
 *           0 <= cost[i] <= 999
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
  }
};
// @lc code=end

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  try {
    json j = json::parse(R"raw({
      "cases": [
        {
          "cost": [10, 15, 20],
          "expected": 15
        },
        {
          "cost": [1, 100, 1, 1, 1, 100, 1, 1, 100, 1],
          "expected": 6
        }
      ]
    })raw");
    for (auto &tc : j.at("cases")) {
      vector<int> cost = tc.at("cost").get<vector<int>>();
      int expected = tc.at("expected").get<int>();
      Solution sol;
      int got = sol.minCostClimbingStairs(cost);
      if (got != expected) {
        cerr << "FAIL: got " << got << ", expected " << expected << endl;
        return 1;
      }
    }
    cout << "PASS" << endl;
    return 0;
  } catch (const exception &e) {
    cerr << "Exception: " << e.what() << endl;
    return 1;
  }
}
