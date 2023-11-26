package main

func max(a, b int) int { if a < b { return b } return a }

func min(a, b int) int { if a < b { return a } return b }

func shortestPathBinaryMatrix(grid [][]int) int {
    if grid[0][0] == 1 {
		return -1
	}

	n := len(grid)
	dist := make([][]int, n)
	for i := 0; i < n; i++ {
		dist[i] = make([]int, n)
		for j := 0; j < n; j++ {
			dist[i][j] = 0x3f3f3f3f
		}
	}
	// queue stores next level [x, y]
	que := [][2]int{{0,0}}
	dist[0][0] = 1
	for len(que) > 0 {
		x, y := que[0][0], que[0][1]
		que = que[1:]
		if x == n- 1&& y == n- 1 {
			return dist[x][y]
		}
		for dx:=-1; dx<= 1; dx++ {
			for dy:=-1;dy <=1; dy ++{
				if x + dx < 0 || x + dx >=n || y+dy<0||y+dy>=n{
					continue	
				}
				if grid[x+dx][y+dy] == 1 || dist[x][y] + 1 >= dist[x+dx][y+dy] {
					continue
				}
				dist[x+dx][y+dy] = dist[x][y] + 1
				que = append(que, [2]int{x+dx, y+dy})
			}
		}
	}
	return -1
}