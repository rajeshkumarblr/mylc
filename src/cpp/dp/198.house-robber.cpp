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
int rob(std::vector<int>& nums) {
    Solution sol;
    return sol.rob(nums);
}

