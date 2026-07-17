#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security
 * systems connected and it will automatically contact the police if two
 * adjacent houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each
 * house, return the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 * Example 2:
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 7) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 7 + 1 = 12.
 *
 * Constraints:
 * - 1 <= nums.length <= 100
 * - 0 <= nums[i] <= 400
 *
 * Description:
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security systems
 * connected and  it will automatically contact the police if two adjacent
 * houses were broken into on the same night .
 *  Given an integer array  nums  representing the amount of money of each
 * house, return  the maximum amount of money you can rob tonight  without
 * alerting the police  .
 *   Example 1:
 *  Input:  nums = [1,2,3,1]
 *  Output:  4
 *  Explanation:  Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *   Example 2:
 *  Input:  nums = [2,7,9,3,1]
 *  Output:  12
 *  Explanation:  Rob house 1 (money = 2), rob house 3 (money = 9) and rob
 * house 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *   Constraints:
 *           1 <= nums.length <= 100
 *           0 <= nums[i] <= 400
 */
#include "string.h"
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        
        // Edge cases
        if (n == 0) return 0;           // No houses
        if (n == 1) return nums[0];     // Only 1 house
        
        // Option 2: Constant Space O(1) - BEST for memory!
        // We only need the last 2 values: dp[i-2] and dp[i-1]
        int prev2 = nums[0];                    // dp[i-2] 
        int prev1 = max(nums[0], nums[1]);      // dp[i-1]
        
        for (int i = 2; i < n; i++) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;    // Slide the window
            prev1 = current;  // Slide the window
        }
        
        return prev1;  // This holds the maximum money
    }
};
// @lc code=end
















// Non-LeetCode wrapper for harness






int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {1};
        auto got = sol.rob(nums);
        if (got != 1) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {2, 1};
        auto got = sol.rob(nums);
        if (got != 2) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> nums = {1, 2};
        auto got = sol.rob(nums);
        if (got != 2) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> nums = {2, 7, 9, 3, 1};
        auto got = sol.rob(nums);
        if (got != 12) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> nums = {1, 2, 3, 1};
        auto got = sol.rob(nums);
        if (got != 4) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    // Case 6
    {
        vector<int> nums = {5, 1, 3, 9};
        auto got = sol.rob(nums);
        if (got != 14) {
            cerr << "FAIL case 6" << endl;
            return 1;
        }
    }
    // Case 7
    {
        vector<int> nums = {2, 1, 1, 2};
        auto got = sol.rob(nums);
        if (got != 4) {
            cerr << "FAIL case 7" << endl;
            return 1;
        }
    }
    // Case 8
    {
        vector<int> nums = {5, 5, 10, 100, 10, 5};
        auto got = sol.rob(nums);
        if (got != 110) {
            cerr << "FAIL case 8" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
