package main

/**
 * Definition for singly-linked list. */
type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{0, head}
	t := dummy
	for t.Next != nil && t.Next.Next != nil {
		node1, node2 := t.Next, t.Next.Next

		node1.Next = node2.Next
		node2.Next = node1
		t.Next = node2
		t = node1
	}
	return dummy.Next
}
