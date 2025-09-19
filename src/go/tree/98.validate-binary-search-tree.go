package main

// 98. Validate Binary Search Tree
// Function signature expected by the harness: func(*TreeNode) bool
// Implementation uses DFS with range constraints (open interval).
func isValidBST(root *TreeNode) bool {
	var dfs func(n *TreeNode, low *int, high *int) bool
	dfs = func(n *TreeNode, low *int, high *int) bool {
		if n == nil {
			return true
		}
		if low != nil && n.Val <= *low {
			return false
		}
		if high != nil && n.Val >= *high {
			return false
		}
		// Left subtree: all values must be < n.Val
		if !dfs(n.Left, low, &n.Val) {
			return false
		}
		// Right subtree: all values must be > n.Val
		if !dfs(n.Right, &n.Val, high) {
			return false
		}
		return true
	}
	return dfs(root, nil, nil)
}
