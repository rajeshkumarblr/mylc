#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 *
 * Difficulty: Hard
 * Category: dp
 * URL: https://leetcode.com/problems/burst-balloons/
 *
 * Description:
 * You are given  n  balloons, indexed from  0  to  n - 1 . Each balloon is
 * painted with a number on it represented by an array  nums . You are asked
 * to burst all the balloons.
 *  If you burst the  i th   balloon, you will get  nums[i - 1] * nums[i] *
 * nums[i + 1]  coins. If  i - 1  or  i + 1  goes out of bounds of the array,
 * then treat it as if there is a balloon with a  1  painted on it.
 *  Return  the maximum coins you can collect by bursting the balloons wisely
 * .
 *   Example 1:
 *  Input:  nums = [3,1,5,8]
 *  Output:  167
 *  Explanation:
 * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 * coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 *   Example 2:
 *  Input:  nums = [1,5]
 *  Output:  10
 *   Constraints:
 *           n == nums.length
 *           1 <= n <= 300
 *           0 <= nums[i] <= 100
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
    int maxCoins(vector<int>& nums) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
