#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
#include "../lc_types.h"
/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * Difficulty: Medium
 * Category: tree
 * URL: https://leetcode.com/problems/binary-tree-right-side-view/
 *
 * Description:
 * Given the  root  of a binary tree, imagine yourself standing on the  right
 * side  of it, return  the values of the nodes you can see ordered from top
 * to bottom .
 *   Example 1:
 *   Input:   root = [1,2,3,null,5,null,4]
 *   Output:   [1,3,4]
 *   Explanation:
 *   Example 2:
 *   Input:   root = [1,2,3,4,null,null,null,5]
 *   Output:   [1,3,4,5]
 *   Explanation:
 *   Example 3:
 *   Input:   root = [1,null,3]
 *   Output:   [1,3]
 *   Example 4:
 *   Input:   root = []
 *   Output:   []
 *   Constraints:
 *          The number of nodes in the tree is in the range  [0, 100] .
 *           -100 <= Node.val <= 100
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;


// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    // Case 1
    {
        vector<int> tree_arr{1, 2, 3, None, 5, None, 4};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.rightSideView(tree);
        if (got != vector<int>{1, 3, 4}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> tree_arr{1, None, 3};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.rightSideView(tree);
        if (got != vector<int>{1, 3}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> tree_arr{};
        TreeNode* tree = vec_to_tree(tree_arr);
        auto got = sol.rightSideView(tree);
        if (got != vector<int>{}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
