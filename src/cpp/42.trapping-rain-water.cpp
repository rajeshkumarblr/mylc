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
        //return trap_minmax(height);
    }

    int trap_twopointer(vector<int>& height) {
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

#include <vector>
#include "lc_test_utils.h"
using namespace std;

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

    auto fn = [&](vector<int>& v) { return sol.trap(v); };
    const int iters = lc_env_iters(); // default 1; override with LC_STRESS_ITERS
    const bool ok = run_vec_cases<vector<int>, int>(tests, fn, iters);
    std::cout << "\nFinal Result: " << (ok ? "PASS" : "FAIL") << std::endl;
    return ok ? 0 : 1;
}

