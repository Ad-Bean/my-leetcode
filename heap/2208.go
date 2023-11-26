package main

import (
	"container/heap"
	"sort"
)

type hp struct{ sort.Float64Slice }

func (h hp) Less(i, j int) bool { return h.Float64Slice[i] > h.Float64Slice[j] } // max heap
func (h hp) Push(any)           {}
func (h hp) Pop() (_ any)       { return }

func halveArray(nums []int) (ans int) {
	h := hp{}
	half := float64(0)
	for i := range nums {
		h.Float64Slice = append(h.Float64Slice, float64(nums[i]))
		half += float64(nums[i])
	}
	heap.Init(&h)

	for half /= 2; half > 0; ans++ {
		half -= (h.Float64Slice[0] / 2)
		h.Float64Slice[0] /= 2
		heap.Fix(&h, 0)
	}
	return
}
