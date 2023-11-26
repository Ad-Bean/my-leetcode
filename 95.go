package main

import (
	"fmt"
)

/**
 * Definition for a binary tree node. */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func check(start, end int) []*TreeNode {
	if start > end {
		return []*TreeNode{nil}
	}
	all := []*TreeNode{}
	for i := start; i <= end; i++ {
		left := check(start, i-1)
		right := check(i+1, end)
		fmt.Printf("%d %d %s %s \n", start, end, left, right)
		for _, l := range left {
			for _, r := range right {
				cur := &TreeNode{i, nil, nil}
				cur.Left = l
				cur.Right = r
				all = append(all, cur)
			}
		}
	}
	fmt.Printf("start: %d end: %d ans: %s\n", start, end, all)
	return all
}

func generateTrees(n int) []*TreeNode {
	if n == 0 {
		return nil
	}
	return check(1, n)
}

func main() {
	n := 3
	ans := generateTrees(n)
	fmt.Printf("%s\n", ans)
}
