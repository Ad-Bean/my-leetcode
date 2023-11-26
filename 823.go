package main

import "sort"

func numFactoredBinaryTrees(arr []int) int {
	sort.Ints(arr)
	dp := make([]int64, len(arr))
	res, mod := int64(0), int64(1e9+7)
	for i := 0; i < len(arr); i++ {
		dp[i] = 1
		for l, r := 0, i-1; l <= r; l++ {
			for l <= r && int64(arr[l])*int64(arr[r]) > int64(arr[i]) {
				r--
			}
			if l <= r && int64(arr[l])*int64(arr[r]) == int64(arr[i]) {
				if l == r {
					dp[i] = (dp[i] + dp[l]*dp[r]) % mod
				} else {
					dp[i] = (dp[i] + dp[l]*dp[r]*2) % mod
				}
			}
		}
		res = (res + dp[i]) % mod
	}
	return int(res)
}
