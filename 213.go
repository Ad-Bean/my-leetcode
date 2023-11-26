package main

// dp[i] = max(dp[i-2]+nums[i], dp[i-1])
func dp(nums []int) int {
	fir, sec := nums[0], max(nums[0], nums[1])
	for _, num := range nums[2:] {
		fir, sec = sec, max(fir+num, sec)
	}
	return sec
}
func rob(nums []int) int {
	n := len(nums)
	if n == 1 {
		return nums[0]
	}
	if n == 2 {
		return max(nums[0], nums[1])
	}
	return max(dp(nums[:n-1]), dp(nums[1:]))
}
