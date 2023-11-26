package main

import "math"

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxProduct(root *TreeNode) int {
	sum, best := 0, 0

	var getTotSum func(*TreeNode)
	getTotSum = func(node *TreeNode) {
		if node == nil {
			return
		}
		sum += node.Val
		getTotSum(node.Left)
		getTotSum(node.Right)
	}

	var getSubSum func(*TreeNode) int
	getSubSum = func(node *TreeNode) int {
		if node == nil {
			return 0
		}
		subsum := getSubSum(node.Left) + getSubSum(node.Right) + node.Val
		// if subsum == sum / 2, (sum - subsum) * subsum is the largest
		if math.Abs(float64(subsum*2-sum)) < math.Abs(float64(best*2-sum)) {
			best = subsum
		}
		return subsum
	}

	getTotSum(root)
	getSubSum(root)
	return best * (sum - best) % (1e9 + 7)
}
