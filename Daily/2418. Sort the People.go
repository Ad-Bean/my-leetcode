package main

import "sort"

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
func sortPeople(names []string, heights []int) []string {
	n := len(names)
	indices := make([]int, n)
	for i := 0; i < n; i++ {
		indices[i] = i
	}
	sort.Slice(indices, func(i, j int) bool {
		return heights[indices[j]] < heights[indices[i]]
	})
	res := make([]string, n)
	for i := 0; i < n; i++ {
		res[i] = names[indices[i]]
	}
	return res
}
