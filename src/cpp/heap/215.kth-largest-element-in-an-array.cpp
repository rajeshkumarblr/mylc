#include <map>
#include <utility>
#include <iostream>
#include <cmath>
#include <set>
/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element In An Array
 *
 * Difficulty: Medium
 * Category: heap
 * URL: https://leetcode.com/problems/kth-largest-element-in-an-array/
 *
 * Description:
 * Given an integer array  nums  and an integer  k , return  the   k th
 * largest element in the array .
 *  Note that it is the  k th   largest element in the sorted order, not the
 * k th   distinct element.
 *  Can you solve it without sorting?
 *   Example 1:
 *   Input:  nums = [3,2,1,5,6,4], k = 2
 *  Output:  5
 *    Example 2:
 *   Input:  nums = [3,2,3,1,2,4,5,5,6], k = 4
 *  Output:  4
 *   Constraints:
 *           1 <= k <= nums.length <= 10 5
 *           -10 4  <= nums[i] <= 10 4
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
    int findKthLargest(vector<int>& nums, int k) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {3, 2, 1, 5, 6, 4};
        int k = 2;
        auto got = sol.findKthLargest(nums, k);
        if (got != 5) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        int k = 4;
        auto got = sol.findKthLargest(nums, k);
        if (got != 4) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
