/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
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
        return trap_twopointer(height);
        //return trap_minmax()
    }

    int trap_twopointer(vector<int>& height) {
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

    int trap_minmax(vector<int>& height) {
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

