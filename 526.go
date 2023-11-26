package main

func countArrangement(n int) (ans int) {
	match := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if i%j == 0 || j%i == 0 {
				match[i] = append(match[i], j)
			}
		}
	}

	vis := make([]bool, n+1)
	var dfs func(int)
	dfs = func(i int) {
		if i > n {
			ans++
			return
		}
		for _, x := range match[i] {
			if !vis[x] {
				vis[x] = true
				dfs(i + 1)
				vis[x] = false
			}
		}
	}
	dfs(1)
	return
}
