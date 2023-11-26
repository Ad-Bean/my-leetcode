package main

import "fmt"

func minimumMoves(grid [][]int) int {
	type Point struct{ x, y int }
	need, res := []Point{}, []Point{}
	for i, row := range grid {
		for j, c := range row {
			if c > 1 {
				for k := 1; k < c; k++ {
					res = append(res, Point{i, j})
				}
			}
			if c == 0 {
				need = append(need, Point{i, j})
			}
		}
	}

	sz := len(res)
	p := make([]int, sz)
	for i := range p {
		p[i] = i
	}
	// fmt.Printf("%v\n", p)

	ans := 0x3f3f3f3f
	var dfs func(int)
	dfs = func(st int) {
		if st == sz {
			return
		}
		for i := st; i < sz; i++ {
			p[st], p[i] = p[i], p[st]
			dfs(st + 1)
			cur := 0
			for j := 0; j < sz; j++ {
				x1, y1 := res[p[j]].x, res[p[j]].y
				// fmt.Printf("%v\n", res[p[j]])

				x2, y2 := need[j].x, need[j].y
				// fmt.Printf("need: %v\n", need[p[j]])
				cur += abs(x1-x2) + abs(y1-y2)
			}
			ans = min(ans, cur)
			p[st], p[i] = p[i], p[st]
		}
	}
	dfs(0)
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	g := [][]int{
		{1, 1, 0}, {1, 1, 1}, {1, 2, 1},
	}
	ans := minimumMoves(g)
	fmt.Printf("%v\n", ans)
}
