package main

func maxProfit(prices []int) int {
	n := len(prices)
	f := make([][3]int, n)
	f[0][0] = -prices[0]
	for i := 1; i < n; i++ {
		f[i][0] = max(f[i-1][0], f[i-1][2]-prices[i]) // 持有股票
		f[i][1] = f[i-1][0] + prices[i]               // 不持有股票，在冷冻期
		f[i][2] = max(f[i-1][2], f[i-1][1])           // 不持有股票，不在冷冻期
	}
	return max(f[n-1][1], f[n-1][2])
}
