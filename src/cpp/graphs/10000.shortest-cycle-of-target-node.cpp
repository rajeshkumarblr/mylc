/*
 * @lc app=leetcode id=10000 lang=cpp
 *
 * [10000] Shortest Cycle of a Target Node
 *
 * Problem Description:
 * Finding the length of shortest cycle of a target node in directed graph.
 * If no cycle found with target node, return -1.
 *
 * Examples:
 * 1. Input: n = 4, edges = [[0,1],[1,2],[2,0],[2,3]], target = 0
 *    Output: 3
 *    Explanation: The cycle is 0 -> 1 -> 2 -> 0.
 *
 * 2. Input: n = 4, edges = [[0,1],[1,2],[2,3]], target = 0
 *    Output: -1
 *    Explanation: There is no cycle containing node 0.
 *
 * Constraints:
 * - 2 <= n <= 1000
 * - 1 <= edges.length <= 2000
 * - edges[i].length == 2
 * - 0 <= u, v < n
 * - 0 <= target < n
 */

#include "../lc_test_utils.h"
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int findShortestCycle(vector<vector<int>> &adj, int target) {
    queue<int> q;
    if (target >= adj.size()) {
      return -1;
    }
    vector<int> dist(adj.size(), 0);
    const vector<int> &vec = adj[target];
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] == target) {
        return 1;
      }
      dist[vec[i]] = 1;
      q.push(vec[i]);
    }

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      if (curr >= adj.size()) {
        continue;
      }

      const vector<int> &vec = adj[curr];
      for (const int node : vec) {
        if (node == target) {
          return dist[curr] + 1;
        }

        if (dist[node] == 0) {
          dist[node] = dist[curr] + 1;
          q.push(node);
        }
      }
    }

    return -1;
  }
};
// @lc code=end

int findShortestCycle(vector<vector<int>> &adj, int target) {
  Solution sol;
  return sol.findShortestCycle(adj, target);
}
