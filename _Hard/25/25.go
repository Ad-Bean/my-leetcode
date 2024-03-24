package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	n := 0
	cur := head
	for cur != nil {
		cur, n = cur.Next, n+1
	}
	dummy := &ListNode{Next: head}
	p0 := dummy
	for n >= k {
		n -= k
		var pre *ListNode
		cur = p0.Next
		for i := 0; i < k; i++ {
			nxt := cur.Next
			cur.Next = pre
			pre = cur
			cur = nxt
		}
		nxt := p0.Next
		p0.Next.Next = cur
		p0.Next = pre
		p0 = nxt
	}
	return dummy.Next
}
