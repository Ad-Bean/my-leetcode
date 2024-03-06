package main

import (
	"container/heap"
	"sort"
)

type hp struct{ sort.IntSlice }

var a []int

func (h hp) Less(i, j int) bool { return a[h.IntSlice[i]] > a[h.IntSlice[j]] }
func (h *hp) Pop() any          { a := h.IntSlice; v := a[len(a)-1]; h.IntSlice = a[:len(a)-1]; return v }
func (h *hp) Push(x any)        { h.IntSlice = append(h.IntSlice, x.(int)) }

func maxSlidingWindow(nums []int, k int) []int {
	a = nums
	h := &hp{make([]int, k)}
	for i := 0; i < k; i++ {
		h.IntSlice[i] = i
	}
	heap.Init(h)

	ans := []int{nums[h.IntSlice[0]]}
	for i := k; i < len(nums); i++ {
		heap.Push(h, i)
		for h.IntSlice[0]+k <= i {
			heap.Pop(h)
		}
		ans = append(ans, nums[h.IntSlice[0]])
	}
	return ans
}
