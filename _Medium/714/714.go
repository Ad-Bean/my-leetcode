package main

func maxProfit(prices []int, fee int) int {
	n := len(prices)
	dp := make([][]int, n)
	dp[0][1] = -prices[0]
	for i := 0; i < n; i++ {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee) // 没有股票
		dp[i][1] = max(dp[i-1][1], dp[i-1]-prices[i])        // 有股票
	}
	return dp[n-1][0]
}
