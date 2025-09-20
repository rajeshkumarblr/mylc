class P9 {
    // @lc app=leetcode id=9 lang=java
    // @lc code=start
    public class Solution {
        public boolean isPalindrome(int x) {
            if (x < 0) return false;
            if (x >= 0 && x < 10) return true;
            if (x % 10 == 0) return x == 0;
            int rev = 0;
            int n = x;
            while (n > 0) {
                rev = rev * 10 + (n % 10);
                n /= 10;
            }
            return rev == x;
        }
    }
    // @lc code=end
}
