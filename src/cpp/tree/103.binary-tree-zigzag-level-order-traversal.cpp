/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */
#include <vector>
#include <queue>
#include "lc_types.h"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            for (int i=0; i<n; i++) {
                TreeNode *node = q.front(); q.pop();
                int index = leftToRight ? i : (n-1-i);
                level[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(std::move(level));
            leftToRight = !leftToRight;
        }
        return res;
    }
};

// @lc code=end

// Non-LeetCode wrapper for harness
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    Solution sol;
    return sol.zigzagLevelOrder(root);
}

