package main

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
func gardenNoAdj(n int, paths [][]int) []int {
	adj := make([][]int, n)
	for i := 0; i < n; i++ {
		adj[i] = []int{}
	}

	for _, path := range paths {
		adj[path[0]-1] = append(adj[path[0]-1], path[1]-1)
		adj[path[1]-1] = append(adj[path[1]-1], path[0]-1)
	}

	ans := make([]int, n)
	for i := 0; i < n; i++ {
		colored := make([]bool, 5)
		for _, v := range adj[i] {
			// ans[v] means it already is colored (initially colored with 0)
			colored[ans[v]] = true
		}
		for j := 1; j <= 4; j++ {
			if !colored[j] {
				ans[i] = j
				break
			}
		}
	}
	return ans
}
