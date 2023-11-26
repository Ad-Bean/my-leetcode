package main

import (
	"sort"
)

func minimumRightShifts(nums []int) int {
	n := len(nums)
	prev := make([]int, n)
	for i := 0; i < n; i++ {
		prev[i] = nums[i]
	}
	sort.Ints(prev)

	k := 0
	for i := 0; i < n; i++ {
		if nums[i] == prev[0] {
			k = i
			break
		}
	}
	for i := 0; i < n; i++ {
		if prev[i] != nums[(i+k)%n] {
			return -1
		}
	}
	if k == 0 {
		return 0
	}
	return min(k-1, n-k-1)
}
