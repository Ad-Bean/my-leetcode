package main

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

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func nextLargerNodes(head *ListNode) []int {
	var ans []int
	var stk [][]int
	cur := head
	idx := -1
	for cur != nil {
		idx++
		ans = append(ans, 0)
		for len(stk) > 0 && stk[len(stk)-1][0] < cur.Val {
			top := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			ans[top[1]] = cur.Val
		}
		stk = append(stk, []int{cur.Val, idx})
		cur = cur.Next
	}
	return ans
}
