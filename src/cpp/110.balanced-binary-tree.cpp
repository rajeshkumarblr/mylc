/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */
#include "lc_test_utils.h"
using namespace std;

int height(TreeNode* node);

// @lc code=start
#ifndef LC_LOCAL_TEST
class Solution {
public:
#endif
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


#ifndef LC_LOCAL_TEST
};
#endif
// @lc code=end

