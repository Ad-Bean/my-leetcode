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

func mergeSimilarItems(items1 [][]int, items2 [][]int) [][]int {
	mp := map[int]int{}

	for _, item := range items1 {
		mp[item[0]] += item[1]
	}
	for _, item := range items2 {
		mp[item[0]] += item[1]
	}
	var ans [][]int
	for a, b := range mp {
		ans = append(ans, []int{a, b})
	}

	sort.Slice(ans, func(i, j int) bool {
		return ans[i][0] < ans[i][0]
	})

	return ans
}
