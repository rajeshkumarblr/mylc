#include "../lc_test_utils.h"
#include <vector>

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 *
 * Prior to being passed to your function, nums is possibly rotated at an
 * unknown pivot index k (1 <= k < nums.length) such that the resulting array
 * is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
 * (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index
 * 3 and become [4,5,6,7,0,1,2].
 *
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 *
 * Constraints:
 * - 1 <= nums.length <= 5000
 * - -10^4 <= nums[i] <= 10^4
 * - All values of nums are unique.
 * - nums is an ascending array that is possibly rotated.
 * - -10^4 <= target <= 10^4
 *
 * Description:
 * There is an integer array  nums  sorted in ascending order (with  distinct
 * values).
 *  Prior to being passed to your function,  nums  is  possibly left rotated
 * at an unknown index  k  ( 1 <= k < nums.length ) such that the resulting
 * array is  [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ...,
 * nums[k-1]]  ( 0-indexed ). For example,  [0,1,2,4,5,6,7]  might be left
 * rotated by  3  indices and become  [4,5,6,7,0,1,2] .
 *  Given the array  nums   after  the possible rotation and an integer
 * target , return  the index of   target   if it is in   nums  , or   -1   if
 * it is not in   nums .
 *  You must write an algorithm with  O(log n)  runtime complexity.
 *   Example 1:
 *   Input:  nums = [4,5,6,7,0,1,2], target = 0
 *  Output:  4
 *    Example 2:
 *   Input:  nums = [4,5,6,7,0,1,2], target = 3
 *  Output:  -1
 *    Example 3:
 *   Input:  nums = [1], target = 0
 *  Output:  -1
 *   Constraints:
 *           1 <= nums.length <= 5000
 *           -10 4  <= nums[i] <= 10 4
 *          All values of  nums  are  unique .
 *           nums  is an ascending array that is possibly rotated.
 *           -10 4  <= target <= 10 4
 */

using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) { return search_33(nums, target); }
};

int search_33(std::vector<int> &nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == target) {
      return m;
    }

    // Check if the left half is sorted
    if (nums[l] <= nums[m]) {
      if (nums[l] <= target && target < nums[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    // Otherwise, the right half must be sorted
    else {
      if (nums[m] < target && target <= nums[r]) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
  }
  return -1;
}

bool lc_test_33(const json &j) {
  std::cout << "Running LC33: Search in Rotated Sorted Array ...\n";

  std::vector<int> cases_to_run;
  if (j.contains("cases")) {
    for (size_t i = 0; i < j.at("cases").size(); ++i)
      cases_to_run.push_back(i);
  }

  bool all_passed = true;
  for (int i : cases_to_run) {
    const auto &tc = j.at("cases").at(i);
    std::vector<int> nums = tc.at("nums").get<std::vector<int>>();
    int target = tc.at("target").get<int>();
    int expected = tc.at("expected").get<int>();

    int result = search_33(nums, target);

    if (result != expected) {
      std::cout << "  Case " << i + 1 << " Failed. Expected: " << expected
                << ", Got: " << result << "\n";
      all_passed = false;
    }
  }

  return all_passed;
}
