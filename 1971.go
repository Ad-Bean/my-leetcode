package main

import (
	"fmt"
)

func validPath(n int, edges [][]int, source int, destination int) bool {
	g := make([][]int, n)
	for _, edge := range edges {
		g[edge[0]] = append(g[edge[0]], edge[1])
		g[edge[1]] = append(g[edge[1]], edge[0])
	}
	vis := make([]bool, n)
	vis[source] = true

	que := []int{source}
	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		if v == destination {
			break
		}
		for _, next := range g[v] {
			if vis[next] == false {
				que = append(que, next)
				vis[next] = true
			}
		}
	}
	return vis[destination]
}

func main() {
	n := 3
	edges := [][]int{{0, 1}, {1, 2}, {2, 0}}
	source := 0
	destination := 2

	ans := validPath(n, edges, source, destination)
	fmt.Printf("%v\n", ans)
}
