#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <utility>
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






int main() {
    Solution sol;
    // Case 1
    {
        vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
        auto got = sol.dailyTemperatures(input);
        if (got != vector<int>{1, 1, 4, 2, 1, 1, 0, 0}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> input = {30, 40, 50, 60};
        auto got = sol.dailyTemperatures(input);
        if (got != vector<int>{1, 1, 1, 0}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> input = {30, 60, 90};
        auto got = sol.dailyTemperatures(input);
        if (got != vector<int>{1, 1, 0}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> input = {90, 80, 70, 60};
        auto got = sol.dailyTemperatures(input);
        if (got != vector<int>{0, 0, 0, 0}) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> input = {};
        auto got = sol.dailyTemperatures(input);
        if (got != vector<int>{}) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    // Case 6
    {
        vector<int> input = {42};
        auto got = sol.dailyTemperatures(input);
        if (got != vector<int>{0}) {
            cerr << "FAIL case 6" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
