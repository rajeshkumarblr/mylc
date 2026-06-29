package tree;
import common.*;


public class P102 {
/*
 * @lc app=leetcode id=102 lang=java
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 2000].
 * - -1000 <= Node.val <= 1000
 */
    // @lc code=start
    public class Solution {
        public java.util.List<java.util.List<Integer>> levelOrder(TreeNode root) {
            java.util.List<java.util.List<Integer>> out = new java.util.ArrayList<>();
            if (root==null) return out;
            java.util.ArrayDeque<TreeNode> q = new java.util.ArrayDeque<>();
            q.add(root);
            while(!q.isEmpty()){
                int sz = q.size();
                java.util.List<Integer> level = new java.util.ArrayList<>(sz);
                for(int i=0;i<sz;i++){
                    TreeNode n = q.poll();
                    level.add(n.val);
                    if (n.left!=null) q.add(n.left);
                    if (n.right!=null) q.add(n.right);
                }
                out.add(level);
            }
            return out;
        }
    }
    // @lc code=end
}
