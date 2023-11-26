package main

import "strconv"

func punishmentNumber(n int) int {
	preSum := make([]int, n+1)
	for i := 1; i <= n; i++ {
		str := strconv.Itoa(i * i)
		sz := len(str)

		// dfs 枚举 s[0:j] 子串
		var dfs func(int, int) bool
		dfs = func(p, sum int) bool {
			if p == sz {
				return sum == i
			}
			x := 0
			for j := p; j < sz; j++ {
				x = x*10 + int(str[j]-'0')
				if dfs(j+1, sum+x) {
					return true
				}
			}
			return false
		}
		preSum[i] = preSum[i-1]

		if dfs(0, 0) {
			preSum[i] += i * i
		}
	}
	return preSum[n]
}

/*
n = 10
1: 1 * 1 = 1, 1 = 1
9: 9 * 9 = 81, 8 + 1 = 9
10: 10 * 10 = 100, 10 + 0 = 10
--------------------------------- 1 + 9 * 9 + 10 * 10 = 100+81+1 = 182
n = 37
1
9
10
36: 36 * 36 = 1296, 1+29+6=36

*/
