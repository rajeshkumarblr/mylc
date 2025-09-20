class P42 {
    // @lc app=leetcode id=42 lang=java
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
