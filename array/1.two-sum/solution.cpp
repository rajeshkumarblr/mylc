/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <map>
#include <utility>
#include "../../lc_test_utils.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mymap;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            int num = nums[i];
            if (mymap.find(num) != mymap.end())
            {
                return {mymap[num], i};
            }
            mymap[target - num] = i;
        }
        return {};
    }
};

int main()
{
    Solution sol;
    using input_t = pair<vector<int>, int>;
    vector<pair<input_t, vector<int>>> test_cases = {
        { {{2, 7, 11, 15}, 9}, {0, 1} },
        { {{3, 2, 4}, 6}, {1, 2} },
        { {{3, 3}, 6}, {0, 1} },
        { {{1, 2, 3}, 7}, {} }, // No solution
        { {{1, 5, 1, 5}, 10}, {1, 3} }
    };
    auto func = [&](const input_t &in) {
        auto nums = in.first; // make a copy
        return sol.twoSum(nums, in.second);
    };
    return run_vector_tests(test_cases, func) ? 0 : 1;
}
// @lc code=end
