#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <utility>
using namespace std;
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





int main() {
    Solution sol;
    // Case 1
    {
        int input = 121;
        auto got = sol.isPalindrome(input);
        if (got != true) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        int input = -121;
        auto got = sol.isPalindrome(input);
        if (got != false) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        int input = 10;
        auto got = sol.isPalindrome(input);
        if (got != false) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        int input = 0;
        auto got = sol.isPalindrome(input);
        if (got != true) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        int input = 12321;
        auto got = sol.isPalindrome(input);
        if (got != true) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    // Case 6
    {
        int input = 123;
        auto got = sol.isPalindrome(input);
        if (got != false) {
            cerr << "FAIL case 6" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
