/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start


// @lc code=start
#ifndef LC_LOCAL_TEST
class Solution {
public:
#endif
bool isPalindrome(int x) {
    if (x < 0) return false;
    int orig = x, rev = 0;
    while (x) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return orig == rev;
}
#ifndef LC_LOCAL_TEST
};
#endif
// @lc code=end
