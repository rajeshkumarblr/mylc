/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * Difficulty: Easy
 * Category: hash
 * URL: https://leetcode.com/problems/contains-duplicate/
 *
 * Description:
 * Given an integer array  nums , return  true  if any value appears  at least
 * twice  in the array, and return  false  if every element is distinct.
 *   Example 1:
 *   Input:   nums = [1,2,3,1]
 *   Output:   true
 *   Explanation:
 *  The element 1 occurs at the indices 0 and 3.
 *   Example 2:
 *   Input:   nums = [1,2,3,4]
 *   Output:   false
 *   Explanation:
 *  All elements are distinct.
 *   Example 3:
 *   Input:   nums = [1,1,1,3,3,4,3,2,4,2]
 *   Output:   true
 *   Constraints:
 *           1 <= nums.length <= 10 5
 *           -10 9  <= nums[i] <= 10 9
 */

#include "../lc_test_utils.h"
#include <type_traits>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    // std::sort operates directly on the vector's contiguous memory.
    // Zero dynamic allocations = Huge savings in CPU and Memory!
    std::sort(nums.begin(), nums.end());
    
    // Check adjacent elements
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
