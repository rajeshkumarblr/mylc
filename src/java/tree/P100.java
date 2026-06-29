package tree;
import common.*;


public class P100 {
/*
 * @lc app=leetcode id=100 lang=java
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
 */
    // @lc code=start
    public class Solution {
        public boolean isSameTree(TreeNode p, TreeNode q) {
            if (p==null || q==null) return p==q;
            if (p.val!=q.val) return false;
            return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        }
    }
    // @lc code=end
}
