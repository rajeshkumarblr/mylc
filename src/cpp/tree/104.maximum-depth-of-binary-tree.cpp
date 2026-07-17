#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <list>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "../lc_types.h"
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
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * Given the root of a binary tree, return its maximum depth.
 *
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 *
 * Example 2:
 * Input: root = [1,null,2]
 * Output: 2
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 10^4].
 * - -100 <= Node.val <= 100
 *
 * Description:
 * Given the  root  of a binary tree, return  its maximum depth .
 *  A binary tree's  maximum depth  is the number of nodes along the longest
 * path from the root node down to the farthest leaf node.
 *   Example 1:
 *  Input:  root = [3,9,20,null,null,15,7]
 *  Output:  3
 *   Example 2:
 *  Input:  root = [1,null,2]
 *  Output:  2
 *   Constraints:
 *          The number of nodes in the tree is in the range  [0, 10 4 ] .
 *           -100 <= Node.val <= 100
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





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> tree_arr{3, 9, 20, None, None, 15, 7};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.maxDepth(tree);
        if (got != 3) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> tree_arr{};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.maxDepth(tree);
        if (got != 0) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> tree_arr{1};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.maxDepth(tree);
        if (got != 1) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> tree_arr{1, 2};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.maxDepth(tree);
        if (got != 2) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> tree_arr{1, 2, 3, 4, 5, None, 7};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.maxDepth(tree);
        if (got != 3) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    // Case 6
    {
        vector<int> tree_arr{1, 2, None, 3, None, 4};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.maxDepth(tree);
        if (got != 4) {
            cerr << "FAIL case 6" << endl;
            return 1;
        }
    }
    // Case 7
    {
        vector<int> tree_arr{1, None, 2, None, 3, None, 4};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.maxDepth(tree);
        if (got != 4) {
            cerr << "FAIL case 7" << endl;
            return 1;
        }
    }
    // Case 8
    {
        vector<int> tree_arr{1, 2, None, 3, None, 4, None, 5};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.maxDepth(tree);
        if (got != 5) {
            cerr << "FAIL case 8" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
