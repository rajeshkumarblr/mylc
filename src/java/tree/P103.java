package tree;
import common.*;


public class P103 {
/*
 * @lc app=leetcode id=103 lang=java
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * Given the root of a binary tree, return the zigzag level order traversal of
 * its nodes' values. (i.e., from left to right, then right to left for the
 * next level and alternate between).
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
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
 * - -100 <= Node.val <= 100
 */
    // @lc code=start
    public class Solution {
        public java.util.List<java.util.List<Integer>> zigzagLevelOrder(TreeNode root) {
            java.util.List<java.util.List<Integer>> out = new java.util.ArrayList<>();
            if (root==null) return out;
            java.util.ArrayDeque<TreeNode> q = new java.util.ArrayDeque<>();
            q.add(root);
            boolean rev=false;
            while(!q.isEmpty()){
                int sz=q.size();
                java.util.LinkedList<Integer> level = new java.util.LinkedList<>();
                for(int i=0;i<sz;i++){
                    TreeNode n=q.poll();
                    if (!rev) level.addLast(n.val); else level.addFirst(n.val);
                    if (n.left!=null) q.add(n.left);
                    if (n.right!=null) q.add(n.right);
                }
                out.add(new java.util.ArrayList<>(level));
                rev=!rev;
            }
            return out;
        }
    }
    // @lc code=end
}
