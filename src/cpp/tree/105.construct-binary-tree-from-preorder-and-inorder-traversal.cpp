/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree From Preorder And Inorder Traversal
 *
 * Difficulty: Medium
 * Category: tree
 * URL: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *
 * Description:
 * Given two integer arrays  preorder  and  inorder  where  preorder  is the
 * preorder traversal of a binary tree and  inorder  is the inorder traversal
 * of the same tree, construct and return  the binary tree .
 *   Example 1:
 *  Input:  preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 *  Output:  [3,9,20,null,null,15,7]
 *   Example 2:
 *  Input:  preorder = [-1], inorder = [-1]
 *  Output:  [-1]
 *   Constraints:
 *           1 <= preorder.length <= 3000
 *           inorder.length == preorder.length
 *           -3000 <= preorder[i], inorder[i] <= 3000
 *           preorder  and  inorder  consist of  unique  values.
 *          Each value of  inorder  also appears in  preorder .
 *           preorder  is  guaranteed  to be the preorder traversal of the
 * tree.
 *           inorder  is  guaranteed  to be the inorder traversal of the tree.
 */

#include "../lc_test_utils.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};
// @lc code=end
