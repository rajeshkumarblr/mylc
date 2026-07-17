#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * Difficulty: Medium
 * Category: dp
 * URL: https://leetcode.com/problems/target-sum/
 *
 * Description:
 * You are given an integer array  nums  and an integer  target .
 *  You want to build an  expression  out of nums by adding one of the symbols
 * '+'  and  '-'  before each integer in nums and then concatenate all the
 * integers.
 *          For example, if  nums = [2, 1] , you can add a  '+'  before  2
 * and a  '-'  before  1  and concatenate them to build the expression  "+2-1"
 * .
 *  Return the number of different  expressions  that you can build, which
 * evaluates to  target .
 *   Example 1:
 *  Input:  nums = [1,1,1,1,1], target = 3
 *  Output:  5
 *  Explanation:  There are 5 ways to assign symbols to make the sum of nums
 * be target 3.
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *   Example 2:
 *  Input:  nums = [1], target = 1
 *  Output:  1
 *   Constraints:
 *           1 <= nums.length <= 20
 *           0 <= nums[i] <= 1000
 *           0 <= sum(nums[i]) <= 1000
 *           -1000 <= target <= 1000
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
    int findTargetSumWays(vector<int>& nums, int target) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
