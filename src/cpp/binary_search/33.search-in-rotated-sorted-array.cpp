#include <unordered_set>
#include <queue>
#include <unordered_map>
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
using namespace std;

int search_33(std::vector<int> &nums, int target);


int search_33(std::vector<int> &nums, int target);


int search_33(std::vector<int> &nums, int target);


int search_33(std::vector<int> &nums, int target);


int search_33(std::vector<int> &nums, int target);


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

class Solution {
public:
  int search(vector<int> &nums, int target) { return search_33(nums, target); }
};
// @lc code=end

















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






int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        auto got = sol.search(nums, target);
        if (got != 4) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 3;
        auto got = sol.search(nums, target);
        if (got != -1) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> nums = {1};
        int target = 0;
        auto got = sol.search(nums, target);
        if (got != -1) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
