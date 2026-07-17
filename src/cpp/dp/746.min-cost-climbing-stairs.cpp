#include <set>
#include <cmath>
#include <map>
#include <iostream>
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

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
