/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (65.63%)
 * Likes:    34781
 * Dislikes: 629
 * Total Accepted:    3M
 * Total Submissions: 4.6M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

#include <vector>
#include <iostream>
#include "lc_test_utils.h"

using namespace std;


// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len <=2) return 0;

        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        int leftMax = height[l];
        int rightMax = height[r];
        while (l < r) {
            if (leftMax <= rightMax)
            {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> tests = {
        {{0,1,0,2,1,0,1,3,2,1,2,1}, 6},
        {{4,2,0,3,2,5}, 9},
        {{1,2,3,4,5}, 0},
        {{5,4,1,2}, 1},
        {{2,0,2}, 2},
        {{}, 0}
    };
    bool all_passed = true;
    for (const auto& [input, expected] : tests) {
        int result = sol.trap(const_cast<vector<int>&>(input));
        all_passed &= print_test_result(input, result, expected);
    }
    std::cout << "\nFinal Result: " << (all_passed ? "PASS" : "FAIL") << std::endl;
    return all_passed ? 0 : 1;
}

