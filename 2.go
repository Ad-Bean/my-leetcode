package main

import (
	"fmt"
)

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	l, r := l1, l2
	dummy := &ListNode{Val: -1, Next: &ListNode{}}
	cur := dummy
	carry := 0
	for l != nil && r != nil {
		sum := l.Val + r.Val + carry
		cur.Next = &ListNode{Val: sum % 10, Next: nil}
		carry = sum / 10
		l = l.Next
		r = r.Next
		cur = cur.Next
	}
	for l != nil {
		sum := l.Val + carry
		cur.Next = &ListNode{Val: sum % 10, Next: nil}
		carry = sum / 10
		l = l.Next
		cur = cur.Next
	}
	for r != nil {
		sum := r.Val + carry
		cur.Next = &ListNode{Val: sum % 10, Next: nil}
		carry = sum / 10
		r = r.Next
		cur = cur.Next
	}
	if carry != 0 {
		cur.Next = &ListNode{Val: carry, Next: nil}
		cur = cur.Next
	}
	return dummy.Next
}

func main() {
	l1 := &ListNode{Val: 2, Next: nil}
	l1n := &ListNode{Val: 4, Next: nil}
	l1nn := &ListNode{Val: 3, Next: nil}
	l1.Next = l1n
	l1n.Next = l1nn
	l2 := &ListNode{Val: 5, Next: nil}
	l2n := &ListNode{Val: 6, Next: nil}
	l2nn := &ListNode{Val: 4, Next: nil}
	l2.Next = l2n
	l2n.Next = l2nn
	t := addTwoNumbers(l1, l2)
	fmt.Printf("%v\n", t)
	fmt.Printf("%v\n", t.Next)
	fmt.Printf("%v\n", t.Next.Next)
}

//  999
//  999
//  998
