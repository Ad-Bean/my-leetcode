package main

import (
	"fmt"
	"sort"
)

func numberOfGoodPaths(vals []int, edges [][]int) int {
	n := len(vals)
	g := make([][]int, n)
	for _, e := range edges {
		x, y := e[0], e[1]
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}

	// 并查集模板
	fa := make([]int, n)
	// sz[x] 表示节点值等于 vals[x] 的节点个数
	sz := make([]int, n)
	id := make([]int, n)
	for i := range fa {
		fa[i] = i
		id[i] = i
		sz[i] = 1
	}

	var find func(int) int
	find = func(x int) int {
		if fa[x] != x {
			fa[x] = find(fa[x])
		}
		return fa[x]
	}

	ans := n // 单节点个数
	// 按照 vals 从小到大对 id 排序
	sort.Slice(id, func(i, j int) bool { return vals[id[i]] < vals[id[j]] })

	for _, x := range id {
		vx := vals[x]
		fx := find(x)
		for _, y := range g[x] {
			y = find(y)
			if y == fx || vals[y] > vx {
				continue
			}
			if vals[y] == vx {
				ans += sz[fx] * sz[y]
				sz[fx] += sz[y]
			}
			fa[y] = fx
		}
	}
	fmt.Printf("%v\n", fa)
	fmt.Printf("%v\n", sz)
	return ans
}

func main() {
	vals := []int{1, 3, 2, 1, 3}
	edges := [][]int{{0, 1}, {0, 2}, {2, 3}, {2, 4}}
	ans := numberOfGoodPaths(vals, edges)
	fmt.Printf("%d\n", ans)
}
