/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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

