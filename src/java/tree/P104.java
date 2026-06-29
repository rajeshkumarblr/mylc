package tree;
import common.*;


public class P104 {
/*
 * @lc app=leetcode id=104 lang=java
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * Given the root of a binary tree, return its maximum depth.
 *
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 *
 * Example 2:
 * Input: root = [1,null,2]
 * Output: 2
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 10^4].
 * - -100 <= Node.val <= 100
 */
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
    public static int run(TreeNode root) { return new P104().new Solution().maxDepth(root); }
}
