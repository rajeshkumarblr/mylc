package tree;
import common.*;


public class P94 {
/*
 * @lc app=leetcode id=94 lang=java
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 * Example 1:
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 * Example 2:
 * Input: root = []
 * Output: []
 *
 * Example 3:
 * Input: root = [1]
 * Output: [1]
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 100].
 * - -100 <= Node.val <= 100
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */
    // @lc code=start
    public class Solution {
        public java.util.List<Integer> inorderTraversal(TreeNode root) {
            java.util.List<Integer> out = new java.util.ArrayList<>();
            inorder(root, out);
            return out;
        }
        private void inorder(TreeNode n, java.util.List<Integer> out){
            if (n==null) return; inorder(n.left, out); out.add(n.val); inorder(n.right, out);
        }
    }
    // @lc code=end
}
