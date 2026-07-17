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
#include <vector>
#include <queue>
#include "lc_types.h"
using namespace std;

/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * Given the roots of two binary trees p and q, write a function to check if
 * they are the same or not.
 *
 * Two binary trees are considered the same if they are structurally
 * identical, and the nodes have the same value.
 *
 * Example 1:
 * Input: p = [1,2,3], q = [1,2,3]
 * Output: true
 *
 * Example 2:
 * Input: p = [1,2], q = [1,null,2]
 * Output: false
 *
 * Example 3:
 * Input: p = [1,2,1], q = [1,1,2]
 * Output: false
 *
 * Constraints:
 * - The number of nodes in both trees is in the range [0, 100].
 * - -10^4 <= Node.val <= 10^4
 *
 * Description:
 * Given the roots of two binary trees  p  and  q , write a function to check
 * if they are the same or not.
 *  Two binary trees are considered the same if they are structurally
 * identical, and the nodes have the same value.
 *   Example 1:
 *  Input:  p = [1,2,3], q = [1,2,3]
 *  Output:  true
 *   Example 2:
 *  Input:  p = [1,2], q = [1,null,2]
 *  Output:  false
 *   Example 3:
 *  Input:  p = [1,2,1], q = [1,1,2]
 *  Output:  false
 *   Constraints:
 *          The number of nodes in both trees is in the range  [0, 100] .
 *           -10 4  <= Node.val <= 10 4
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






int main() {
    Solution sol;
    // Case 1
    {
        vector<int> p_arr{};
        TreeNode* p = vec_to_tree(p_arr);
        vector<int> q_arr{};
        TreeNode* q = vec_to_tree(q_arr);
        auto got = sol.isSameTree(p, q);
        if (got != true) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> p_arr{1, 2, 3};
        TreeNode* p = vec_to_tree(p_arr);
        vector<int> q_arr{1, 2, 3};
        TreeNode* q = vec_to_tree(q_arr);
        auto got = sol.isSameTree(p, q);
        if (got != true) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> p_arr{1, 2};
        TreeNode* p = vec_to_tree(p_arr);
        vector<int> q_arr{1, None, 2};
        TreeNode* q = vec_to_tree(q_arr);
        auto got = sol.isSameTree(p, q);
        if (got != false) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> p_arr{1, 2, 1};
        TreeNode* p = vec_to_tree(p_arr);
        vector<int> q_arr{1, 1, 2};
        TreeNode* q = vec_to_tree(q_arr);
        auto got = sol.isSameTree(p, q);
        if (got != false) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> p_arr{};
        TreeNode* p = vec_to_tree(p_arr);
        vector<int> q_arr{1};
        TreeNode* q = vec_to_tree(q_arr);
        auto got = sol.isSameTree(p, q);
        if (got != false) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
