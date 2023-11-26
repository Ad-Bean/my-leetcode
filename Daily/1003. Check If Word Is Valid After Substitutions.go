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
func isValid(s string) bool {
	stk := []byte{}
	for i := range s {
		stk = append(stk, s[i])
		if len(stk) >= 3 && string(stk[len(stk)-3:]) == "abc" {
			stk = stk[:len(stk)-3]
		}
	}
	return len(stk) == 0
}
