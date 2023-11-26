package main

import (
	"sort"
)

func miceAndCheese(reward1 []int, reward2 []int, k int) int {
	ans := 0
	n := len(reward1)
	dif := make([]int, n)
	for i := 0; i < n; i++ {
		dif[i] = reward1[i] - reward2[i]
		ans += reward2[i]
	}
	sort.Ints(dif)
	for i := 0; i < k; i++ {
		ans += dif[n-1-i]
	}
	return ans
}

type IntHeap []int

func (h IntHeap) Less(i, j int) bool {
	return h[i] < h[j]
}
func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}
func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}
func (h IntHeap) Len() int {
	return len(h)
}
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}
