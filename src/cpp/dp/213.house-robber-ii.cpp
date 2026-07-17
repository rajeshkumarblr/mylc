#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * Difficulty: Medium
 * Category: dp
 * URL: https://leetcode.com/problems/house-robber-ii/
 *
 * Description:
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle.  That means the first house is the neighbor of the
 * last one. Meanwhile, adjacent houses have a security system connected, and
 * it will automatically contact the police if two adjacent houses were broken
 * into on the same night .
 *  Given an integer array  nums  representing the amount of money of each
 * house, return  the maximum amount of money you can rob tonight  without
 * alerting the police  .
 *   Example 1:
 *  Input:  nums = [2,3,2]
 *  Output:  3
 *  Explanation:  You cannot rob house 1 (money = 2) and then rob house 3
 * (money = 2), because they are adjacent houses.
 *   Example 2:
 *  Input:  nums = [1,2,3,1]
 *  Output:  4
 *  Explanation:  Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *   Example 3:
 *  Input:  nums = [1,2,3]
 *  Output:  3
 *   Constraints:
 *           1 <= nums.length <= 100
 *           0 <= nums[i] <= 1000
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {2, 3, 2};
        auto got = sol.rob(nums);
        if (got != 3) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {1, 2, 3, 1};
        auto got = sol.rob(nums);
        if (got != 4) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> nums = {1, 2, 3};
        auto got = sol.rob(nums);
        if (got != 3) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> nums = {1};
        auto got = sol.rob(nums);
        if (got != 1) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> nums = {1, 2};
        auto got = sol.rob(nums);
        if (got != 2) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    // Case 6
    {
        vector<int> nums = {2, 7, 9, 3, 1};
        auto got = sol.rob(nums);
        if (got != 11) {
            cerr << "FAIL case 6" << endl;
            return 1;
        }
    }
    // Case 7
    {
        vector<int> nums = {5, 1, 3, 9};
        auto got = sol.rob(nums);
        if (got != 10) {
            cerr << "FAIL case 7" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
