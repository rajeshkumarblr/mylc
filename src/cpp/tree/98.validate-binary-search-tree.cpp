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
bool isValidBST(TreeNode* root) {
    Solution sol;
    return sol.isValidBST(root);
}
