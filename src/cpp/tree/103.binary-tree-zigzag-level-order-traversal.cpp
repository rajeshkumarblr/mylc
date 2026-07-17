#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include <unordered_set>
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
/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */
#include <vector>
#include <queue>
#include "lc_types.h"
using namespace std;


// @lc code=start
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            
            // Set up position calculation once based on direction
            int start, increment;
            if (leftToRight) {
                start = 0;
                increment = 1;
            } else {
                start = n - 1;
                increment = -1;
            }
            
            // Process nodes with pre-calculated direction
            int pos = start;
            int count = 0;
            while (count < n) {
                TreeNode *node = q.front(); q.pop();
                
                level[pos] = node->val;
                pos += increment;  // Move to next position
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
                count++;
            }
            
            res.push_back(std::move(level));
            leftToRight = !leftToRight;
        }
        return res;
    }
};

// @lc code=end
















// Non-LeetCode wrapper for harness






int main() {
    Solution sol;
    // Case 1
    {
        vector<int> tree_arr{};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.zigzagLevelOrder(tree);
        if (got != vector<vector<int>>{}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> tree_arr{1};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.zigzagLevelOrder(tree);
        if (got != vector<vector<int>>{{1}}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> tree_arr{3, 9, 20, None, None, 15, 7};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.zigzagLevelOrder(tree);
        if (got != vector<vector<int>>{{3}, {20, 9}, {15, 7}}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> tree_arr{1, 2, 3, 4, 5, None, 7};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.zigzagLevelOrder(tree);
        if (got != vector<vector<int>>{{1}, {3, 2}, {4, 5, 7}}) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> tree_arr{1, None, 2, None, 3, None, 4};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.zigzagLevelOrder(tree);
        if (got != vector<vector<int>>{{1}, {2}, {3}, {4}}) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
