package main

// dp[i] = max(dp[i-1], dp[i-2]+nums[i])
func rob(nums []int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}
	if n == 1 {
		return nums[0]
	}
	// dp := make([]int, n)
	// dp[0] = nums[0]
	// dp[1] = max(nums[0], nums[1])
	fir, sec := nums[0], max(nums[0], nums[1])
	for i := 2; i < n; i++ {
		// dp[i] = max(dp[i-1], dp[i-2]+nums[i])
		tmp := sec
		sec = max(fir+nums[i], sec)
		fir = tmp
	}
	return sec
}
