package main

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	vars := map[string]int{}
	for _, eq := range equations {
		u, v := eq[0], eq[1]
		if _, ok := vars[u]; !ok {
			vars[u] = len(vars)
		}
		if _, ok := vars[v]; !ok {
			vars[v] = len(vars)
		}
	}

	type edge struct {
		t int
		w float64
	}

	g := make([][]edge, len(vars))
	for i, eq := range equations {
		u, v := eq[0], eq[1]
		a, b := vars[u], vars[v]
		g[a] = append(g[a], edge{b, values[i]})
		g[b] = append(g[b], edge{a, 1 / values[i]})
	}

	bfs := func(start, end int) float64 {
		r := make([]float64, len(g))
		r[start] = 1
		que := []int{start}
		for len(que) > 0 {
			v := que[0]
			que = que[1:]
			if v == end {
				return r[end]
			}

			for _, e := range g[v] {
				if u := e.t; r[u] == 0 {
					r[u] = r[v] * e.w
					que = append(que, u)
				}
			}
		}
		return -1
	}

	ans := make([]float64, len(queries))
	for i, q := range queries {
		start, oks := vars[q[0]]
		end, oke := vars[q[1]]
		if !oks || !oke {
			ans[i] = -1
		} else {
			ans[i] = bfs(start, end)
		}
	}
	return ans
}
