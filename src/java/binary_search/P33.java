package binary_search;
import common.*;



/*
 * @lc app=leetcode id=33 lang=java
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 *
 * Prior to being passed to your function, nums is possibly rotated at an
 * unknown pivot index k (1 <= k < nums.length) such that the resulting array
 * is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
 * (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index
 * 3 and become [4,5,6,7,0,1,2].
 *
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 *
 * Constraints:
 * - 1 <= nums.length <= 5000
 * - -10^4 <= nums[i] <= 10^4
 * - All values of nums are unique.
 * - nums is an ascending array that is possibly rotated.
 * - -10^4 <= target <= 10^4
 */

// @lc code=start
public class P33 {
    public class Solution {
        public int search(int[] nums, int target) {
            int l = 0;
            int r = nums.length - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (nums[m] == target) {
                    return m;
                }

                // Check if left half is sorted
                if (nums[l] <= nums[m]) {
                    if (target >= nums[l] && target < nums[m]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                } else {
                    // Right half must be sorted
                    if (target > nums[m] && target <= nums[r]) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            }
            return -1;
        }
    }
}
// @lc code=end
