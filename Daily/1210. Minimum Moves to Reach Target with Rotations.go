package main

func minimumMoves(grid [][]int) int {
	n := len(grid)
	dist := make([][][2]int, n)
	for i := range dist {
		dist[i] = make([][2]int, n)
		for j := range dist[i] {
			dist[i][j] = [2]int{-1, -1}
		}
	}
	dist[0][0][0] = 0
	// tail
	que := [][3]int{{0, 0, 0}}

	for len(que) > 0 {
		arr := que[0]
		que = que[1:]
		x, y, status := arr[0], arr[1], arr[2]

		if status == 0 {
			// horizontal snake
			// move right
			if y+2 < n && dist[x][y+1][0] == -1 && grid[x][y+2] == 0 {
				dist[x][y+1][0] = dist[x][y][0] + 1
				que = append(que, [3]int{x, y + 1, 0})
			}
			// move down
			if x+1 < n && dist[x+1][y][0] == -1 && grid[x+1][y] == 0 && grid[x+1][y+1] == 0 {
				dist[x+1][y][0] = dist[x][y][0] + 1
				que = append(que, [3]int{x + 1, y, 0})
			}
			// rotate clockwise
			if x+1 < n && dist[x][y][1] == -1 && grid[x+1][y] == 0 && grid[x+1][y+1] == 0 {
				dist[x][y][1] = dist[x][y][0] + 1
				que = append(que, [3]int{x, y, 1})
			}
		} else {
			// vertical snake
			// move right
			if y+1 < n && dist[x][y+1][1] == -1 && grid[x][y+1] == 0 && grid[x+1][y+1] == 0 {
				dist[x][y+1][1] = dist[x][y][1] + 1
				que = append(que, [3]int{x, y + 1, 1})
			}
			// move down
			if x+2 < n && dist[x+1][y][1] == -1 && grid[x+2][y] == 0 {
				dist[x+1][y][1] = dist[x][y][1] + 1
				que = append(que, [3]int{x + 1, y, 1})
			}
			// rotate counterclockwise
			if y+1 < n && dist[x][y][0] == -1 && grid[x][y+1] == 0 && grid[x+1][y+1] == 0 {
				dist[x][y][0] = dist[x][y][1] + 1
				que = append(que, [3]int{x, y, 0})
			}
		}
	}
	return dist[n-1][n-2][0]
}
