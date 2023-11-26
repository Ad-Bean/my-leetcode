package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	var dfs func(*TreeNode) (int, *TreeNode)
	dfs = func(node *TreeNode) (int, *TreeNode) {
		if node == nil {
			return 0, nil
		}
		l, lca1 := dfs(node.Left)
		r, lca2 := dfs(node.Right)
		if l > r {
			return l + 1, lca1
		}
		if l < r {
			return r + 1, lca2
		}
		return l + 1, node
	}
	_, lca := dfs(root)
	return lca
}
