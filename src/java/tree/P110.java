package tree;
import common.*;


public class P110 {
/*
 * @lc app=leetcode id=110 lang=java
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 * Example 2:
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 * Example 3:
 * Input: root = []
 * Output: true
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 5000].
 * - -10^4 <= Node.val <= 10^4
 */
    // @lc code=start
    public class Solution {
        public boolean isBalanced(TreeNode root) { return height(root) != -1; }
        private int height(TreeNode n){
            if (n==null) return 0;
            int lh = height(n.left); if (lh==-1) return -1;
            int rh = height(n.right); if (rh==-1) return -1;
            if (Math.abs(lh-rh) > 1) return -1;
            return 1 + Math.max(lh, rh);
        }
    }
    // @lc code=end
}
