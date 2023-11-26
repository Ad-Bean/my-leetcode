package main

//  Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{
		Val:  0,
		Next: head,
	}

	fir, sec := head, dummy
	for i := 0; i < n; i++ {
		fir = fir.Next
	}
	for ; fir != nil; fir = fir.Next {
		sec = sec.Next
	}

	sec.Next = sec.Next.Next
	// head maybe nil, e.g. head =[1], n = 1
	return dummy.Next
}
