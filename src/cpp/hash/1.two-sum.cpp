#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nummap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (nummap.find(complement) != nummap.end()) {
                return {nummap[complement], i};
            }
            
            // Store the current number and its index
            nummap[nums[i]] = i;
        }
        return {};
    }
    };
// @lc code=end

// Non-LeetCode wrapper for harness
std::vector<int> twoSum(std::vector<int> &nums, int target) {
  Solution sol;
  return sol.twoSum(nums, target);
}