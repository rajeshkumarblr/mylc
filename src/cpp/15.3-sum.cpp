/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        const int n = (int)nums.size();
        for (int i=0; i<n; i++) {
            // since we have already sorted the array, 
            // anything more than 0 means, whatever follows this, will
            // be positive numbers, so adding them is not going to result
            // in zero, only more than that. so stop here.
            if (nums[i]>0) break;

            // if this is a duplicate of previous element, then continue.
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1, r = n -1;

            while (l < r) {
                long long sum = (long long)nums[i] + nums[l] + nums[r];

                if (sum > 0) {
                    // if sume is greater than 0, it means the current right is
                    // more than what we want, so reduce it by decrementing r.
                    r--;
                } else if (sum < 0) {
                    // if sume is less than 0, it means the current left is
                    // less than what we want, so increase it by incrementing r.
                    l++;
                } else {
                    //we found the triplet that adds up to zero. so add it to res.
                    res.push_back({nums[i],nums[l],nums[r]});

                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
            }
        }
        return res;
    }
};
// @lc code=end

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    Solution sol;
    return sol.threeSum(nums);
}