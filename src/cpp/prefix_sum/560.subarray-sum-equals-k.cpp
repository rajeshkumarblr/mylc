#include <unordered_set>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * Given an array of integers nums and an integer k, return the total number
 * of continuous subarrays whose sum equals k.
 *
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 *
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 *
 * Constraints:
 * - 1 <= nums.length <= 2 * 10^4
 * - -1000 <= nums[i] <= 1000
 * - -10^7 <= k <= 10^7
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





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {1, 1, 1};
        int k = 2;
        auto got = sol.subarraySum(nums, k);
        if (got != 2) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {1, 2, 3};
        int k = 3;
        auto got = sol.subarraySum(nums, k);
        if (got != 2) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
