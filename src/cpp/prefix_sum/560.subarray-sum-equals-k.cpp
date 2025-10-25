#include <vector>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Empty prefix sum
        
        int count = 0;
        int prefixSum = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            // Check if (prefixSum - k) exists
            if (prefixSumCount.count(prefixSum - k)) {
                count += prefixSumCount[prefixSum - k];
            }
            
            // Add current prefixSum to map
            prefixSumCount[prefixSum]++;
        }
        
        return count;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
int subarraySum(std::vector<int>& nums, int k) {
    Solution sol;
    return sol.subarraySum(nums, k);
}