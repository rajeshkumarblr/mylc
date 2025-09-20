class P104 {
    // @lc app=leetcode id=104 lang=java
    // @lc code=start
    public class Solution {
        // Maximum Depth of Binary Tree
        // DFS depth: O(n) time, O(h) stack
        public int maxDepth(TreeNode root) {
            if (root == null) return 0;
            int left = maxDepth(root.left);
            int right = maxDepth(root.right);
            return 1 + (left > right ? left : right);
        }
    }
    // @lc code=end

    // Local wrapper for harness
    static int run(TreeNode root) { return new P104().new Solution().maxDepth(root); }
}
