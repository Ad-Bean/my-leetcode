package main

func maxCoins(nums []int) int {
	n := len(nums)
	arr := make([]int, n+2)
	arr[0], arr[n+1] = 1, 1
	for i := 1; i <= n; i++ {
		arr[i] = nums[i-1]
	}
	dp := make([][]int, n+2)
	for i := 0; i < n+2; i++ {
		dp[i] = make([]int, n+2)
	}
	for len := 3; len <= n+2; len++ {
		for l := 0; l+len-1 <= n+1; l++ {
			r := l + len - 1
			for k := l + 1; k <= r-1; k++ {
				dp[l][r] = max(dp[l][r], dp[l][k]+dp[k][r]+arr[l]*arr[k]*arr[r])
			}
		}
	}
	return dp[0][n+1]
}
