/*
 * @lc app=leetcode id=226 lang=java
 *
 * [226] Invert Binary Tree
 */

// @lc code=start

import java.util.Stack;
class TreeNode {
     int val;
     TreeNode left;
    TreeNode right;
     TreeNode() {}
     TreeNode(int val) { this.val = val; }
     TreeNode(int val, TreeNode left, TreeNode right) {
         this.val = val;
         this.left = left;
         this.right = right;
     }
}


class Solution {
    public TreeNode invertTree(TreeNode root) {
        
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while(!stack.isEmpty()) {
            TreeNode node = stack.pop();

            if(node !=null){
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

