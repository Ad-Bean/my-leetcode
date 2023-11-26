package main

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// dp[i] = max(dp[j] + maxValue * (i - j)), j \in {[i - k, i - 1]
func maxSumAfterPartitioning(arr []int, k int) int {
	n := len(arr)
	dp := make([]int, n+1)
	for i := 1; i <= n; i++ {
		maxValue := arr[i-1]
		for j := i - 1; j >= max(0, i-k); j-- {
			dp[i] = max(dp[i], dp[j]+maxValue*(i-j))
			if j > 0 && arr[j-1] > maxValue {
				maxValue = arr[j-1]
			}
		}

	}
	return dp[n]
}
