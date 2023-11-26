package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type hp struct{ sort.IntSlice }

func (hp) Pop() (_ interface{}) { return }
func (hp) Push(interface{})     {}
func (h hp) replace(v int) int  { top := h.IntSlice[0]; h.IntSlice[0] = v; heap.Fix(&h, 0); return top }
func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}

// (nums1[i_0] + nums1[i_1] + ... + nums1[i_k-1]) * min(nums2[i_0], nums2[i_1]), ...)
// subsequence -> sort, min -> sort
// need to select the min x from nums2, and select all the num that greater than x from nums2
// in conclustion,
// if nums2 is sorted by descending,
// we can only chose nums2[:i] (those nums are greater than nums2[i], which means that min() should be nums2[i])
// we can only chose nums1[:i]

// now we can chose k nums from nums1[:i]
// use min heap, since ?
// maintain the sum of the heap
func maxScore(nums1 []int, nums2 []int, k int) int64 {
	// sort nums1 by descending nums2
	type pair struct{ x, y int }
	num := make([]pair, len(nums1))
	for i, x := range nums1 {
		num[i] = pair{x, nums2[i]}
	}
	sort.Slice(num, func(i, j int) bool { return num[i].y > num[j].y })

	sum := 0
	h := hp{nums2[:k]} // reuse the memo
	for i, p := range num[:k] {
		sum += p.x
		h.IntSlice[i] = p.x
	}
	ans := sum * num[k-1].y

	heap.Init(&h)
	for _, pa := range num[k:] {
		if pa.x > h.IntSlice[0] {
			sum += pa.x - h.replace(pa.x) // replace and pop the minheap top val，heap.Fix(&h, 0) pass down
			ans = max(ans, sum*pa.y)
		}
	}
	return int64(ans)
}

func main() {
	nums1 := []int{2, 2, 3, 1, 1}
	nums2 := []int{7, 5, 2, 9, 6}
	k := 3
	res := maxScore(nums1, nums2, k)
	fmt.Printf("%d\n", res)
}
