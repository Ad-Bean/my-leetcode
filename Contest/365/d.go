package main

import (
	"fmt"
)

func countVisitedNodes(edges []int) (ans []int) {
	var dfsCirce func(int, map[int]int) []int
	var dfs func(cur int, vis map[int]int, cnt int) int
	dfsCirce = func(cur int, vis map[int]int) []int {
		if vis[cur] != 0 {
			return []int{-1, cur}
		}
		vis[cur] = 1
		nxt := dfsCirce(edges[cur], vis)
		if nxt[1] == -1 {
			ans[cur] = nxt[0] + 1
			return []int{nxt[0] + 1, nxt[1]}
		}
		return nxt
	}
	dfs = func(cur int, vis map[int]int, cnt int) int {
		if vis[cur] != 0 {
			return cnt
		}
		vis[cur] = 1
		nxt := dfs(edges[cur], vis, cnt+1)
		ans[cur] = nxt
		return nxt
	}

	for i := range edges {
		if ans[i] != 0 {
			continue
		} else {
			nxt := dfsCirce(i, map[int]int{})
			if nxt[1] != -1 {
				dfs(nxt[1], map[int]int{}, 0)
				dfsCirce(nxt[1], map[int]int{})
			}
		}
	}
	return
}

func main() {
	edges1 := []int{1, 2, 0, 0}
	edges2 := []int{1, 2, 3, 4, 0}

	result1 := countVisitedNodes(edges1)
	result2 := countVisitedNodes(edges2)

	fmt.Println(result1) // 输出 [3 3 3 4]
	fmt.Println(result2) // 输出 [5 5 5 5 5]
}
