package dp;
import common.*;


/*
 * @lc app=leetcode id=213 lang=java
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the
 * last one. Meanwhile, adjacent houses have a security system connected, and
 * it will automatically contact the police if two adjacent houses were broken
 * into on the same night.
 *
 * Given an integer array nums representing the amount of money of each
 * house, return the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 * Example 1:
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3
 * (money = 2), because they are adjacent houses.
 *
 * Example 2:
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 * Example 3:
 * Input: nums = [1,2,3]
 * Output: 3
 *
 * Constraints:
 * - 1 <= nums.length <= 100
 * - 0 <= nums[i] <= 1000
 */

public class P213 {
    // @lc code=start
    public static class Solution {
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

    // Wrapper method for driver compatibility
    public int rob(int[] nums) {
        return new Solution().rob(nums);
    }
}