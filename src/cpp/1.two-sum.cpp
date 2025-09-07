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
#include "lc_test_utils.h"
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
// @lc code=end

static inline std::vector<int> normalize2(std::vector<int> v) {
    if (v.size() == 2 && v[0] > v[1]) std::swap(v[0], v[1]);
    return v;
}

int main() {
    Solution sol;
    using input_t = std::pair<std::vector<int>, int>;
    std::vector<std::pair<input_t, std::vector<int>>> test_cases = {
        { {{2,7,11,15}, 9}, {0,1} },
        { {{3,2,4}, 6},     {1,2} },
        { {{3,3}, 6},       {0,1} },
        { {{1,2,3}, 7},     {} },
        { {{1,5,1,5},10},   {1,3} }
    };

    // normalize all expected pairs once
    for (auto& tc : test_cases) tc.second = normalize2(tc.second);

    auto func = [&](const input_t& in) {
        auto nums = in.first; // copy ok
        auto got  = sol.twoSum(nums, in.second);
        return normalize2(got);
    };

    return run_cases<input_t, std::vector<int>>(test_cases, func) ? 0 : 1;
}