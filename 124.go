package main

import "math"

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxPathSum(root *TreeNode) int {
	maxSum := math.MinInt32
	var dfs func(*TreeNode) int
	dfs = func(node *TreeNode) int {
		if node == nil {
			return 0
		}
		l := max(dfs(node.Left), 0)
		r := max(dfs(node.Right), 0)
		sum := node.Val + l + r
		maxSum = max(maxSum, sum)
		return node.Val + max(l, r)
	}

	dfs(root)
	return maxSum
}
