package main

import (
	"container/heap"
	"fmt"
)

type hp [][2]int

func (h hp) Len() int               { return len(h) }
func (h hp) Swap(i int, j int)      { h[i], h[j] = h[j], h[i] }
func (h hp) Less(i int, j int) bool { return h[i][1] < h[j][1] }
func (h *hp) Push(x any)            { *h = append(*h, x.([2]int)) }
func (h *hp) Pop() any              { cur := (*h)[len(*h)-1]; *h = (*h)[:len(*h)-1]; return cur }

func topKFrequent(nums []int, k int) (ans []int) {
	mp := map[int]int{}
	for _, num := range nums {
		mp[num]++
	}
	h := &hp{}
	heap.Init(h)
	for kk, vv := range mp {
		heap.Push(h, [2]int{kk, vv})
		if h.Len() > k {
			heap.Pop(h)
		}
	}
	for i := 0; i < k; i++ {
		ans = append(ans, heap.Pop(h).([2]int)[0])
	}
	return
}

func main() {
	nums := []int{1, 1, 1, 2, 2, 3}
	k := 2
	ans := topKFrequent(nums, k)
	for _, x := range ans {
		fmt.Printf("%d\n", x)
	}
}
