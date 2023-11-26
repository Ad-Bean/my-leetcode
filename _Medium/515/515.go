package main

import "math"

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func largestValues(root *TreeNode) (ans []int) {
	if root == nil {
		return []int{}
	}
	que := []*TreeNode{root}
	for len(que) > 0 {
		sz := len(que)
		curMax := math.MinInt
		for i := 0; i < sz; i++ {
			cur := que[0]
			que = que[1:]
			if cur.Val > curMax {
				curMax = cur.Val
			}
			if cur.Left != nil {
				que = append(que, cur.Left)
			}
			if cur.Right != nil {
				que = append(que, cur.Right)
			}
		}
		ans = append(ans, curMax)
	}
	return
}
