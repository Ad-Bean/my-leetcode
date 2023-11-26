package main

import (
	"sort"
)

func dist(x, y []int) int {
	return abs(x[0]-y[0]) + abs(x[1]-y[1])
}

func minCostConnectPoints(points [][]int) (ans int) {
	n := len(points)

	type edge struct{ v, w, dis int }
	edges := []edge{}
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			edges = append(edges, edge{i, j, dist(points[i], points[j])})
		}
	}
	sort.Slice(edges, func(i, j int) bool { return edges[i].dis < edges[j].dis })

	fa, sz := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		fa[i] = i
		sz[i] = 1
	}
	var find func(int) int
	find = func(x int) int {
		if fa[x] != x {
			fa[x] = find(fa[x])
		}
		return fa[x]
	}

	var union = func(x, y int) bool {
		fx, fy := find(x), find(y)
		if fx == fy {
			return false
		}
		if sz[fx] < sz[fy] {
			fx, fy = fy, fx
		}
		sz[fx] += sz[fy]
		fa[fy] = fx
		return true
	}

	nodes := n - 1
	for _, e := range edges {
		if union(e.v, e.w) {
			ans += e.dis
			nodes--
			if nodes == 0 {
				break
			}
		}
	}
	return
}
