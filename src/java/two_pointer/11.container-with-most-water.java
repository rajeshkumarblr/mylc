class P11 {
    // @lc app=leetcode id=11 lang=java
    // @lc code=start
    public class Solution {
        public int maxArea(int[] height) {
            int i=0, j=height.length-1, best=0;
            while(i<j){
                int area = Math.min(height[i], height[j]) * (j-i);
                if (area>best) best=area;
                if (height[i] < height[j]) i++; else j--;
            }
            return best;
        }
    }
    // @lc code=end
}
