#include <vector>
#include <unordered_map>

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

using namespace std;

#ifndef LC_LOCAL_TEST
class Solution
{
    public:
#endif

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int,int> pos;
    for (int i = 0; i < (int)nums.size(); ++i) {
        int want = target - nums[i];
        auto it = pos.find(want);
        if (it != pos.end()) return {it->second, i};
        pos[nums[i]] = i;
    }
    return {};
}

#ifndef LC_LOCAL_TEST
};
#endif 
// @lc code=end