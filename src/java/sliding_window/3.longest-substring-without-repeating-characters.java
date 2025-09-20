class P3 {
    // @lc app=leetcode id=3 lang=java
    // @lc code=start
    public class Solution {
        public int lengthOfLongestSubstring(String s) {
            int[] last = new int[256];
            java.util.Arrays.fill(last, -1);
            int best = 0, start = 0;
            for (int i = 0; i < s.length(); i++) {
                int c = s.charAt(i);
                if (last[c] >= start) start = last[c] + 1;
                last[c] = i;
                best = Math.max(best, i - start + 1);
            }
            return best;
        }
    }
    // @lc code=end
}
