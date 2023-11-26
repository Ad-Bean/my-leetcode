package main

import "fmt"

func countPairs(n int, edges [][]int) int64 {
	fa := make([]int, n)
	sz := make([]int, n)
	cnt := int64(n)
	for i := range fa {
		fa[i] = i
		sz[i] = 1
	}

	var find func(x int) int
	find = func(x int) int {
		if fa[x] != x {
			fa[x] = find(fa[x])
			return fa[x]
		}
		return fa[x]
	}

	union := func(x int, y int) {
		fx, fy := find(x), find(y)
		if fx == fy {
			return
		}
		fmt.Printf("union(%d, %d)\n", fx, fy)
		if sz[fx] > sz[fy] {
			fa[fy] = fx
			sz[fx] += sz[fy]
		} else {
			fa[fx] = fy
			sz[fy] += sz[fx]
		}
		cnt--
	}

	for _, e := range edges {
		u, v := e[0], e[1]
		union(u, v)
	}
	if cnt == 1 {
		return 0
	}

	mp := map[int]bool{}
	tmp, sum := int64(0), int64(0)
	for _, f := range fa {
		ff := find(f)
		if !mp[ff] {
			sum += tmp * int64(sz[ff])
			tmp += int64(sz[ff])
		}
		mp[ff] = true
	}
	return sum
}

func countPairs(n int, edges [][]int) (sum int64) {
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	vis := make([]bool, n)
	var dfs func(int) int
	dfs = func(i int) int {
		vis[i] = true
		sz := 1
		for _, nx := range g[i] {
			if !vis[nx] {
				sz += dfs(nx)
			}
		}
		return sz
	}

	tot := 0
	for i, b := range vis {
		if !b {
			sz := dfs(i)
			sum += int64(sz) * int64(tot)
			tot += sz
		}
	}
	return
}

func main() {
	n := 5
	edges := [][]int{{0, 3}, {4, 1}, {0, 1}}
	fmt.Printf("%v\n", countPairs(n, edges))
}

/*
0 - 3
   |
   1 - 4

2

*/

/*
a0 a1 a2 a3

a0 * a1 + a0 * a2 + a0 * a3 + a1 * a2 + a1 * a3 + a2 * a3
= a0 * a1 + (a0 + a1) * a2 + (a0 + a1 + a2) * a3
*/
