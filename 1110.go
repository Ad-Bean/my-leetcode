package main

/**
 * Definition for a binary tree node. */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 后序遍历，左右中
func delNodes(root *TreeNode, to_delete []int) (ans []*TreeNode) {
	mp := make(map[int]struct{}, len(to_delete))
	for _, x := range to_delete {
		mp[x] = struct{}{} // optimize memo
	}
	var dfs func(*TreeNode) *TreeNode
	dfs = func(node *TreeNode) *TreeNode {
		if node == nil {
			return nil
		}
		node.Left = dfs(node.Left)
		node.Right = dfs(node.Right)
		if _, ok := mp[node.Val]; !ok {
			return node
		}

		if node.Left != nil {
			ans = append(ans, node.Left)
		}
		if node.Right != nil {
			ans = append(ans, node.Right)
		}
		return nil
	}
	if dfs(root) != nil {
		ans = append(ans, root)
	}
	return
}
