package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var move int

func distributeCoins(root *TreeNode) int {
	move = 0
	dfs(root)
	return move
}

func dfs(root *TreeNode) int {
	moveleft := 0
	moveright := 0
	if root == nil {
		return 0
	}
	if root.Left != nil {
		moveleft = dfs(root.Left)
	}
	if root.Right != nil {
		moveright = dfs(root.Right)
	}
	move += abs(moveleft) + abs(moveright)
	return moveleft + moveright + root.Val - 1
}

func abs(a int) int {
	if a < 0 {
		a = -a
	}
	return a
}
