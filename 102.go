package main

/**
 * Definition for a binary tree node. */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) (res [][]int) {
	if root == nil {
		return res
	}
	que := []*TreeNode{root}
	for len(que) > 0 {
		sz := len(que)
		cur := []int{}
		for i := 1; i <= sz; i++ {
			node := que[0]
			que = que[1:]
			cur = append(cur, node.Val)
			if node.Left != nil {
				que = append(que, node.Left)
			}
			if node.Right != nil {
				que = append(que, node.Right)
			}
		}
		res = append(res, cur)
	}
	return res
}
