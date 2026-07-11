/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * Problem Description:
 * Given an integer array nums, handle multiple queries of two types:
 * 1. Update the value of an element in nums.
 * 2. Calculate the sum of the elements of nums between indices left and right 
 *    inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 *
 * Implement the NumArray class:
 * - NumArray(vector<int>& nums) Initializes the object with the integer array nums.
 * - void update(int index, int val) Updates the value of nums[index] to be val.
 * - int sumRange(int left, int right) Returns the sum of the elements of nums 
 *   between indices left and right inclusive.
 *
 * Examples:
 * Input:
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * Output:
 * [null, 9, null, 8]
 *
 * Explanation:
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
 * numArray.update(1, 2);   // nums = [1, 2, 5]
 * numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 *
 * Constraints:
 * - 1 <= nums.length <= 3 * 10^4
 * - -100 <= nums[i] <= 100
 * - 0 <= index < nums.length
 * - -100 <= val <= 100
 * - 0 <= left <= right < nums.length
 * - At most 3 * 10^4 calls will be made to update and sumRange.
 */

#include "../lc_test_utils.h"
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        // TODO: Initialize your data structures
    }
    
    void update(int index, int val) {
        // TODO: Update value at index to val
    }
    
    int sumRange(int left, int right) {
        // TODO: Query range sum
        return 0;
    }
};
// @lc code=end

vector<string> runRangeSumQuery(const vector<string> &cmds, const json &args) {
    NumArray *na = nullptr;
    vector<string> res;
    for (size_t i = 0; i < cmds.size(); ++i) {
        if (cmds[i] == "NumArray") {
            vector<int> nums = args[i][0].get<vector<int>>();
            na = new NumArray(nums);
            res.push_back("null");
        } else if (cmds[i] == "update") {
            int index = args[i][0].get<int>();
            int val = args[i][1].get<int>();
            na->update(index, val);
            res.push_back("null");
        } else if (cmds[i] == "sumRange") {
            int left = args[i][0].get<int>();
            int right = args[i][1].get<int>();
            res.push_back(to_string(na->sumRange(left, right)));
        }
    }
    delete na;
    return res;
}
