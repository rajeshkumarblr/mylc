class P98 {
    // @lc app=leetcode id=98 lang=java
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
