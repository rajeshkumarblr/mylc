#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 *
 * Difficulty: Easy
 * Category: binary_search
 * URL: https://leetcode.com/problems/binary-search/
 *
 * Description:
 * Given an array of integers  nums  which is sorted in ascending order, and
 * an integer  target , write a function to search  target  in  nums . If
 * target  exists, then return its index. Otherwise, return  -1 .
 *  You must write an algorithm with  O(log n)  runtime complexity.
 *   Example 1:
 *  Input:  nums = [-1,0,3,5,9,12], target = 9
 *  Output:  4
 *  Explanation:  9 exists in nums and its index is 4
 *   Example 2:
 *  Input:  nums = [-1,0,3,5,9,12], target = 2
 *  Output:  -1
 *  Explanation:  2 does not exist in nums so return -1
 *   Constraints:
 *           1 <= nums.length <= 10 4
 *           -10 4  < nums[i], target < 10 4
 *          All the integers in  nums  are  unique .
 *           nums  is sorted in ascending order.
 */

#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (target < nums[m]) {
        r = m - 1;
      } else if (target > nums[m]) {
        l = m + 1;
      } else {
        return m;
      }
    }
    return -1;
  }
};
// @lc code=end
















// Non-LeetCode wrapper for harness





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {-1, 0, 3, 5, 9, 12};
        int target = 9;
        auto got = sol.search(nums, target);
        if (got != 4) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {-1, 0, 3, 5, 9, 12};
        int target = 2;
        auto got = sol.search(nums, target);
        if (got != -1) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
