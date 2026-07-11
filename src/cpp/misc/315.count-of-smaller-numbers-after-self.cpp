/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * Problem Description:
 * Given an integer array nums, return an integer array counts where counts[i] 
 * is the number of smaller elements to the right of nums[i].
 *
 * Examples:
 * 1. Input: nums = [5,2,6,1]
 *    Output: [2,1,1,0]
 *    Explanation:
 *    - To the right of 5 there are 2 smaller elements (2 and 1).
 *    - To the right of 2 there is 1 smaller element (1).
 *    - To the right of 6 there is 1 smaller element (1).
 *    - To the right of 1 there is 0 smaller element.
 *
 * 2. Input: nums = [-1]
 *    Output: [0]
 *
 * 3. Input: nums = [-1,-1]
 *    Output: [0,0]
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 */

#include "../lc_test_utils.h"
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // TODO: Implement solution here
        return {};
    }
};
// @lc code=end

vector<int> countSmaller(vector<int>& nums) {
    Solution sol;
    return sol.countSmaller(nums);
}
