package misc;
import common.*;


/*
 * @lc app=leetcode id=9 lang=java
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 *
 * Example 1:
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 *
 * Example 2:
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 *
 * Example 3:
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 * Constraints:
 * - -2^31 <= x <= 2^31 - 1
 */

public class P9 {
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
