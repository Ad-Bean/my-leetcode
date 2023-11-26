package main

import "fmt"

func main() {
	edges := [][]string{
		{"96b0", "96e0"},
		{"96b0", "9710"},
		{"96e0", "9740"},
		{"9710", "9740"},
	}

	vis := map[string]bool{}
	txs := []string{}
	for _, edge := range edges {
		u, v := edge[0], edge[1]
		if !vis[u] {
			vis[u] = true
			txs = append(txs, u)
		}
		if !vis[v] {
			vis[v] = true
			txs = append(txs, v)
		}
	}
	mp := map[string]int{}
	fmt.Printf("txs: %v\n", txs)
	for i, tx := range txs {
		mp[tx] = i
	}
	fmt.Printf("mp: %v\n\n", mp)
	fmt.Printf("edges: %v\n", edges)
	fa, sz := make([]int, len(txs)), make([]int, len(txs))
	for i := range fa {
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

	for _, edge := range edges {
		u, v := edge[0], edge[1]
		// true if a cycle exists
		if !union(mp[u], mp[v]) {
			fmt.Printf("cycled: %v %v\n", u, v)
			break
		}
	}
	fmt.Printf("no cycle")
	return
}
