/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * Given n non-negative integers representing an elevation map where the
 * width of each bar is 1, compute how much water it can trap after raining.
 *
 * Example 1:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by
 * array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 * Constraints:
 * - n == height.length
 * - 1 <= n <= 2 * 10^4
 * - 0 <= height[i] <= 10^5
 *
 * Description:
 * Given  n  non-negative integers representing an elevation map where the
 * width of each bar is  1 , compute how much water it can trap after raining.
 *   Example 1:
 *  Input:  height = [0,1,0,2,1,0,1,3,2,1,2,1]
 *  Output:  6
 *  Explanation:  The above elevation map (black section) is represented by
 * array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *   Example 2:
 *  Input:  height = [4,2,0,3,2,5]
 *  Output:  9
 *   Constraints:
 *           n == height.length
 *           1 <= n <= 2 * 10 4
 *           0 <= height[i] <= 10 5
 */

#include <vector>
#include <iostream>
#include "lc_test_utils.h"

using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int len = (int)height.size();
        if (len <=2) return 0;

        int l = 0, r = len - 1, res = 0;

        //initialize the leftMax to the leftmost array item.
        int leftMax = height[l];

        //initialize the rightMax to the rightMost array item.
        int rightMax = height[r];

        // Loop until left and right cross over.
    while (l < r) {

            // If the current max left we have seen  is lesser
            // than the current max right, then increment left.
            // we get the water in current position by subtracting
            // the height of current item from leftmax, because leftMax
            // is lesser than the right side's max, we only need that
            // to calculate. the same logic applies for the right side as well.
            if (leftMax < rightMax) {
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
        int len = (int)height.size();
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


// Non-LeetCode wrapper for harness
int trap(std::vector<int>& height) {
    Solution sol;
    return sol.trap(height);
}

