package main

import "fmt"

// func max(a, b int) int {
// 	if a < b {
// 		return b
// 	}
// 	return a
// }

// func min(a, b int) int {
// 	if a < b {
// 		return a
// 	}
// 	return b
// }

// func equalPairs(grid [][]int) int {
// 	res := 0
// 	n := len(grid)
// 	for i := 0; i < n; i++ {
// 		for j := 0; j < n; j++ {
// 			flag := true
// 			for k := 0; k < n; k++ {
// 				if grid[i][k] != grid[k][j] {
// 					flag = false
// 					break
// 				}
// 			}
// 			if flag == true {
// 				res += 1
// 			}
// 		}
// 	}
// 	return res
// }

// func equalPairs2(grid [][]int) int {
// 	n := len(grid)
// 	cnt := make(map[string]int)
// 	for _, row := range grid {
// 		cnt[fmt.Sprint(row)]++
// 	}

// 	res := 0
// 	for j := 0; j < n; j++ {
// 		var arr []int
// 		for i := 0; i < n; i++ {
// 			arr = append(arr, grid[i][j])
// 		}
// 		if val, ok := cnt[fmt.Sprint(arr)]; ok {
// 			res += val
// 		}
// 	}

// 	return res
// }
func equalPairs(grid [][]int) (ans int) {
	mp := map[string]int{}
	for _, row := range grid {
		mp[fmt.Sprint(row)]++
	}

	n := len(grid)
	for i := 0; i < n; i++ {
		col := []int{}
		for j := 0; j < n; j++ {
			col = append(col, grid[j][i])
		}
		if k, ok := mp[fmt.Sprint(col)]; ok {
			ans += k
		}
	}
	return
}

func main() {
	grid := [][]int{
		{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2},
	}
	fmt.Printf("%d\n", equalPairs(grid))
}
