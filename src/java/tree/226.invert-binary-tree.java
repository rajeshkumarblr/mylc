import java.util.Stack;

class P226 {
    // @lc app=leetcode id=226 lang=java
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

