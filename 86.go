package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	sm := &ListNode{}
	smhead := sm
	lg := &ListNode{}
	lghead := lg

	for head != nil {
		if head.Val < x {
			sm.Next = head
			sm = sm.Next
		} else {
			lg.Next = head
			lg = lg.Next
		}
		head = head.Next
	}
	lg.Next = nil
	sm.Next = lghead.Next
	return smhead.Next
}
