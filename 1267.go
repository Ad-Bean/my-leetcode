package main

func countServers(grid [][]int) (ans int) {
	r, c := make(map[int]int), make(map[int]int)
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == 1 {
				r[i] = r[i] + 1
				c[j] = c[j] + 1
			}
		}
	}
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == 1 && (r[i] > 1 || c[j] > 1) {
				ans++
			}
		}
	}
	return
}
