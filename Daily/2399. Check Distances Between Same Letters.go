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

func checkDistances(s string, distance []int) bool {
	idx := make([]int, 26)
	for i := 0; i < len(s); i++ {
		c := s[i] - 'a'
		if idx[c] != 0 && i-idx[c] != distance[c] {
			return false
		}
		idx[c] = i + 1
	}
	return true
}
