import java.util.*;

// @lc app=leetcode id=1 lang=java

public class P1 {
    // @lc code=start
    static class Solution {
        // Two Sum
        // Time: O(n), Space: O(n)
        public int[] twoSum(int[] nums, int target) {
            Map<Integer, Integer> pos = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                int need = target - nums[i];
                Integer j = pos.get(need);
                if (j != null) {
                    return new int[]{j, i};
                }
                pos.put(nums[i], i);
            }
            return new int[0];
        }
    }
    // @lc code=end

    // Wrapper method for driver compatibility
    public int[] twoSum(int[] nums, int target) {
        return new Solution().twoSum(nums, target);
    }
}
