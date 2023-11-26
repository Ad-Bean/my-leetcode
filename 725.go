package main

import "fmt"

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func splitListToParts(head *ListNode, k int) []*ListNode {
	n, cur := 0, head
	for cur != nil {
		n++
		cur = cur.Next
	}
	fmt.Printf("%v\n", n)
	tot, lef := n/k, n%k

	ans := make([]*ListNode, tot)
	cur = head
	for i := 0; i < k; i++ {
		ans[i] = cur
		sz := n / k
		if i < lef {
			sz++
		}
		for j := 1; j < sz; j++ {
			cur = cur.Next
		}
		cur, cur.Next = cur.Next, nil
	}
	return ans
}
