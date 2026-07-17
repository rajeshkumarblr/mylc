#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * Difficulty: Medium
 * Category: graphs
 * URL: https://leetcode.com/problems/network-delay-time/
 *
 * Description:
 * You are given a network of  n  nodes, labeled from  1  to  n . You are also
 * given  times , a list of travel times as directed edges  times[i] = (u i ,
 * v i , w i ) , where  u i   is the source node,  v i   is the target node,
 * and  w i   is the time it takes for a signal to travel from source to
 * target.
 *  We will send a signal from a given node  k . Return  the  minimum  time it
 * takes for all the   n   nodes to receive the signal . If it is impossible
 * for all the  n  nodes to receive the signal, return  -1 .
 *   Example 1:
 *  Input:  times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 *  Output:  2
 *   Example 2:
 *  Input:  times = [[1,2,1]], n = 2, k = 1
 *  Output:  1
 *   Example 3:
 *  Input:  times = [[1,2,1]], n = 2, k = 2
 *  Output:  -1
 *   Constraints:
 *           1 <= k <= n <= 100
 *           1 <= times.length <= 6000
 *           times[i].length == 3
 *           1 <= u i , v i  <= n
 *           u i  != v i
 *           0 <= w i  <= 100
 *          All the pairs  (u i , v i )  are  unique . (i.e., no multiple
 * edges.)
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
