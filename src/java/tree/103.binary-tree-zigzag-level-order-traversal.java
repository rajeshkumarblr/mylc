class P103 {
    // @lc app=leetcode id=103 lang=java
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
