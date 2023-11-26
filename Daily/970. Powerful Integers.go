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
func powerfulIntegers(x int, y int, bound int) []int {
	res := make(map[int]bool)
	var res map[int]bool
	val1 := 1
	for i := 0; i < 21; i++ {
		val2 := 1
		for j := 0; j < 21; j++ {
			val := val1 + val2
			if val <= bound {
				res[val] = true
			} else {
				break
			}
			val2 *= y
		}
		if val1 > bound {
			break
		}
		val1 *= x
	}
	var result []int
	for k := range res {
		result = append(result, k)
	}
	return result
}
