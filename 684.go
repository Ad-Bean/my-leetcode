package main

func findRedundantConnection(edges [][]int) []int {
	n := len(edges)
	fa := make([]int, n+1)
	for i := range fa {
		fa[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if fa[x] != x {
			fa[x] = find(fa[x])
		}
		return fa[x]
	}

	var union func(int, int) bool
	union = func(x, y int) bool {
		u, v := find(x), find(y)
		if u == v {
			return false
		}
		fa[u] = v
		return true
	}

	for _, e := range edges {
		if !union(e[0], e[1]) {
			return e
		}
	}
	return nil
}
