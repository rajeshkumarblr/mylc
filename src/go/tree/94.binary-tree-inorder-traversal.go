package main

func inorderTraversal(root *TreeNode) []int {
	res := []int{}
	var helper func(*TreeNode)
	helper = func(node *TreeNode) {
		if node == nil {
			return
		}
		helper(node.Left)
		res = append(res, node.Val)
		helper(node.Right)
	}
	helper(root)
	return res
}
