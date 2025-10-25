#include <vector>
#include "lc_types.h"
using namespace std;

/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        // Swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
TreeNode* invertTree(TreeNode* root) {
    Solution sol;
    return sol.invertTree(root);
}