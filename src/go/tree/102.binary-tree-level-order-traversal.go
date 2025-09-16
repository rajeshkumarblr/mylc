package main

// 102. Binary Tree Level Order Traversal
// BFS collecting nodes per level.
func levelOrder(root *TreeNode) [][]int {
	res := [][]int{}
	if root == nil {
		return res
	}
	q := []*TreeNode{root}
	for len(q) > 0 {
		sz := len(q)
		lvl := make([]int, 0, sz)
		for i := 0; i < sz; i++ {
			n := q[0]
			q = q[1:]
			lvl = append(lvl, n.Val)
			if n.Left != nil {
				q = append(q, n.Left)
			}
			if n.Right != nil {
				q = append(q, n.Right)
			}
		}
		res = append(res, lvl)
	}
	return res
}
