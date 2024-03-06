package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return false
	}
	l, r := head, head.Next
	for l != r {
		if r == nil || r.Next == nil {
			return false
		}
		l = l.Next
		r = r.Next.Next
	}
	return true
}
