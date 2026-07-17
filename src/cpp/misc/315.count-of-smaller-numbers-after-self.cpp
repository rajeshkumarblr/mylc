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
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * Problem Description:
 * Given an integer array nums, return an integer array counts where counts[i] 
 * is the number of smaller elements to the right of nums[i].
 *
 * Examples:
 * 1. Input: nums = [5,2,6,1]
 *    Output: [2,1,1,0]
 *    Explanation:
 *    - To the right of 5 there are 2 smaller elements (2 and 1).
 *    - To the right of 2 there is 1 smaller element (1).
 *    - To the right of 6 there is 1 smaller element (1).
 *    - To the right of 1 there is 0 smaller element.
 *
 * 2. Input: nums = [-1]
 *    Output: [0]
 *
 * 3. Input: nums = [-1,-1]
 *    Output: [0,0]
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 */

#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // TODO: Implement solution here
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {5, 2, 6, 1};
        auto got = sol.countSmaller(nums);
        if (got != vector<int>{2, 1, 1, 0}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {-1};
        auto got = sol.countSmaller(nums);
        if (got != vector<int>{0}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> nums = {-1, -1};
        auto got = sol.countSmaller(nums);
        if (got != vector<int>{0, 0}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
