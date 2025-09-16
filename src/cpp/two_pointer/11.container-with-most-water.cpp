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

/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#ifndef LC_LOCAL_TEST
class Solution {
public:
#endif

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1, ans = 0;
    while (l < r) {
        ans = max(ans, (r - l) * min(height[l], height[r]));
        if (height[l] < height[r]) ++l;
        else --r;
    }
    return ans;
}


#ifndef LC_LOCAL_TEST
};
#endif
// @lc code=end


