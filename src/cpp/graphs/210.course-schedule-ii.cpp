#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * Difficulty: Medium
 * Category: graphs
 * URL: https://leetcode.com/problems/course-schedule-ii/
 *
 * Description:
 * There are a total of  numCourses  courses you have to take, labeled from  0
 * to  numCourses - 1 . You are given an array  prerequisites  where
 * prerequisites[i] = [a i , b i ]  indicates that you  must  take course  b i
 * first if you want to take course  a i  .
 *          For example, the pair  [0, 1] , indicates that to take course  0
 * you have to first take course  1 .
 *  Return  the ordering of courses you should take to finish all courses . If
 * there are many valid answers, return  any  of them. If it is impossible to
 * finish all courses, return  an empty array .
 *   Example 1:
 *  Input:  numCourses = 2, prerequisites = [[1,0]]
 *  Output:  [0,1]
 *  Explanation:  There are a total of 2 courses to take. To take course 1 you
 * should have finished course 0. So the correct course order is [0,1].
 *   Example 2:
 *  Input:  numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 *  Output:  [0,2,1,3]
 *  Explanation:  There are a total of 4 courses to take. To take course 3 you
 * should have finished both courses 1 and 2. Both courses 1 and 2 should be
 * taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3].
 *   Example 3:
 *  Input:  numCourses = 1, prerequisites = []
 *  Output:  [0]
 *   Constraints:
 *           1 <= numCourses <= 2000
 *           0 <= prerequisites.length <= numCourses * (numCourses - 1)
 *           prerequisites[i].length == 2
 *           0 <= a i , b i  < numCourses
 *           a i  != b i
 *          All the pairs  [a i , b i ]  are  distinct .
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

class Solution_BFS {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adjlist(numCourses);
    vector<int> indegree(numCourses, 0);
    queue<int> q;
    vector<int> courseOrder;
    courseOrder.reserve(numCourses);

    for (const auto &pre : prerequisites) {
      adjlist[pre[1]].push_back(pre[0]);
      indegree[pre[0]]++;
    }

    for (int i = 0; i < numCourses; i++) {
      if (!indegree[i]) {
        q.push(i);
        courseOrder.push_back(i);
      }
    }

    while (!q.empty()) {
      int course = q.front();
      q.pop();

      for (auto nextcourse : adjlist[course]) {
        indegree[nextcourse]--;
        if (indegree[nextcourse] == 0) {
          q.push(nextcourse);
          courseOrder.push_back(nextcourse);
        }
      }
    }

    if (courseOrder.size() == numCourses) {
      return courseOrder;
    }
    return {};
  }
};

// @lc code=start
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adjlist(numCourses);
    vector<int> indegree(numCourses, 0);
    vector<int> courseOrder;
    courseOrder.reserve(numCourses);

    for (const auto &pre : prerequisites) {
      adjlist[pre[1]].push_back(pre[0]);
      indegree[pre[0]]++;
    }

    for (int i = 0; i < numCourses; i++) {
      if (!indegree[i]) {
        courseOrder.push_back(i);
      }
    }

    int courseIndex = 0;
    while (courseIndex < courseOrder.size()) {
      int course = courseOrder[courseIndex];
      courseIndex++;

      for (auto nextcourse : adjlist[course]) {
        indegree[nextcourse]--;
        if (indegree[nextcourse] == 0) {
          courseOrder.push_back(nextcourse);
        }
      }
    }

    if (courseOrder.size() == numCourses) {
      return courseOrder;
    }
    return {};
  }
};
// @lc code=end

int main() {
  Solution sol;
  // Case 1
  {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    auto got = sol.findOrder(numCourses, prerequisites);
    if (got != vector<int>{0, 1}) {
      cerr << "FAIL case 1" << endl;
      return 1;
    }
  }
  // Case 2
  {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    auto got = sol.findOrder(numCourses, prerequisites);
    if (got != vector<int>{0, 1, 2, 3}) {
      cerr << "FAIL case 2" << endl;
      return 1;
    }
  }
  // Case 3
  {
    int numCourses = 1;
    vector<vector<int>> prerequisites = {};
    auto got = sol.findOrder(numCourses, prerequisites);
    if (got != vector<int>{0}) {
      cerr << "FAIL case 3" << endl;
      return 1;
    }
  }
  // Case 4
  {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    auto got = sol.findOrder(numCourses, prerequisites);
    if (got != vector<int>{}) {
      cerr << "FAIL case 4" << endl;
      return 1;
    }
  }
  cout << "PASS" << endl;
  return 0;
}
