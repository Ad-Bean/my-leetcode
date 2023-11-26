package main

// dp[i] = max(dp[i], dp[i- nums[i]] + nums[i])
func canPartition(nums []int) bool {
	sum := 0
	for _, num := range nums {
		sum += num
	}
	if sum&1 == 1 {
		return false
	}

	t := sum / 2
	dp := make([]int, t+1)
	for _, num := range nums {
		for j := t; j >= num; j-- {
			if dp[j] < dp[j-num]+num {
				dp[j] = dp[j-num] + num
			}
		}
	}
	return dp[t] == t
}
