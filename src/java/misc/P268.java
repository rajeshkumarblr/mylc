package misc;

import java.util.*;

public class P268 {
    // @lc app=leetcode id=268 lang=java
    // @lc code=start
    public class Solution {
        public int missingNumber(int[] nums) {
            int len = nums.length;
            int expectedSum = (len * (len + 1)) / 2;
            int sum = 0;
            for (int num : nums) {
                sum += num;
            }
            return expectedSum - sum;
        }
    }
    // @lc code=end

    // Wrapper for compatibility with your driver
    public static int run(int[] nums) {
        return new P268().new Solution().missingNumber(nums);
    }
}
