package main

// u,v  u->v
func checkIfPrerequisite(n int, p [][]int, q [][]int) (res []bool) {
	g := make([][]int, n)
	ind := make([]int, n)
	for _, pre := range p {
		u, v := pre[0], pre[1]
		g[u] = append(g[u], v)
		ind[v]++
	}
	que := []int{}
	for i, d := range ind {
		if d == 0 {
			que = append(que, i)
		}
	}

	m := make([][]bool, n)
	for i := range m {
		m[i] = make([]bool, n)
	}
	for len(que) > 0 {
		cur := que[0]
		que = que[1:]
		for _, nx := range g[cur] {
			m[cur][nx] = true
			// cur -> nx 连通且邻接，寻找 i->cur->nx 从而更新 m[i][nx] 表示 i 是 nx 先决
			// 为什么是 i->nx 而不是 i->cur，因为 cur 先入队列，cur 当时为 0
			for i := range m[cur] {
				m[i][nx] = m[i][cur] || m[i][nx]
			}
			ind[nx]--
			if ind[nx] == 0 {
				que = append(que, nx)
			}
		}
	}
	for _, query := range q {
		res = append(res, m[query[0]][query[1]])
	}
	return
}

/*
m: n*n



*/
