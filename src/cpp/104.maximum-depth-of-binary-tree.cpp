/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */
#include "lc_test_utils.h"
using namespace std;

// @lc code=start
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //return maxDepth_recursive(root);
        return maxDepth_dfs(root);
    }

    int maxDepth_dfs(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*,int>> st;
        st.push({root, 1});
        int depth = 0;

        while (!st.empty()) {
            auto [node, d] = st.top(); st.pop();
            depth = max(depth, d);
            if (node->left) st.push({node->left, d+1});
            if (node->right) st.push({node->right, d+1});
        }
        return depth;
    }

    int maxDepth_recursive(TreeNode* root) {
        if (!root) return 0;                       // base: empty subtree has depth 0
        return 1 + max(maxDepth_recursive(root->left),       // child depth
                       maxDepth_recursive(root->right));     // +1 for the current node
    }


};
// @lc code=end

int main() {
    Solution sol;
    using In  = std::vector<std::optional<int>>;
    using Out = int;

    std::vector<std::pair<In, Out>> tests = {
        { {3,9,20,nullopt,nullopt,15,7}, 3 },
        { {}, 0 },
        { {1}, 1 },
        { {1,2}, 2 },
        { {1,2,3,4,5,nullopt,7}, 3 },
        { {1,2,nullopt,3,nullopt,4}, 4 },
        { {1,nullopt,2,nullopt,3,nullopt,4}, 4 },
        { {1,2,nullopt,3,nullopt,4,nullopt,5}, 5 }
    };

    auto fn = [&](TreeNode* root) { return sol.maxDepth(root); };
    return run_tree_tests(tests, fn) ? 0 : 1;
}