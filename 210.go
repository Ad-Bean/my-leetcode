package main

import "fmt"

// pre [a,b] b->a
func findOrder(n int, p [][]int) (ans []int) {
	g, ind := make([][]int, n), make([]int, n)
	for _, pp := range p {
		a, b := pp[0], pp[1]
		ind[a]++
		g[b] = append(g[b], a)
	}
	fmt.Printf("%v\n", g)
	fmt.Printf("%v\n", ind)
	que := []int{}
	for i, v := range ind {
		if v == 0 {
			que = append(que, i)
		}
	}

	for len(que) > 0 {
		cur := que[0]
		que = que[1:]
		ans = append(ans, cur)
		for _, nx := range g[cur] {
			ind[nx]--
			if ind[nx] == 0 {
				que = append(que, nx)
			}
		}
	}
	if len(ans) != n {
		return []int{}
	}
	return
}

func main() {
	n := 3
	p := [][]int{{1, 0}, {1, 2}, {0, 1}}
	ans := findOrder(n, p)
	fmt.Printf("%v\n", ans)
}

// 0->1
// 2->1
//
