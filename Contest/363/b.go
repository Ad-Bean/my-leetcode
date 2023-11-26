package main

import "sort"

func countWays(nums []int) (ans int) {
	sort.Ints(nums)
	n := len(nums)

	for i := n - 1; i >= 0; i-- {
		if i+1 > nums[i] {
			if i < n-1 && i+1 < nums[i+1] {
				ans++
			} else if i == n-1 {
				ans++
			}
		}
	}
	// 不选
	if nums[0] > 0 {
		ans++
	}
	return
}
