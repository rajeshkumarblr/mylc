#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * Difficulty: Medium
 * Category: graphs
 * URL: https://leetcode.com/problems/course-schedule/
 *
 * Description:
 * There are a total of  numCourses  courses you have to take, labeled from  0
 * to  numCourses - 1 . You are given an array  prerequisites  where
 * prerequisites[i] = [a i , b i ]  indicates that you  must  take course  b i
 * first if you want to take course  a i  .
 *          For example, the pair  [0, 1] , indicates that to take course  0
 * you have to first take course  1 .
 *  Return  true  if you can finish all courses. Otherwise, return  false .
 *   Example 1:
 *  Input:  numCourses = 2, prerequisites = [[1,0]]
 *  Output:  true
 *  Explanation:  There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *   Example 2:
 *  Input:  numCourses = 2, prerequisites = [[1,0],[0,1]]
 *  Output:  false
 *  Explanation:  There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0
 * you should also have finished course 1. So it is impossible.
 *   Constraints:
 *           1 <= numCourses <= 2000
 *           0 <= prerequisites.length <= 5000
 *           prerequisites[i].length == 2
 *           0 <= a i , b i  < numCourses
 *          All the pairs prerequisites[i] are  unique .
 */

#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution_BFS {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adjlist;
    vector<int> indegree(numCourses, 0);
    adjlist.resize(numCourses);

    for (const auto &req : prerequisites) {
      int courseReq = req[0];
      int depReq = req[1];
      adjlist[depReq].push_back(courseReq);
      indegree[courseReq]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    int nodes = q.size();
    while (!q.empty()) {
      int course = q.front();
      q.pop();

      for (int nextcourse : adjlist[course]) {
        indegree[nextcourse]--;
        if (indegree[nextcourse] == 0) {
          q.push(nextcourse);
          nodes++;
        }
      }
    }

    return nodes == numCourses;
  }
};

class Solution {
private:
  bool dfs(int course, const vector<vector<int>> &adjlist, vector<int> &state) {
    // If we see a node that is currently "visiting" (1), we found a cycle!
    if (state[course] == 1) return false; 
    
    // If it's already "visited" (2), we know it's safe and has no cycles.
    if (state[course] == 2) return true;  

    // Mark as "visiting" before traversing neighbors
    state[course] = 1; 

    for (int nextcourse : adjlist[course]) {
      if (!dfs(nextcourse, adjlist, state)) {
        return false;
      }
    }

    // Finished processing all neighbors with no cycles! Mark as safe (2).
    state[course] = 2; 
    return true;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // 1. Build the adjacency list
    vector<vector<int>> adjlist(numCourses);
    for (const auto &req : prerequisites) {
      adjlist[req[1]].push_back(req[0]);
    }

    // 2. State array for cycle detection:
    // 0 = unvisited, 1 = visiting, 2 = visited (safe)
    vector<int> state(numCourses, 0);

    // 3. Graph might be disconnected, so we check every single course
    for (int i = 0; i < numCourses; i++) {
      if (state[i] == 0) {
        if (!dfs(i, adjlist, state)) {
          return false; // Found a cycle!
        }
      }
    }

    return true;
  }
};
// @lc code=end

int main() {
  Solution sol;
  {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    auto got = sol.canFinish(numCourses, prerequisites);
    if (got != true) {
      cerr << "FAIL case 1" << endl;
      return 1;
    }
  }
  // Case 1
  {
    int numCourses = 5;
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 3}};
    auto got = sol.canFinish(numCourses, prerequisites);
    if (got != true) {
      cerr << "FAIL case 1" << endl;
      return 1;
    }
  }
  // Case 2
  {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    auto got = sol.canFinish(numCourses, prerequisites);
    if (got != true) {
      cerr << "FAIL case 2" << endl;
      return 1;
    }
  }
  // Case 3
  {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    auto got = sol.canFinish(numCourses, prerequisites);
    if (got != false) {
      cerr << "FAIL case 3" << endl;
      return 1;
    }
  }
  cout << "PASS" << endl;
  return 0;
}
