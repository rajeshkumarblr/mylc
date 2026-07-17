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
/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 *
 * Description:
 * You are given an integer array  height  of length  n . There are  n
 * vertical lines drawn such that the two endpoints of the  i th   line are
 * (i, 0)  and  (i, height[i]) .
 *  Find two lines that together with the x-axis form a container, such that
 * the container contains the most water.
 *  Return  the maximum amount of water a container can store .
 *   Notice  that you may not slant the container.
 *   Example 1:
 *  Input:  height = [1,8,6,2,5,4,8,3,7]
 *  Output:  49
 *  Explanation:  The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 *   Example 2:
 *  Input:  height = [1,1]
 *  Output:  1
 *   Constraints:
 *           n == height.length
 *           2 <= n <= 10 5
 *           0 <= height[i] <= 10 4
 */

 #include <vector>
 #include <cstdlib>
using namespace std;

/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * You are given an integer array height of length n. There are n vertical
 * lines drawn such that the two endpoints of the ith line are (i, 0) and
 * (i, height[i]).
 *
 * Find two lines that, together with the x-axis, form a container, such
 * that the container contains the most water.
 *
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container.
 *
 * Example 1:
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section)
 * the container can contain is 49.
 *
 * Example 2:
 * Input: height = [1,1]
 * Output: 1
 *
 * Constraints:
 * - n == height.length
 * - 2 <= n <= 10^5
 * - 0 <= height[i] <= 10^4
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







int main() {
    Solution sol;
    // Case 1
    {
        vector<int> input = {8, 7, 2, 2};
        auto got = sol.maxArea(input);
        if (got != 7) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        auto got = sol.maxArea(input);
        if (got != 49) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> input = {1, 1};
        auto got = sol.maxArea(input);
        if (got != 1) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> input = {4, 3, 2, 1, 4};
        auto got = sol.maxArea(input);
        if (got != 16) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> input = {1, 2, 1};
        auto got = sol.maxArea(input);
        if (got != 2) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    // Case 6
    {
        vector<int> input = {1, 2, 4, 3};
        auto got = sol.maxArea(input);
        if (got != 4) {
            cerr << "FAIL case 6" << endl;
            return 1;
        }
    }
    // Case 7
    {
        vector<int> input = {2, 3, 4, 5, 18, 17, 6};
        auto got = sol.maxArea(input);
        if (got != 17) {
            cerr << "FAIL case 7" << endl;
            return 1;
        }
    }
    // Case 8
    {
        vector<int> input = {1, 3, 2, 5, 25, 24, 5};
        auto got = sol.maxArea(input);
        if (got != 24) {
            cerr << "FAIL case 8" << endl;
            return 1;
        }
    }
    // Case 9
    {
        vector<int> input = {};
        auto got = sol.maxArea(input);
        if (got != 0) {
            cerr << "FAIL case 9" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
