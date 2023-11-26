package main

// dp[i] = max(dp[i-1], nums[i] + i)
func canJump(nums []int) bool {
	n := len(nums)
	end := n - 1
	for i := n - 2; i >= 0; i-- {
		if end-i <= nums[i] {
			end = i
		}
	}
	return end == 0
}
