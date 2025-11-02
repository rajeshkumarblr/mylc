// Needed for TreeNode definition and STL containers
#include "lc_types.h"
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;


/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */


// @lc code=start
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return maxDepth_bfs(root);
        //return maxDepth_recursive(root);
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

    int maxDepth_bfs(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();  // Current level's node count
            depth++;                   // Increment depth for each level
            
            // Process all nodes in current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front(); 
                q.pop();
                
                // Add children to queue for next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return depth;
    }

    int maxDepth_recursive(TreeNode* root) {
        if (!root) return 0;                       // base: empty subtree has depth 0
        return 1 + max(maxDepth_recursive(root->left),       // child depth
                       maxDepth_recursive(root->right));     // +1 for the current node
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
int maxDepth(TreeNode* root) {
    Solution sol;
    return sol.maxDepth(root);
}
