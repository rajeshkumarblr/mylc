#include <vector>
#include <queue>
#include "lc_types.h"

using namespace std;
/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p || !q) return false;
        else if (p->val != q->val) return false;

        return (isSameTree(p->left, q->left)  &&
                isSameTree(p->right, q->right));
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
bool isSameTree(TreeNode* p, TreeNode* q) {
    Solution sol;
    return sol.isSameTree(p, q);
}

