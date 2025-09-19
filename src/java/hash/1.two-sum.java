import java.util.*;

// @lc app=leetcode id=1 lang=java
// @lc code=start
class Solution {
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

// Minimal local wrapper used by harness driver (keeps problem file focused)
class P1_TwoSum {
    int[] twoSum_local(int[] nums, int target) {
        return new Solution().twoSum(nums, target);
    }
}
