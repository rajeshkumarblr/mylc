/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 2000].
 * - -1000 <= Node.val <= 1000
 *
 * Description:
 * Given the  root  of a binary tree, return  the level order traversal of its
 * nodes' values . (i.e., from left to right, level by level).
 *   Example 1:
 *  Input:  root = [3,9,20,null,null,15,7]
 *  Output:  [[3],[9,20],[15,7]]
 *   Example 2:
 *  Input:  root = [1]
 *  Output:  [[1]]
 *   Example 3:
 *  Input:  root = []
 *  Output:  []
 *   Constraints:
 *          The number of nodes in the tree is in the range  [0, 2000] .
 *           -1000 <= Node.val <= 1000
 */
#include <vector>
#include <queue>
#include "lc_types.h"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res; // empty => [] not [[]]
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            level.reserve(n);
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(std::move(level));
        }
        return res;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    Solution sol;
    return sol.levelOrder(root);
}

