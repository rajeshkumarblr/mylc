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
#include <stack>
#include <string>
#include <iostream>
#include <utility>
#include "../lc_types.h"
#include <vector>
#include "lc_types.h"
using namespace std;

/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * Given the root of a binary tree, invert the tree, and return its root.
 *
 * Example 1:
 * Input: root = [4,2,7,1,3,6,9]
 * Output: [4,7,2,9,6,3,1]
 *
 * Example 2:
 * Input: root = [2,1,3]
 * Output: [2,3,1]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 100].
 * - -100 <= Node.val <= 100
 *
 * Description:
 * Given the  root  of a binary tree, invert the tree, and return  its root .
 *   Example 1:
 *  Input:  root = [4,2,7,1,3,6,9]
 *  Output:  [4,7,2,9,6,3,1]
 *   Example 2:
 *  Input:  root = [2,1,3]
 *  Output:  [2,3,1]
 *   Example 3:
 *  Input:  root = []
 *  Output:  []
 *   Constraints:
 *          The number of nodes in the tree is in the range  [0, 100] .
 *           -100 <= Node.val <= 100
 */

// @lc code=start
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        // Swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
// @lc code=end
















// Non-LeetCode wrapper for harness





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> root_arr{4, 2, 7, 1, 3, 6, 9};
        TreeNode* root = vec_to_tree(root_arr);
        TreeNode* got_node = sol.invertTree(root);
        vector<int> got = tree_to_vec(got_node);
        if (got != vector<int>{4, 7, 2, 9, 6, 3, 1}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> root_arr{2, 1, 3};
        TreeNode* root = vec_to_tree(root_arr);
        TreeNode* got_node = sol.invertTree(root);
        vector<int> got = tree_to_vec(got_node);
        if (got != vector<int>{2, 3, 1}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> root_arr{};
        TreeNode* root = vec_to_tree(root_arr);
        TreeNode* got_node = sol.invertTree(root);
        vector<int> got = tree_to_vec(got_node);
        if (got != vector<int>{}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
