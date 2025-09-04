/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 */

 #include <vector>
 #include <cstdlib>
 using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r = height.size()-1;
        int maxContainerArea = 0;
        while (l<r) {
            int a = (r-l) * min(height[l],height[r]);
            maxContainerArea = max(maxContainerArea, a);
            if (height[l] < height[r]) { 
                l++;
             } else { 
                r--;
             }
        }
        return maxContainerArea;
    }
};
// @lc code=end

// Add test harness similar to lc42.cpp
#include <iostream>
#include "lc_test_utils.h"

int main() {
    Solution sol;
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{8,7,2,2},7},
        {{1,8,6,2,5,4,8,3,7}, 49},   // Example 1
        {{1,1}, 1},                  // Example 2
        {{4,3,2,1,4}, 16},           // Custom
        {{1,2,1}, 2},                // Custom
        {{1,2,4,3}, 4},              // Custom
        {{2,3,4,5,18,17,6}, 17},     // Custom
        {{1,3,2,5,25,24,5}, 24},     // Custom
        {{}, 0}                      // Edge case: empty
    };
    bool all_passed = true;
    for (const auto& [input, expected] : tests) {
        int result = sol.maxArea(const_cast<std::vector<int>&>(input));
        all_passed &= print_test_result(input, result, expected);
    }
    std::cout << "\nFinal Result: " << (all_passed ? "PASS" : "FAIL") << std::endl;
    return all_passed ? 0 : 1;
}
