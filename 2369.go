package main

func validPartition(nums []int) bool {
	n := len(nums)
	dp := make([]bool, n+1)
	dp[0] = true
	for i, num := range nums {
		if i > 0 && dp[i-1] && num == nums[i-1] || i > 1 && dp[i-2] && (num == nums[i-1] && num == nums[i-2] || num == nums[i-1]+1 && num == nums[i-2]+2) {
			dp[i+1] = true
		}
	}
	return dp[n]
}
