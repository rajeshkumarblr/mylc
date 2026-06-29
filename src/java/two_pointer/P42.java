package two_pointer;
import common.*;


/*
 * @lc app=leetcode id=42 lang=java
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * Given n non-negative integers representing an elevation map where the
 * width of each bar is 1, compute how much water it can trap after raining.
 *
 * Example 1:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by
 * array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 * Constraints:
 * - n == height.length
 * - 1 <= n <= 2 * 10^4
 * - 0 <= height[i] <= 10^5
 */

public class P42 {
    // @lc code=start
    public class Solution {
        public int trap(int[] height) {
            int n = height.length;
            int i = 0, j = n - 1, leftMax = 0, rightMax = 0, water = 0;
            while (i <= j) {
                if (leftMax <= rightMax) {
                    leftMax = Math.max(leftMax, height[i]);
                    water += leftMax - height[i];
                    i++;
                } else {
                    rightMax = Math.max(rightMax, height[j]);
                    water += rightMax - height[j];
                    j--;
                }
            }
            return water;
        }
    }
    // @lc code=end
}
