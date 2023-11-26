package main

import (
	"fmt"
)

func maxNumberOfAlloys(n int, k int, budget int, composition [][]int, stock []int, cost []int) int {
	flag := true
	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}
	canProduce := func(m int) bool {
		for i := 0; i < k; i++ {
			tot, need := 0, make([]int, n)
			for j := 0; j < n; j++ {
				need[j] += max(0, composition[i][j]*m-stock[j])
				tot += need[j] * cost[j]
				if tot > budget {
					flag = false
					break
				}
			}
			if tot <= budget {
				return true
			}
			fmt.Printf("机器 %v 制作 %d 个，成本 %v:\n%v\n", i, m, tot, need)
		}
		return flag
	}

	left, right := 0, 0x3f3f3f3f
	maxMetal := 0
	for left <= right {
		mid := left + (right-left)/2
		if canProduce(mid) {
			maxMetal = mid
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return maxMetal
}

func main() {
	n := 4
	k := 9
	budget := 55
	composition := [][]int{{8, 3, 4, 2}, {3, 9, 5, 5}, {1, 7, 9, 8}, {7, 6, 5, 1}, {4, 6, 9, 4}, {6, 8, 7, 1}, {5, 10, 3, 4}, {10, 1, 2, 4}, {10, 3, 7, 2}}
	stock := []int{9, 1, 10, 0}
	cost := []int{3, 4, 9, 9}

	result := maxNumberOfAlloys(n, k, budget, composition, stock, cost)
	fmt.Println(result) // 输出 2
}
