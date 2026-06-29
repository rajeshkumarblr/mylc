/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Kth Smallest Element in an Array
 */

#include "../lc_test_utils.h"
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for (int num : nums) {
            maxHeap.push(num);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};
// @lc code=end

int findKthSmallest(vector<int>& nums, int k) {
    Solution sol;
    return sol.findKthSmallest(nums, k);
}
