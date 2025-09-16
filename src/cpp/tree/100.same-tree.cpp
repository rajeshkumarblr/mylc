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
#ifndef LC_LOCAL_TEST
class Solution {
public:
#endif

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p || !q) return false;
        else if (p->val != q->val) return false;

        return (isSameTree(p->left, q->left)  &&
                isSameTree(p->right, q->right));
    }

#ifndef LC_LOCAL_TEST
};
#endif
// @lc code=end

