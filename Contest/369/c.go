package main

import (
	"fmt"
	"math"
)

func minIncrementOperations(nums []int, k int) int64 {
	n := len(nums)
	dp := make([]int64, n+1)
	for i := 1; i <= n; i++ {
		dp[i] = 0x3f3f3f3f
	}

	for i := 0; i < n; i++ {
		diff := int64(0)
		if nums[i] < k {
			diff = int64(k - nums[i])
		}
		if i >= 2 {
			for j := i - 2; j < i+1; j++ {
				dp[i+1] = min(dp[i+1], dp[j]+diff)
			}
		} else {
			for j := 0; j < i+1; j++ {
				dp[i+1] = min(dp[i+1], dp[j]+diff)
			}
		}
	}
	ans := int64(math.MaxInt64)
	for _, d := range dp[n-2:] {
		ans = min(ans, d)
	}
	return ans
}

func main() {
	nums := []int{2, 3, 0, 0, 2}
	k := 4
	fmt.Printf("%d\n", minIncrementOperations(nums, k))
}
