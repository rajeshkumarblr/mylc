/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */


#include <vector>
#include <stack>
#include "lc_test_utils.h"

using namespace std;

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


int main() {
    using input_t = std::vector<std::optional<int>>;
    using output_t = std::vector<int>;
    std::vector<std::pair<input_t, output_t>> test_cases = {
        { {1, nullopt, 2, 3}, {1, 3, 2} },
        { {}, {} },
        { {1}, {1} },
        { {1, 2, 3, 4, 5, 6, 7}, {4,2,5,1,6,3,7} },
        { {1, 2, nullopt, 3}, {3,2,1} },
        { {1, nullopt, 2, nullopt, 3}, {1,2,3} },
        { {5, 4, nullopt, 3, nullopt, 2, nullopt, 1}, {1,2,3,4,5} }
    };

    Solution sol;
    auto func = [&](TreeNode* root) { return sol.inorderTraversal(root); };
    return run_tree_tests(test_cases, func) ? 0 : 1;
}

