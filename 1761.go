package main

func minTrioDegree(n int, edges [][]int) int {
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
	}
	d := make([]int, n)
	for _, e := range edges {
		u, v := e[0]-1, e[1]-1
		g[u][v], g[v][u] = 1, 1
		d[u], d[v] = d[u]+1, d[v]+1
	}
	ans := 0x3f3f3f3f
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if g[i][j] != 1 {
				continue
			}
			for k := j + 1; k < n; k++ {
				if g[i][k] == 1 && g[j][k] == 1 {
					ans = min(ans, d[i]+d[j]+d[k]-2-2-2)
				}
			}
		}
	}
	if ans == 0x3f3f3f3f {
		return -1
	}
	return ans
}
