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

using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        /* At least 3 elements must be there to trap rain water.*/
        if (len <=2) return 0;

        // Fill maxLeft
        vector<int> maxLeft(len,0);
        int maxL = height[0];
        for (int i = 1; i < len; i++) {
            maxL = std::max(maxL, height[i]);
            maxLeft[i] = maxL;
        }

        // Fill maxRight
        vector<int> maxRight(len,0);
        int maxR = height[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            maxR = std::max(maxR, height[i]);
            maxRight[i] = maxR;
        }

        // Now calculate the trapped rain water based on the max left and max right.
        int res = 0;
        for (int i=1; i<len; i++) {
            res += max (0,(min(maxLeft[i], maxRight[i]) - height[i]));
        }
        return res;
    }
};
// @lc code=end

#include <iostream>
#include "../../lc_test_utils.h"

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> tests = {
        {{0,1,0,2,1,0,1,3,2,1,2,1}, 6},
        {{4,2,0,3,2,5}, 9},
        {{1,2,3,4,5}, 0},
        {{5,4,1,2}, 1},
        {{2,0,2}, 2},
        {{}, 0},
        {{0, 10, 0}, 0}
    };
    bool all_passed = true;
    for (auto& [input, expected] : tests) {
        int result = sol.trap(input);
        all_passed &= print_test_result(input, result, expected);
    }
    std::cout << "\nFinal Result: " << (all_passed ? "PASS" : "FAIL") << std::endl;
    return all_passed ? 0 : 1;
}

