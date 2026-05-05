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
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> vec;
    unordered_map<int, int> complements;
    for (int i = 0; i < nums.size(); i++) {
      if (const auto it = complements.find(nums[i]); it != complements.end()) {
        vec = {it->second, i};
        break;
      } else {
        complements[target - nums[i]] = i;
      }
    }
    return vec;
  }
};
// @lc code=end

// Non-LeetCode wrapper for harness
std::vector<int> twoSum(std::vector<int> &nums, int target) {
  Solution sol;
  return sol.twoSum(nums, target);
}