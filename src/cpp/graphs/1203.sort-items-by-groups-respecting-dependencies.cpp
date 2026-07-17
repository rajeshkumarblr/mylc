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
 * @lc app=leetcode id=1203 lang=cpp
 *
 * [1203] Sort Items by Groups Respecting Dependencies
 *
 * Problem Description:
 * There are n items each belonging to one of m groups. The group of each item is
 * given by the array group, where group[i] is the group that the i-th item
 * belongs to (it is -1 if the i-th item does not belong to any group).
 * - Items belong to the same group should be next to each other in the sorted
 * list.
 * - Some items have dependencies: beforeItems[i] is a list of all items that
 * must be sorted before the i-th item.
 *
 * Return any sorted list of all items that satisfies the conditions. If there
 * is no such list, return an empty list.
 *
 * Examples:
 * 1. Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1],
 *    beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
 *    Output: [6,3,4,1,5,2,0,7]
 *
 * 2. Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1],
 *    beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
 *    Output: []
 *    Explanation: There is a cycle where 4 must be before 6, and 6 must be
 * before 4. So it is impossible.
 *
 * Constraints:
 * - 1 <= m <= n <= 3 * 10^4
 * - group.length == n
 * - -1 <= group[i] <= m - 1
 * - beforeItems.length == n
 * - 0 <= beforeItems[i].length <= n - 1
 * - 0 <= beforeItems[i][j] <= n - 1
 * - i != beforeItems[i][j]
 * - beforeItems[i] contains no duplicates.
 */

#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
  vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
    // TODO: Implement your solution here
    return {};
  }
};
// @lc code=end


int main() {
    Solution sol;
    // Case 1
    {
        int n = 8;
        int m = 2;
        vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1};
        vector<vector<int>> beforeItems = {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}};
        auto got = sol.sortItems(n, m, group, beforeItems);
        if (got != vector<int>{6, 3, 4, 1, 5, 2, 0, 7}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        int n = 8;
        int m = 2;
        vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1};
        vector<vector<int>> beforeItems = {{}, {6}, {5}, {6}, {3}, {}, {4}, {}};
        auto got = sol.sortItems(n, m, group, beforeItems);
        if (got != vector<int>{}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
