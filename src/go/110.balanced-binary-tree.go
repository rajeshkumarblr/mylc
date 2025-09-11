package main

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
