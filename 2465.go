package main

import (
	"fmt"
	"sort"
)

func distinctAverages(nums []int) int {
	sort.Ints(nums)
	vis := make(map[int]struct{})
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		vis[nums[i]+nums[j]] = struct{}{}
	}
	return len(vis)
}

func main() {
	nums := []int{9, 5, 7, 8, 7, 9, 8, 2, 0, 7}
	res := distinctAverages(nums)
	fmt.Printf("%d\n", res)
}
