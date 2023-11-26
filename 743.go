package main

func networkDelayTime(times [][]int, n int, k int) (ans int) {
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = 0x3f3f3f3f
		}
	}
	for _, t := range times {
		g[t[0]-1][t[1]-1] = t[2]
	}

	dis := make([]int, n)
	for i := range dis {
		dis[i] = 0x3f3f3f3f
	}
	dis[k-1] = 0
	vis := make([]bool, n)
	for i := 0; i < n; i++ {
		x := -1
		for j := range vis {
			if !vis[j] && (x == -1 || dis[j] < dis[x]) {
				x = j
			}
		}
		vis[x] = true
		for u, w := range g[x] {
			dis[u] = min(dis[u], dis[x]+w)
		}
	}
	for _, d := range dis {
		if d == 0x3f3f3f3f {
			return -1
		}
		ans = max(ans, d)
	}
	return
}
