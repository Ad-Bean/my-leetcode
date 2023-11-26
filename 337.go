package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/*
树形 dp

*/

func rob(root *TreeNode) int {
	// max:=func(a,b int) int {if a > b {return a}; return b}
	var dfs func(*TreeNode) []int
	dfs = func(node *TreeNode) []int {
		if node == nil {
			return []int{0, 0}
		}
		l, r := dfs(node.Left), dfs(node.Right)
		selectCur := node.Val + l[1] + r[1]
		notSelectCur := max(l[0], l[1]) + max(r[0], r[1])
		return []int{selectCur, notSelectCur}
	}
	val := dfs(root)
	return max(val[0], val[1])
}
