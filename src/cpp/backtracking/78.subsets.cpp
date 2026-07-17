#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * Difficulty: Medium
 * Category: backtracking
 * URL: https://leetcode.com/problems/subsets/
 *
 * Description:
 * Given an integer array  nums  of  unique  elements, return  all possible
 * subsets    (the power set) .
 *  The solution set  must not  contain duplicate subsets. Return the solution
 * in  any order .
 *   Example 1:
 *  Input:  nums = [1,2,3]
 *  Output:  [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *   Example 2:
 *  Input:  nums = [0]
 *  Output:  [[],[0]]
 *   Constraints:
 *           1 <= nums.length <= 10
 *           -10 <= nums[i] <= 10
 *          All the numbers of  nums  are  unique .
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
