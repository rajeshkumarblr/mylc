#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * Description:
 * Given an array of integers  temperatures  represents the daily
 * temperatures, return  an array   answer   such that   answer[i]   is the
 * number of days you have to wait after the   i th    day to get a warmer
 * temperature . If there is no future day for which this is possible, keep
 * answer[i] == 0  instead.
 *   Example 1:
 *   Input:  temperatures = [73,74,75,71,69,72,76,73]
 *  Output:  [1,1,4,2,1,1,0,0]
 *    Example 2:
 *   Input:  temperatures = [30,40,50,60]
 *  Output:  [1,1,1,0]
 *    Example 3:
 *   Input:  temperatures = [30,60,90]
 *  Output:  [1,1,0]
 *   Constraints:
 *           1 <= temperatures.length <= 10 5
 *           30 <= temperatures[i] <= 100
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

