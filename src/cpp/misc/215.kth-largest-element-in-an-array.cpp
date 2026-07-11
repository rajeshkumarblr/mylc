/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
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

#include "../lc_test_utils.h"
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
// @lc code=end

int findKthLargest(vector<int>& nums, int k) {
    Solution sol;
    return sol.findKthLargest(nums, k);
}
