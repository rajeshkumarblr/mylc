package main

/*
 * @lc app=leetcode id=110 lang=golang
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 * Example 2:
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 * Example 3:
 * Input: root = []
 * Output: true
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 5000].
 * - -10^4 <= Node.val <= 10^4
 */

func isBalanced(root *TreeNode) bool {
	var check func(*TreeNode) int
	check = func(node *TreeNode) int {
		if node == nil {
			return 0
		}
		l := check(node.Left)
		r := check(node.Right)
		if l == -1 || r == -1 || abs(l-r) > 1 {
			return -1
		}
		if l > r {
			return l + 1
		}
		return r + 1
	}
	return check(root) != -1
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
