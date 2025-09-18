/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */
// Needed for TreeNode and std helpers
#include "lc_types.h"
#include <algorithm>
using namespace std;

int height(TreeNode* node);

// @lc code=start
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

    int height(TreeNode* node) {
        if (!node) return 0;
        int L = height(node->left);   if (L == -1) return -1;
        int R = height(node->right);  if (R == -1) return -1;  
        if (abs(L - R) > 1) return -1;      
        return 1 + max(L,R);
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
bool isBalanced(TreeNode* root) {
    Solution sol;
    return sol.isBalanced(root);
}

