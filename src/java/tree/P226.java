package tree;
import common.*;


import java.util.Stack;

public class P226 {
/*
 * @lc app=leetcode id=226 lang=java
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * Given the root of a binary tree, invert the tree, and return its root.
 *
 * Example 1:
 * Input: root = [4,2,7,1,3,6,9]
 * Output: [4,7,2,9,6,3,1]
 *
 * Example 2:
 * Input: root = [2,1,3]
 * Output: [2,3,1]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 100].
 * - -100 <= Node.val <= 100
 */
    // @lc code=start
    public class Solution {
        public TreeNode invertTree(TreeNode root) {
            Stack<TreeNode> stack = new Stack<>();
            stack.push(root);
            while(!stack.isEmpty()) {
                TreeNode node = stack.pop();

                if(node != null){
                    TreeNode temp = node.left;
                    node.left = node.right;
                    node.right = temp;
                    stack.push(node.left);
                    stack.push(node.right);
                }
            }
            return root;        
        }
    }
    // @lc code=end
}

