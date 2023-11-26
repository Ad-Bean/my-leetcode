package main

import (
	"sort"
)

func findValueOfPartition(nums []int) int {
	sort.Ints(nums)
	maxGap := 0x3f3f3f3f
	for i := 1; i < len(nums); i++ {
		maxGap = min(maxGap, nums[i]-nums[i-1])
	}
	return maxGap
}
