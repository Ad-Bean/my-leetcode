package main

func reconstructMatrix(upper int, lower int, colsum []int) [][]int {
	n := len(colsum)
	ans := make([][]int, 2)
	for i := 0; i < 2; i++ {
		ans[i] = make([]int, n)
	}
	for i, sum := range colsum {
		if sum == 2 {
			ans[0][i], ans[1][i] = 1, 1
			upper, lower = upper-1, lower-1
		}
		if sum == 1 {
			if upper > lower {
				upper -= 1
				ans[0][i] = 1
			} else {
				lower -= 1
				ans[1][i] = 1
			}
		}
		if upper < 0 || lower < 0 {
			break
		}
	}
	if upper != 0 || lower != 0 {
		return [][]int{}
	}
	return ans
}
