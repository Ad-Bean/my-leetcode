package main

// dp[i][0]
// dp[i][1]
// 表示 nums[0:i] 中选一个子序列，最后一个下标为偶数 0 和奇数 1 的最大和

// 前i个数，长为偶数，选或不选 nums[i]：
// dp[i][0] = (dp[i-1][1]+nums[i], dp[i-1][0])

// 前i个数，长为奇数，选或不选 nums[i]：
// dp[i][1] = max(dp[i-1][0] - nums[i], dp[i-1][1])

// dp[0][0] = 0
// dp[0][1] = ?
// 5,6,7,8
// dp[0][0], d[0][1] = 0, -INF
// dp[1][0] = max(?-5, ?)   			dp[1][1] = max(0, 5)
// dp[2][0] = max(5-6, ?)     			dp[2][1] = max()
// dp[3][0] = -2     				dp[3][1] = max(-INF, 7)
func maxAlternatingSum(nums []int) int64 {
	even, odd := -0x3f3f3f3f, 0
	for _, num := range nums {
		_even, _odd := even, odd
		even, odd = max(_even, _odd+num), max(_even-num, _odd)
	}
	return int64(max(even, odd))
}
