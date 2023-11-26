package main

import "fmt"

func queensAttacktheKing(queens [][]int, king []int) (ans [][]int) {
	dirs := [][]int{
		{0, 1}, {0, -1},
		{1, 0}, {1, -1}, {1, 1},
		{-1, 0}, {-1, -1}, {-1, 1},
	}
	queenMap := map[int]bool{}
	for _, queen := range queens {
		p := queen[0]*10 + queen[1]
		queenMap[p] = true
	}
	for _, dir := range dirs {
		nx, ny := king[0]+dir[0], king[1]+dir[1]
		for nx >= 0 && nx <= 7 && ny >= 0 && ny <= 7 {
			if queenMap[nx*10+ny] {
				ans = append(ans, []int{nx, ny})
				break
			}
			nx, ny = nx+dir[0], ny+dir[1]
		}
	}
	return
}

func main() {
	queens := [][]int{
		{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4},
	}
	king := []int{0, 0}
	fmt.Printf("%v\n", queensAttacktheKing(queens, king))
}
