#include "lc_test_utils.h"
using namespace std;


/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

int maxDepth_recursive(TreeNode* root);

// @lc code=start
#ifndef LC_LOCAL_TEST
class Solution {
public:
#endif
    int maxDepth(TreeNode* root) {
        return maxDepth_recursive(root);
        //return maxDepth_dfs(root);
    }

    int maxDepth_dfs(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*,int>> st;
        st.push({root, 1});
        int depth = 0;

        while (!st.empty()) {
            auto [node, d] = st.top(); st.pop();
            depth = max(depth, d);
            if (node->left) st.push({node->left, d+1});
            if (node->right) st.push({node->right, d+1});
        }
        return depth;
    }

    int maxDepth_recursive(TreeNode* root) {
        if (!root) return 0;                       // base: empty subtree has depth 0
        return 1 + max(maxDepth_recursive(root->left),       // child depth
                       maxDepth_recursive(root->right));     // +1 for the current node
    }


// @lc code=end
