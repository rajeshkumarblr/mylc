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
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * Given an array of integers nums and an integer target, return indices of
 * the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you
 * may not use the same element twice.
 *
 * You can return the answer in any order.
 *
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Constraints:
 * - 2 <= nums.length <= 10^4
 * - -10^9 <= nums[i] <= 10^9
 * - -10^9 <= target <= 10^9
 * - Only one valid answer exists.
 *
 * Description:
 * Given an array of integers  nums  and an integer  target , return  indices
 * of the two numbers such that they add up to  target  .
 *  You may assume that each input would have   exactly  one solution , and
 * you may not use the  same  element twice.
 *  You can return the answer in any order.
 *   Example 1:
 *  Input:  nums = [2,7,11,15], target = 9
 *  Output:  [0,1]
 *  Explanation:  Because nums[0] + nums[1] == 9, we return [0, 1].
 *   Example 2:
 *  Input:  nums = [3,2,4], target = 6
 *  Output:  [1,2]
 *   Example 3:
 *  Input:  nums = [3,3], target = 6
 *  Output:  [0,1]
 *   Constraints:
 *           2 <= nums.length <= 10 4
 *           -10 9  <= nums[i] <= 10 9
 *           -10 9  <= target <= 10 9
 *           Only one valid answer exists.
 *  Follow-up:  Can you come up with an algorithm that is less than  O(n 2 )
 * time complexity?
 */

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> complements;
    for (int i = 0; i < nums.size(); i++) {
      if (const auto it = complements.find(nums[i]); it != complements.end()) {
        return {it->second, i};
      } else {
        complements[target - nums[i]] = i;
      }
    }
    return {};
  }
};
// @lc code=end
















// Non-LeetCode wrapper for harness





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> input = {2, 7, 11, 15};
        int target = 9;
        auto got = sol.twoSum(input, target);
        if (got != vector<int>{0, 1}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> input = {3, 2, 4};
        int target = 6;
        auto got = sol.twoSum(input, target);
        if (got != vector<int>{1, 2}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
