package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

type maxHeap struct {
	sort.IntSlice
}

// must be pointer
func (h *maxHeap) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *maxHeap) Pop() any {
	v := h.IntSlice[len(h.IntSlice)-1]
	h.IntSlice = h.IntSlice[:len(h.IntSlice)-1]
	return v
}
func (h *maxHeap) Push(x any) { h.IntSlice = append(h.IntSlice, x.(int)) }
func (h *maxHeap) Len() int   { return len(h.IntSlice) }

func maxKelements(nums []int, k int) (sum int64) {
	h := &maxHeap{nums}
	heap.Init(h)
	for k > 0 {
		m := heap.Pop(h)
		sum += int64(m.(int))
		heap.Push(h, int(math.Ceil(float64(m.(int))/3.0)))
		k--
	}
	return
}

func main() {
	num := []int{10, 10, 10, 10, 10}
	k := 5
	fmt.Printf("%d\n", maxKelements(num, k))

}
