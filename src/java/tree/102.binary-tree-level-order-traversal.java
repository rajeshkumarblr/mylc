class P102 {
    // @lc app=leetcode id=102 lang=java
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
