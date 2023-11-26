package main

func findTargetSumWays(nums []int, target int) int {
	for _, num := range nums {
		target += num
	}
	if target < 0 || target&1 == 1 {
		return 0
	}

	target = target >> 1
	dp := make([]int, target+1)
	dp[0] = 1
	for _, num := range nums {
		for c := target; c >= num; c-- {
			dp[c] += dp[c-num]
		}
	}
	return dp[target]
}
