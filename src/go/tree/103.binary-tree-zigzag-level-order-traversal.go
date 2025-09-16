package main

// 103. Binary Tree Zigzag Level Order Traversal
// BFS with alternating insertion order by reversing index mapping.
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
