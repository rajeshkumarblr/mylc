package tree;
import common.*;


public class P98 {
/*
 * @lc app=leetcode id=98 lang=java
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * Given the root of a binary tree, determine if it is a valid binary search
 * tree (BST).
 *
 * A valid BST is defined as follows:
 * - The left subtree of a node contains only nodes with keys less than the
 *   node's key.
 * - The right subtree of a node contains only nodes with keys greater than the
 *   node's key.
 * - Both the left and right subtrees must also be binary search trees.
 *
 * Example 1:
 * Input: root = [2,1,3]
 * Output: true
 *
 * Example 2:
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 10^4].
 * - -2^31 <= Node.val <= 2^31 - 1
 */
    // @lc code=start
    public class Solution {
        public boolean isValidBST(TreeNode root) { return dfs(root, null, null); }
        private boolean dfs(TreeNode n, Long lo, Long hi){
            if (n==null) return true;
            long v = n.val;
            if ((lo!=null && v<=lo) || (hi!=null && v>=hi)) return false;
            return dfs(n.left, lo, v) && dfs(n.right, v, hi);
        }
    }
    // @lc code=end
}
