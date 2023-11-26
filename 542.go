package main

func updateMatrix(mat [][]int) [][]int {
	dirs := [][]int{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}
	m, n := len(mat), len(mat[0])
	dist, seen := make([][]int, m), make([][]int, m)
	for i := range dist {
		dist[i] = make([]int, n)
		seen[i] = make([]int, n)
	}
	que := [][]int{}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if mat[i][j] == 0 {
				que = append(que, []int{i, j})
				seen[i][j] = 1
			}
		}
	}
	for len(que) > 0 {
		p := que[0]
		que = que[1:]
		for _, dir := range dirs {
			ni, nj := p[0]+dir[0], p[1]+dir[1]
			if ni >= 0 && ni < m && nj >= 0 && nj < n && seen[ni][nj] == 0 {
				dist[ni][nj] = dist[p[0]][p[1]] + 1
				que = append(que, []int{ni, nj})
				seen[ni][nj] = 1
			}
		}
	}
	return dist
}
