package main

import "math"

// 节点的左子树只包含 小于 当前节点的数。
// 节点的右子树只包含 大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。
// DFS
func isisValidBST(root *TreeNode) bool {
	var dfs func(*TreeNode, int, int) bool
	dfs = func(node *TreeNode, lower, upper int) bool {
		if node == nil {
			return true
		}
		if node.Val <= lower || node.Val >= upper {
			return false
		}

		return dfs(node.Left, lower, node.Val) && dfs(node.Right, node.Val, upper)
	}
	return dfs(root, math.MinInt64, math.MaxInt64)
}

// 中序遍历（左中右）是升序
func isValidBST(root *TreeNode) bool {
	stk := []*TreeNode{}
	prevMax := math.MinInt64
	for len(stk) > 0 || root != nil {
		for root != nil {
			stk = append(stk, root)
			root = root.Left
		}
		root = stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		// ascending
		if root.Val <= prevMax {
			return false
		}
		prevMax = root.Val
		root = root.Right
	}
	return true

}
