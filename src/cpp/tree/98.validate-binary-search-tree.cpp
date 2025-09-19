#include <limits>
#include <climits>
#include "lc_types.h"
using namespace std;

/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
