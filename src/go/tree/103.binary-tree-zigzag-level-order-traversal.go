package main

/*
 * @lc app=leetcode id=103 lang=golang
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * Given the root of a binary tree, return the zigzag level order traversal of
 * its nodes' values. (i.e., from left to right, then right to left for the
 * next level and alternate between).
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 *
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 2000].
 * - -100 <= Node.val <= 100
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
	res := [][]int{}
	if root == nil {
		return res
	}
	q := []*TreeNode{root}
	leftToRight := true
	for len(q) > 0 {
		sz := len(q)
		lvl := make([]int, sz)
		for i := 0; i < sz; i++ {
			n := q[0]
			q = q[1:]
			idx := i
			if !leftToRight {
				idx = sz - 1 - i
			}
			lvl[idx] = n.Val
			if n.Left != nil {
				q = append(q, n.Left)
			}
			if n.Right != nil {
				q = append(q, n.Right)
			}
		}
		res = append(res, lvl)
		leftToRight = !leftToRight
	}
	return res
}
