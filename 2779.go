package main

import (
	"math"
)

func maximumJumps(nums []int, target int) int {
	n := len(nums)
	dp := make([]int, n)
	for i := 1; i < n; i++ {
		dp[i] = math.MinInt
		for j := range nums[:i] {
			if nums[i]-nums[j] >= -target && nums[i]-nums[j] <= target {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
	}
	if dp[n-1] < 0 {
		return -1
	}
	return dp[n-1]
}
