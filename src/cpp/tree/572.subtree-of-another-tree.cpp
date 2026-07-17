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
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * Difficulty: Easy
 * Category: tree
 * URL: https://leetcode.com/problems/subtree-of-another-tree/
 *
 * Description:
 * Given the roots of two binary trees  root  and  subRoot , return  true  if
 * there is a subtree of  root  with the same structure and node values of
 * subRoot  and  false  otherwise.
 *  A subtree of a binary tree  tree  is a tree that consists of a node in
 * tree  and all of this node's descendants. The tree  tree  could also be
 * considered as a subtree of itself.
 *   Example 1:
 *  Input:  root = [3,4,5,1,2], subRoot = [4,1,2]
 *  Output:  true
 *   Example 2:
 *  Input:  root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 *  Output:  false
 *   Constraints:
 *          The number of nodes in the  root  tree is in the range  [1, 2000]
 * .
 *          The number of nodes in the  subRoot  tree is in the range  [1,
 * 1000] .
 *           -10 4  <= root.val <= 10 4
 *           -10 4  <= subRoot.val <= 10 4
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
