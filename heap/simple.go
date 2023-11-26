package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type maxHeap struct{ sort.IntSlice }

func (h maxHeap) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h maxHeap) Push(any)           {}
func (h maxHeap) Pop() (_ any)       { return }

// 大根堆
// func (h *hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }

func main() {
	nums := []int{-123, 1, 2222, 3, 4, 5, 6}
	mxh := &maxHeap{nums}
	heap.Init(mxh)
	// for _, num := range nums {
	// 	mxh.IntSlice = append(mxh.IntSlice, num)
	// }
	fmt.Printf("%v\n", mxh.IntSlice[0])
	_ = heap.Pop(mxh)
	fmt.Printf("%v\n", mxh.IntSlice[0])
	// -123
}
