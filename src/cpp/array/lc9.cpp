/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        // For odd digits, ignore the middle digit
        return x == reversed || x == reversed / 10;
    }
};
// @lc code=end

#include <vector>
#include "lc_test_utils.h"
using namespace std;
int main() {
    Solution sol;
    vector<pair<int, bool>> tests = {
        {121, true},
        {-121, false},
        {10, false},
        {0, true},
        {12321, true},
        {123, false}
    };
    bool all_passed = run_bool_tests(tests, [&](int x) { return sol.isPalindrome(x); });
    return all_passed ? 0 : 1;
}

