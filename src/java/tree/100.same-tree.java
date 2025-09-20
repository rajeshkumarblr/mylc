class P100 {
    // @lc app=leetcode id=100 lang=java
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
