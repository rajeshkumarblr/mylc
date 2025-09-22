#include <vector>
#include <unordered_map>
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
        unordered_map<int,int> pos;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int want = target - nums[i];
            auto it = pos.find(want);
            if (it != pos.end()) return {it->second, i};
            pos[nums[i]] = i;
        }
        return {};
    }
    };
// @lc code=end

// Non-LeetCode wrapper for harness
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    Solution sol;
    return sol.twoSum(nums, target);
}