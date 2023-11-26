package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
	i, j := 0, 0
	stk := []int{}
	for head != nil {
		stk = append(stk, head.Val)
		head = head.Next
		j++
	}
	j--
	for i < j {
		if stk[i] != stk[j] {
			stk[i] ^= stk[j]
			stk[j] ^= stk[i]
			stk[i] ^= stk[j]
		}
	}
	return stk
}

func main() {
}
