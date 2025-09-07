/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */
#include "lc_test_utils.h"
using namespace std;

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

int main() {
    Solution sol;
    using In  = vector<optional<int>>;
    using Out = bool;

    vector<pair<In, Out>> tests = {
        { {3,9,20,nullopt,nullopt,15,7},              true  },
        { {},                                         true  },
        { {1},                                        true  },
        { {1,2},                                      true  },
        { {1,2,2,3,3,nullopt,nullopt,4,4},            false }, // classic unbalanced
        { {1,2,nullopt,3,nullopt,4,nullopt,5},        false }, // left chain
        { {1,nullopt,2,nullopt,3,nullopt,4},          false }, // right chain
        { {1,2,3,4,5,nullopt,7},                      true  }
    };

    auto fn = [&](TreeNode* root) { return sol.isBalanced(root); };
    return run_tree_tests(tests, fn) ? 0 : 1;
}