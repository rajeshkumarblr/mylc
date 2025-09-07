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
    int maxArea(const vector<int>& height) {
        int n = static_cast<int>(height.size());
        if (n < 2) return 0;
        
        int l = 0, r = n - 1, maxarea = 0;
        while (l < r) {
            // calculate the area between the current left and right bars.
            int a = (r - l) * min(height[l], height[r]);

            // update the maxarea, if this is the biggest we have seen so far.
            maxarea = max(maxarea, a);

            // update the current l or r based on which one is higher.
            if (height[l] < height[r]) { 
                l++;
             } else { 
                r--;
             }
        }
        return maxarea;
    }
};
// @lc code=end

#include "lc_test_utils.h"

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> tests = {
        {{8,7,2,2},7},
        {{1,8,6,2,5,4,8,3,7}, 49},
        {{1,1}, 1},
        {{4,3,2,1,4}, 16},
        {{1,2,1}, 2},
        {{1,2,4,3}, 4},
        {{2,3,4,5,18,17,6}, 17},
        {{1,3,2,5,25,24,5}, 24},
        {{}, 0}
    };

    auto fn = [&](const vector<int>& v) { return sol.maxArea(v); };
    const int iters = lc_env_iters();
    const bool ok = run_vec_cases<vector<int>, int>(tests, fn, iters);
    std::cout << "\nFinal Result: " << (ok ? "PASS" : "FAIL") << std::endl;
    return ok ? 0 : 1;
}