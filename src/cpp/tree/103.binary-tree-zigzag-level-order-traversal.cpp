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
            
            // Set up position calculation once based on direction
            int start, increment;
            if (leftToRight) {
                start = 0;
                increment = 1;
            } else {
                start = n - 1;
                increment = -1;
            }
            
            // Process nodes with pre-calculated direction
            int pos = start;
            int count = 0;
            while (count < n) {
                TreeNode *node = q.front(); q.pop();
                
                level[pos] = node->val;
                pos += increment;  // Move to next position
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
                count++;
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

