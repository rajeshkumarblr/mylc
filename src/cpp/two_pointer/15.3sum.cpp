#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * Difficulty: Medium
 * Category: two_pointer
 * URL: https://leetcode.com/problems/3sum/
 *
 * Description:
 * Given an integer array nums, return all the triplets  [nums[i], nums[j],
 * nums[k]]  such that  i != j ,  i != k , and  j != k , and  nums[i] +
 * nums[j] + nums[k] == 0 .
 *  Notice that the solution set must not contain duplicate triplets.
 *   Example 1:
 *  Input:  nums = [-1,0,1,2,-1,-4]
 *  Output:  [[-1,-1,2],[-1,0,1]]
 *  Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 *   Example 2:
 *  Input:  nums = [0,1,1]
 *  Output:  []
 *  Explanation:  The only possible triplet does not sum up to 0.
 *   Example 3:
 *  Input:  nums = [0,0,0]
 *  Output:  [[0,0,0]]
 *  Explanation:  The only possible triplet sums up to 0.
 *   Constraints:
 *           3 <= nums.length <= 3000
 *           -10 5  <= nums[i] <= 10 5
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        auto got = sol.threeSum(nums);
        if (got != vector<vector<int>>{{-1, -1, 2}, {-1, 0, 1}}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {0, 1, 1};
        auto got = sol.threeSum(nums);
        if (got != vector<vector<int>>{}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> nums = {0, 0, 0};
        auto got = sol.threeSum(nums);
        if (got != vector<vector<int>>{{0, 0, 0}}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> nums = {-2, 0, 1, 1, 2};
        auto got = sol.threeSum(nums);
        if (got != vector<vector<int>>{{-2, 0, 2}, {-2, 1, 1}}) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
