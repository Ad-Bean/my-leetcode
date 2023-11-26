package main

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

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

const INF = 0x3f3f3f3f

type SubTree struct {
	IsBST  bool
	MinVal int
	MaxVal int
	SumVal int
}

var res int

func dfs(root *TreeNode) *SubTree {
	if root == nil {
		return &SubTree{true, INF, -INF, 0}
	}
	left := dfs(root.Left)
	right := dfs(root.Right)

	if left.IsBST && right.IsBST && root.Val > left.MaxVal && root.Val < right.MinVal {
		sum := root.Val + left.SumVal + right.SumVal
		res = max(res, sum)
		return &SubTree{true, min(left.MinVal, root.Val), max(root.Val, right.MaxVal), sum}
	} else {
		return &SubTree{false, 0, 0, 0}
	}
}

func maxSumBST(root *TreeNode) int {
	res = 0
	dfs(root)
	return res
}
