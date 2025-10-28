package main

/*
 * @lc app=leetcode id=226 lang=golang
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	// Swap left and right children
	root.Left, root.Right = root.Right, root.Left

	// Recursively invert subtrees
	invertTree(root.Left)
	invertTree(root.Right)

	return root
}

// @lc code=end
