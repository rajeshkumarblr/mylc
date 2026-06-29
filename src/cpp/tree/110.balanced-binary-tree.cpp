/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 * Example 2:
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 * Example 3:
 * Input: root = []
 * Output: true
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 5000].
 * - -10^4 <= Node.val <= 10^4
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

