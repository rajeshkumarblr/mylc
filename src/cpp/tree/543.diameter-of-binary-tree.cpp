#include "../lc_types.h"
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * Difficulty: Easy
 * Category: tree
 * URL: https://leetcode.com/problems/diameter-of-binary-tree/
 *
 * Description:
 * Given the  root  of a binary tree, return  the length of the  diameter  of
 * the tree .
 *  The  diameter  of a binary tree is the  length  of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root .
 *  The  length  of a path between two nodes is represented by the number of
 * edges between them.
 *   Example 1:
 *  Input:  root = [1,2,3,4,5]
 *  Output:  3
 *  Explanation:  3 is the length of the path [4,2,1,3] or [5,2,1,3].
 *   Example 2:
 *  Input:  root = [1,2]
 *  Output:  1
 *   Constraints:
 *          The number of nodes in the tree is in the range  [1, 10 4 ] .
 *           -100 <= Node.val <= 100
 */

#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int maxdepth(TreeNode *node, int &diameter) {
    if (node == nullptr) {
      return 0;
    }
    int maxdepthleft = maxdepth(node->left, diameter);
    int maxdepthright = maxdepth(node->right, diameter);

    diameter = max(diameter, maxdepthleft + maxdepthright);
    return max(maxdepthleft, maxdepthright) + 1;
  }

  int diameterOfBinaryTree(TreeNode *root) {
    int res = 0;
    maxdepth(root, res);
    return res;
  }
};
// @lc code=end

#include "../lc_test_utils.h"
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  try {
    json j = json::parse(R"raw({
      "cases": [
        {
          "root": [1, 2, 3, 4, 5],
          "expected": 3
        },
        {
          "root": [1, 2],
          "expected": 1
        }
      ]
    })raw");

    for (auto &tc : j.at("cases")) {
      vector<optional<int>> root_data;
      for (auto &elem : tc.at("root")) {
        if (elem.is_null()) {
          root_data.push_back(nullopt);
        } else {
          root_data.push_back(elem.get<int>());
        }
      }
      TreeNode *root = build_tree_from_level_order(root_data);
      int expected = tc.at("expected").get<int>();

      Solution sol;
      int result = sol.diameterOfBinaryTree(root);

      if (result != expected) {
        cerr << "FAIL for input: " << tc.at("root") << endl;
        cerr << "Expected: " << expected << ", Got: " << result << endl;
        free_tree(root);
        return 1;
      }
      free_tree(root);
    }
    cout << "PASS" << endl;
    return 0;
  } catch (const exception &e) {
    cerr << "Exception: " << e.what() << endl;
    return 1;
  }
}
