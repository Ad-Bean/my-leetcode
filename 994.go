package main

import (
	"fmt"
)

type Point struct {
	x, y int
}

func orangesRotting(grid [][]int) int {
	dis := make([][]int, 10)
	for i := range dis {
		dis[i] = make([]int, 10)
		for j := 0; j < 10; j++ {
			dis[i][j] = -1
		}
	}

	que := []*Point{}
	fresh, ans := 0, 0
	m, n := len(grid), len(grid[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 2 {
				que = append(que, &Point{i, j})
				dis[i][j] = 0
			}
			if grid[i][j] == 1 {
				fresh += 1
			}
		}
	}

	dir := [][]int{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}
	for len(que) > 0 {
		p := que[0]
		que = que[1:]
		fmt.Printf("%v\n", p)
		for _, d := range dir {
			nx, ny := p.x+d[0], p.y+d[1]
			if nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 {
				dis[nx][ny] = dis[p.x][p.y] + 1
				que = append(que, &Point{nx, ny})
				ans = dis[nx][ny]
				grid[nx][ny] = 2
				fresh -= 1
				if fresh == 0 {
					break
				}
			}
		}
	}
	if fresh > 0 {
		return -1
	}
	return ans
}

func main() {
	grid := [][]int{
		{2, 1, 1},
		{1, 1, 0},
		{0, 1, 1},
	}

	ans := orangesRotting(grid)
	fmt.Printf("%v\n", ans)
}
