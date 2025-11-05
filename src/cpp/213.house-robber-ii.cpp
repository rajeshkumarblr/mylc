/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        
        // Edge cases
        if (n == 0) return 0;   // No houses
        if (n == 1) return nums[0];  // Only one house
        
        // Two scenarios: exclude first OR exclude last house
        // Take maximum of both scenarios
        return max(robLinear(nums, 0, n-2),     // Houses [0, n-2] (exclude last)
                   robLinear(nums, 1, n-1));    // Houses [1, n-1] (exclude first)
    }
    
private:
    // Linear house robber (same as House Robber I) with start/end indices
    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0;  // Max money 2 houses ago
        int prev1 = 0;  // Max money 1 house ago
        
        for (int i = start; i <= end; i++) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
int rob2(vector<int>& nums) {
    Solution sol;
    return sol.rob(nums);
}

