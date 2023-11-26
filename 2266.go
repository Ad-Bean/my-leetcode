package main

const mod, mx int = 1e9 + 7, 1e5

var f = [mx + 1]int{1, 1, 2, 4}
var g = f

func init() {
	for i := 4; i <= mx; i++ {
		f[i] = (f[i-1] + f[i-2] + f[i-3]) % mod
		g[i] = (g[i-1] + g[i-2] + g[i-3] + g[i-4]) % mod
	}
}

func countTexts(s string) int {
	ans, cnt := 1, 0
	for i, c := range s {
		if i == len(s)-1 || s[i+1] != byte(c) {
			if c != '7' && c != '9' {
				ans = ans * f[cnt] % mod
			} else {
				ans = ans * g[cnt] % mod
			}
			cnt = 0
		}
	}
	return ans
}

// 222
// f[0] = 1
// f[1] = 1
// f[2] = 2 (aa, b)
// f[3] = 4
// f[4] = 7 = f[1] + f[2] + f[3] (aaaa, aba, aab, ac, baa, bb, ca)
// f[5] = 13
// ....
