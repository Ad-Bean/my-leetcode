package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	var pre, cur *ListNode = nil, head
	for cur != nil {
		nxt := cur.Next
		cur.Next = pre
		pre = cur
		cur = nxt
	}
	return pre
}

func addTwo(l, r *ListNode) *ListNode {
	dummy := &ListNode{}
	cur := dummy
	carry := 0
	for l != nil || r != nil || carry != 0 {
		if l != nil {
			carry += l.Val
		}
		if r != nil {
			carry += r.Val
		}
		cur.Next = &ListNode{Val: carry % 10}
		carry = carry / 10
		cur = cur.Next
		if l != nil {
			l = l.Next
		}
		if r != nil {
			r = r.Next
		}
	}
	return dummy.Next
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	l1 = reverseList(l1)
	l2 = reverseList(l2)
	sum := addTwo(l1, l2)
	return reverseList(sum)
}
