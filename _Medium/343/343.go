package main

func integerBreak(n int) int {
	dp := make([]int, n+1)
	for i := 2; i <= n; i++ {
		curmax := 0
		for j := 1; j < i; j++ {
			curmax := max(curmax, max(j*(i-j), j*dp[i-j]))
		}
		dp[i] = curmax
	}
	return dp[n]
}

/*

如果 n >= 2 可以拆成 x 和 n - x，或者继续拆
dp[i] 表示 i 拆成两个正整数之后的最大乘积
dp[0] = dp[1] = 0

dp[i] = max(j * dp[i-j], j * (i-j))
*/
