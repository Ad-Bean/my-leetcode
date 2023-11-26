package main

/**
Definition for singly-linked list.*/
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	var pre, cur *ListNode = nil, head
	for cur != nil {
		nex := cur.Next
		cur.Next = pre
		pre = cur
		cur = nex
	}
	return pre
}

func reorderList(head *ListNode) {
	if head == nil {
		return
	}
	slow, fast := head, head
	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	l, r := head, slow.Next
	slow.Next = nil
	r = reverseList(r)
	for l != nil && r != nil {
		tmp1, tmp2 := l.Next, r.Next
		l.Next = r
		l = tmp1
		r.Next = l
		r = tmp2
	}
	return
}
