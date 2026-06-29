package hash;
import common.*;
import java.util.*;

/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * Given an array of integers nums and an integer target, return indices of
 * the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you
 * may not use the same element twice.
 *
 * You can return the answer in any order.
 *
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Constraints:
 * - 2 <= nums.length <= 10^4
 * - -10^9 <= nums[i] <= 10^9
 * - -10^9 <= target <= 10^9
 * - Only one valid answer exists.
 */

public class P1 {
    // @lc code=start
    public static class Solution {
        // Two Sum
        // Time: O(n), Space: O(n)
        public int[] twoSum(int[] nums, int target) {
            Map<Integer, Integer> pos = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                int need = target - nums[i];
                Integer j = pos.get(need);
                if (j != null) {
                    return new int[] { j, i };
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
