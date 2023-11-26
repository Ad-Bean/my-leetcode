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

func minimumDeletions(s string) int {
	lb, ra := 0, 0
	for _, c := range s {
		if c == 'a' {
			ra++
		}
	}
	res := ra
	for _, c := range s {
		if c == 'a' {
			ra--
		} else {
			lb++
		}
		res = min(res, lb+ra)
	}
	return res
}
