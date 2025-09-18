/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */


#include <vector>
#include <stack>
#include "lc_types.h"

using namespace std;
void inOrder_iterative(TreeNode* root, vector<int>& vec);
void inOrder_recursive(TreeNode* root, vector<int>& vec);

// @lc code=start
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inOrder_iterative(root, vec);
        //inOrder_recursive(root, vec);
        return vec;
    }

    void inOrder_iterative(TreeNode* root, vector<int>& vec) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr ) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();                    
            vec.push_back(curr->val);
            curr = curr->right;            
        }
    }

    void inOrder_recursive(TreeNode* root, vector<int>& vec) {
        if (root != nullptr) {
            inOrder_recursive(root->left, vec);
            vec.push_back(root->val);
            inOrder_recursive(root->right, vec);
        }
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
std::vector<int> inorderTraversal(TreeNode* root) {
    Solution sol;
    return sol.inorderTraversal(root);
}
