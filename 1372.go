package main

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func longestZigZag(root *TreeNode) int {
	if root == nil {
		return 0
	}
	ans := 0
	var dfs func(*TreeNode, bool, int)
	dfs = func(node *TreeNode, direction bool, dep int) {
		ans = max(ans, dep)
		if direction {
			if node.Right != nil {
				dfs(node.Right, !direction, dep+1)
			}
			if node.Left != nil {
				dfs(node.Left, direction, 1)
			}
		} else {
			if node.Left != nil {
				dfs(node.Left, !direction, dep+1)
			}
			if node.Right != nil {
				dfs(node.Right, direction, 1)
			}
		}
	}
	dfs(root, false, 0)
	dfs(root, true, 0)
	return ans
}
