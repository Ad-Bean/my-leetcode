package main

// dp[i] the number of plans
// dp[0] = 1
// dp[1] = dp[1-coins[i]] + 1
// 5, [1,2,5]

// dp[0] = 1

// 1
// 1...5 dp[1] += dp[1-1], dp[2] += dp[2-1], dp[3] += dp[3-1]
// 2
// 2..5 dp[2] += dp[2-2], dp[3] += dp[3-2]
// 当前面额 2, dp[3] += dp[1] 表示组成 1 的方案可以的

func change(amount int, coins []int) int {
	dp := make([]int, amount+1)
	dp[0] = 1
	for _, coin := range coins {
		for i := coin; i <= amount; i++ {
			dp[i] += dp[i-coin]
		}
	}
	return dp[amount]
}
