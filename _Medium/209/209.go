package main

func minSubArrayLen(target int, nums []int) int {
	n := len(nums)
	sum, l, ans := 0, 0, n+1
	for r := 0; r < n; r++ {
		sum += nums[r]
		for sum-nums[l] >= target {
			sum -= nums[l]
			l++
		}
		if sum >= target {
			ans = min(ans, r-l+1)
		}
	}
	if ans > n {
		return 0
	}
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
