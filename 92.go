package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	dummy := &ListNode{Val: 0, Next: head}
	l := dummy
	for i := 0; i < left-1; i++ {
		l = l.Next
	}
	var pre *ListNode
	cur := l.Next
	for i := 0; i < right-left+1; i++ {
		nxt := cur.Next
		cur.Next = pre
		pre = cur
		cur = nxt
	}
	l.Next.Next = cur
	l.Next = 

	return
}
