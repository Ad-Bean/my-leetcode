package main

import "sort"

func findItinerary(tickets [][]string) (res []string) {
	m := map[string][]string{}
	for _, t := range tickets {
		u, v := t[0], t[1]
		m[u] = append(m[u], v)
	}
	for k := range m {
		sort.Strings(m[k])
	}

	var dfs func(string)
	dfs = func(cur string) {
		for {
			if v, ok := m[cur]; !ok || len(v) == 0 {
				break
			}
			nxt := m[cur][0]
			m[cur] = m[cur][1:]
			dfs(nxt)
		}
		res = append(res, cur)
	}

	dfs("JFK")
	for i := 0; i < len(res)/2; i++ {
		res[i], res[len(res)-i-1] = res[len(res)-i-1], res[i]
	}

	return
}
