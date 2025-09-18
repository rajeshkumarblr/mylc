/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
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
