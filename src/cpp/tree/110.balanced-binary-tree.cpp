#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <cmath>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <utility>
#include "../lc_types.h"
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
 *
 * Description:
 * Given a binary tree, determine if it is   height-balanced  .
 *   Example 1:
 *  Input:  root = [3,9,20,null,null,15,7]
 *  Output:  true
 *   Example 2:
 *  Input:  root = [1,2,2,3,3,null,null,4,4]
 *  Output:  false
 *   Example 3:
 *  Input:  root = []
 *  Output:  true
 *   Constraints:
 *          The number of nodes in the tree is in the range  [0, 5000] .
 *           -10 4  <= Node.val <= 10 4
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






int main() {
    Solution sol;
    // Case 1
    {
        vector<int> tree_arr{3, 9, 20, None, None, 15, 7};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isBalanced(tree);
        if (got != true) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> tree_arr{};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isBalanced(tree);
        if (got != true) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> tree_arr{1};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isBalanced(tree);
        if (got != true) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> tree_arr{1, 2};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isBalanced(tree);
        if (got != true) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> tree_arr{1, 2, 2, 3, 3, None, None, 4, 4};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isBalanced(tree);
        if (got != false) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    // Case 6
    {
        vector<int> tree_arr{1, 2, None, 3, None, 4, None, 5};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isBalanced(tree);
        if (got != false) {
            cerr << "FAIL case 6" << endl;
            return 1;
        }
    }
    // Case 7
    {
        vector<int> tree_arr{1, None, 2, None, 3, None, 4};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isBalanced(tree);
        if (got != false) {
            cerr << "FAIL case 7" << endl;
            return 1;
        }
    }
    // Case 8
    {
        vector<int> tree_arr{1, 2, 3, 4, 5, None, 7};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isBalanced(tree);
        if (got != true) {
            cerr << "FAIL case 8" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
