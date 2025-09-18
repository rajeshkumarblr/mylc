#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size(),0);

        stack<int> maxTemps;
        for (int ind = 0; ind < (int)temperatures.size(); ind++) {
            while (!maxTemps.empty() && temperatures[ind] > temperatures[maxTemps.top()]) {
                out[maxTemps.top()] = ind - maxTemps.top();
                maxTemps.pop();
            }
            maxTemps.push(ind);
        }
        return out;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
std::vector<int> dailyTemperatures(std::vector<int> temperatures) {
    Solution sol;
    return sol.dailyTemperatures(temperatures);
}

