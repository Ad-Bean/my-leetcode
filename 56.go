package main

import (
	"fmt"
	"sort"
)

func merge(intervals [][]int) (ans [][]int) {
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })
	fmt.Printf("intervals %v\n", intervals)
	n := len(intervals)
	ans = append(ans, intervals[0])
	for i := 1; i < n; i++ {
		if intervals[i][0] <= intervals[i-1][1] || intervals[i][0] <= ans[len(ans)-1][1] {
			ans[len(ans)-1][1] = max(intervals[i][1], ans[len(ans)-1][1])
		} else {
			ans = append(ans, intervals[i])
		}
	}
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	intervals := [][]int{{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}}
	fmt.Printf("intervals %v\n", intervals)
	ans := merge(intervals)
	fmt.Printf("%v\n", ans)
}
