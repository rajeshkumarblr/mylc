#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <utility>
#include "../lc_types.h"
/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 * Example 1:
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 * Example 2:
 * Input: root = []
 * Output: []
 *
 * Example 3:
 * Input: root = [1]
 * Output: [1]
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 100].
 * - -100 <= Node.val <= 100
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





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> tree_arr{1, None, 2, 3};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.inorderTraversal(tree);
        if (got != vector<int>{1, 3, 2}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> tree_arr{};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.inorderTraversal(tree);
        if (got != vector<int>{}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> tree_arr{1};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.inorderTraversal(tree);
        if (got != vector<int>{1}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> tree_arr{1, 2};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.inorderTraversal(tree);
        if (got != vector<int>{2, 1}) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> tree_arr{1, None, 2};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.inorderTraversal(tree);
        if (got != vector<int>{1, 2}) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
