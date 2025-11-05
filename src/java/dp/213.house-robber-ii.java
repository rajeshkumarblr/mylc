/*
 * @lc app=leetcode id=213 lang=java
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        
        // Edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Two scenarios: exclude first OR exclude last house
        // Take maximum of both scenarios
        return Math.max(robLinear(nums, 0, n - 2),     // Houses [0, n-2] (exclude last)
                        robLinear(nums, 1, n - 1));    // Houses [1, n-1] (exclude first)
    }
    
    // Linear house robber (same as House Robber I) with start/end indices
    private int robLinear(int[] nums, int start, int end) {
        int prev2 = 0;  // Max money 2 houses ago
        int prev1 = 0;  // Max money 1 house ago
        
        for (int i = start; i <= end; i++) {
            int current = Math.max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
}
// @lc code=end

// Wrapper class for test harness
class P213 {
    Solution solution = new Solution();
    
    public int rob(int[] nums) {
        return solution.rob(nums);
    }
}