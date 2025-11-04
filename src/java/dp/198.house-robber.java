class P198 {
    /*
     * @lc app=leetcode id=198 lang=java
     *
     * [198] House Robber
     */

    // @lc code=start
    public class Solution {
        public int rob(int[] nums) {
            int n = nums.length;
            
            // Edge cases
            if (n == 0) {
                return 0;
            }
            if (n == 1) {
                return nums[0];
            }
            
            // O(1) space optimization: only track last 2 values
            int prev2 = nums[0];                        // dp[i-2]
            int prev1 = Math.max(nums[0], nums[1]);     // dp[i-1]
            
            for (int i = 2; i < n; i++) {
                int current = Math.max(prev1, prev2 + nums[i]);
                prev2 = prev1;      // Slide window
                prev1 = current;    // Slide window
            }
            
            return prev1;
        }
    }
    // @lc code=end
}