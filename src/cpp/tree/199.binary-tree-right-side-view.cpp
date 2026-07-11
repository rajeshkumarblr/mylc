/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * Difficulty: Medium
 * Category: tree
 * URL: https://leetcode.com/problems/binary-tree-right-side-view/
 *
 * Description:
 * Given the  root  of a binary tree, imagine yourself standing on the  right
 * side  of it, return  the values of the nodes you can see ordered from top
 * to bottom .
 *   Example 1:
 *   Input:   root = [1,2,3,null,5,null,4]
 *   Output:   [1,3,4]
 *   Explanation:
 *   Example 2:
 *   Input:   root = [1,2,3,4,null,null,null,5]
 *   Output:   [1,3,4,5]
 *   Explanation:
 *   Example 3:
 *   Input:   root = [1,null,3]
 *   Output:   [1,3]
 *   Example 4:
 *   Input:   root = []
 *   Output:   []
 *   Constraints:
 *          The number of nodes in the tree is in the range  [0, 100] .
 *           -100 <= Node.val <= 100
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
    }
};
// @lc code=end
