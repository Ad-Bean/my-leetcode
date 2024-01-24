package main

func canFinish(numCourses int, prerequisites [][]int) bool {
	e := make([][]int, numCourses)
	ind := make([]int, numCourses)
	for _, g := range prerequisites {
		e[g[1]] = append(e[g[1]], g[0])
		ind[g[0]]++
	}
	que := []int{}
	for i := 0; i < numCourses; i++ {
		if ind[i] == 0 {
			que = append(que, i)
		}
	}

	vis := []int{}
	for len(que) > 0 {
		u := que[0]
		que = que[1:]
		vis = append(vis, u)
		for _, nx := range e[u] {
			ind[nx]--
			if ind[nx] == 0 {
				que = append(que, nx)
			}
		}
	}
	return len(vis) == numCourses
}
