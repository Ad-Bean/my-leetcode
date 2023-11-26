package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func goodNodes(root *TreeNode) int {
	var dfs func(*TreeNode, int) int
	dfs = func(cur *TreeNode, mx int) int {
		if cur == nil {
			return 0
		}
		l := dfs(cur.Left, max(mx, root.Val))
		r := dfs(cur.Right, max(mx, root.Val))
		if root.Val >= mx {
			return l + r + 1
		}
		return l + r
	}
	return dfs(root, root.Val)
}
