/*
 * @lc app=leetcode id=9 lang=cpp
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

// @lc code=start


// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int orig = x, rev = 0;
        while (x) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return orig == rev;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
bool isPalindrome(int x) {
    Solution sol;
    return sol.isPalindrome(x);
}
