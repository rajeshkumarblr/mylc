class P110 {
    // @lc app=leetcode id=110 lang=java
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
