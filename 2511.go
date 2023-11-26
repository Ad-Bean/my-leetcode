package main

func captureForts(forts []int) (ans int) {
	prev := -1
	for i, fort := range forts {
		if fort == -1 || fort == 1 {
			if prev >= 0 && forts[prev] != fort {
				ans = max(ans, i-prev-1)
			}
			prev = i
		}
	}
	return ans
}
