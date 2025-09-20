class P94 {
    // @lc app=leetcode id=94 lang=java
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
