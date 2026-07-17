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
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <utility>
#include "../lc_types.h"
#include <limits>
#include <climits>
#include "lc_types.h"
using namespace std;

/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * Given the root of a binary tree, determine if it is a valid binary search
 * tree (BST).
 *
 * A valid BST is defined as follows:
 * - The left subtree of a node contains only nodes with keys less than the
 *   node's key.
 * - The right subtree of a node contains only nodes with keys greater than the
 *   node's key.
 * - Both the left and right subtrees must also be binary search trees.
 *
 * Example 1:
 * Input: root = [2,1,3]
 * Output: true
 *
 * Example 2:
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 10^4].
 * - -2^31 <= Node.val <= 2^31 - 1
 *
 * Description:
 * Given the  root  of a binary tree,  determine if it is a valid binary
 * search tree (BST) .
 *  A  valid BST  is defined as follows:
 *          The left  subtree  of a node contains only nodes with keys
 * strictly less than  the node's key.
 *          The right subtree of a node contains only nodes with keys
 * strictly greater than  the node's key.
 *          Both the left and right subtrees must also be binary search trees.
 *   Example 1:
 *  Input:  root = [2,1,3]
 *  Output:  true
 *   Example 2:
 *  Input:  root = [5,1,4,null,null,3,6]
 *  Output:  false
 *  Explanation:  The root node's value is 5 but its right child's value is 4.
 *   Constraints:
 *          The number of nodes in the tree is in the range  [1, 10 4 ] .
 *           -2 31  <= Node.val <= 2 31  - 1
 */

// @lc code=start
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        return isValidBSTRange(root,LONG_MIN, LONG_MAX);
    }

    bool isValidBSTRange(TreeNode* root, long min, long max)
    {
        if (!root) return true;
        return ((root->val > min && root->val < max)
            && isValidBSTRange(root->left, min, root->val)
            && isValidBSTRange(root->right, root->val, max));
    }
};
// @lc code=end
















// Non-LeetCode wrapper for harness





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> tree_arr{2, 1, 3};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isValidBST(tree);
        if (got != true) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> tree_arr{5, 1, 4, None, None, 3, 6};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isValidBST(tree);
        if (got != false) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> tree_arr{};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isValidBST(tree);
        if (got != true) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> tree_arr{1};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isValidBST(tree);
        if (got != true) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> tree_arr{10, 5, 15, None, None, 6, 20};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isValidBST(tree);
        if (got != false) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    // Case 6
    {
        vector<int> tree_arr{2147483647};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.isValidBST(tree);
        if (got != true) {
            cerr << "FAIL case 6" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
