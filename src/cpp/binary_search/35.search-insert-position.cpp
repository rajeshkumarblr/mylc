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

/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be if
 * it were inserted in order.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Example 1:
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 *
 * Example 2:
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 *
 * Example 3:
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 *
 * Constraints:
 * - 1 <= nums.length <= 10^4
 * - -10^4 <= nums[i] <= 10^4
 * - nums contains distinct values sorted in ascending order.
 * - -10^4 <= target <= 10^4
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};
// @lc code=end
















// Non-LeetCode wrapper for harness





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {1, 3, 5, 6};
        int target = 5;
        auto got = sol.searchInsert(nums, target);
        if (got != 2) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {1, 3, 5, 6};
        int target = 2;
        auto got = sol.searchInsert(nums, target);
        if (got != 1) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> nums = {1, 3, 5, 6};
        int target = 7;
        auto got = sol.searchInsert(nums, target);
        if (got != 4) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> nums = {1, 3, 5, 6};
        int target = 0;
        auto got = sol.searchInsert(nums, target);
        if (got != 0) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
