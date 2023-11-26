package main

import (
	"container/heap"
	"fmt"
	"sort"
)

/*
nums[] 每次从中选一个数减少到一半
求数组和减少至少一半的最少操作数

每次拿最大的，然后变成一半（最大堆）

*/

type MaxHeap struct{ sort.Float64Slice }

func (h *MaxHeap) Pop() any {
	v := h.Float64Slice[len(h.Float64Slice)-1]
	h.Float64Slice = h.Float64Slice[:len(h.Float64Slice)-1]
	return v
}
func (h *MaxHeap) Push(x any)         { h.Float64Slice = append(h.Float64Slice, x.(float64)) }
func (h *MaxHeap) Less(i, j int) bool { return h.Float64Slice[i] > h.Float64Slice[j] }

func halveArray(nums []int) (cnt int) {
	sum := 0.0
	h := &MaxHeap{}
	for _, num := range nums {
		sum += float64(num)
		h.Float64Slice = append(h.Float64Slice, float64(num))
	}
	heap.Init(h)
	sum /= 2
	for sum > 0 {
		cnt++
		top := heap.Pop(h)
		heap.Push(h, top.(float64)/2)
		sum -= top.(float64) / 2
	}
	return
}

func main() {
	nums := []int{5, 19, 8, 1}
	fmt.Printf("%v\n", halveArray(nums))
}
