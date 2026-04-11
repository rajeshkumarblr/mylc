package binary_search;
import common.*;



/*
 * @lc app=leetcode id=33 lang=java
 *
 * [33] Search in Rotated Sorted Array
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
