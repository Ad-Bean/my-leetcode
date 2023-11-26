package main

import "fmt"

func checkXMatrix(grid [][]int) bool {
	for i, row := range grid {
		for j, col := range row {
			if i == j || i+j+1 == len(row) {
				if col == 0 {
					return false
				}
			} else if col != 0 {
				return false
			}
		}
	}

	return true
}

func main() {
	fmt.Println("Hello World!")
}
