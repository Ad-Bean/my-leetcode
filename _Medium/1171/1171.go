package main

/** */
type ListNode struct {
	Val  int
	Next *ListNode
}

func removeZeroSumSublists(head *ListNode) *ListNode {
	dummy := &ListNode{Val: 0, Next: head}
	vis := map[int]*ListNode{}
	prev := 0
	for node := dummy; node != nil; node = node.Next {
		prev += node.Val
		vis[prev] = node
	}
	prev = 0
	for node := dummy; node != nil; node = node.Next {
		prev += node.Val
		node.Next = vis[prev].Next
	}
	return dummy.Next
}
