package main

func lengthOfLIS(nums []int) int {
	dp := []int{}
	for _, num := range nums {
		l, r := 0, len(dp)
		for l < r {
			m := l + (r-l)/2
			if dp[m] < num {
				l = m + 1
			} else {
				r = m
			}
		}
		if r == len(dp) {
			dp = append(dp, num)
		} else {
			dp[r] = num
		}
	}
	return len(dp)
}
