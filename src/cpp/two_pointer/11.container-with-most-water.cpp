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
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1, ans = 0;
        while (l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return ans;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
int maxArea(vector<int>& height) {
    Solution sol;
    return sol.maxArea(height);
}


