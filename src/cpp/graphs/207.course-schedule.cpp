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

#include "../lc_test_utils.h"
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
    }
};
// @lc code=end
