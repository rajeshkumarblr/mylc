/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
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

