package main

/**
 * Definition for singly-linked list.*/
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}
	dummy := &ListNode{0, &ListNode{}}
	head := dummy
	for list1 != nil && list2 != nil {
		if list1.Val < list2.Val {
			head.Next = &ListNode{list1.Val, &ListNode{}}
			list1 = list1.Next
		} else {
			head.Next = &ListNode{list2.Val, &ListNode{}}
			list2 = list2.Next
		}
		head = head.Next
	}
	if list1 != nil {
		head.Next = list1
	} else if list2 != nil {
		head.Next = list2
	}
	return dummy.Next
}
