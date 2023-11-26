package main

func flipgame(fronts []int, backs []int) int {
	vis := map[int]bool{}
	for i, front := range fronts {
		if front == backs[i] {
			vis[front] = true
		}
	}

	ans := 0x3f3f3f3f
	for i, front := range fronts {
		if !vis[front] {
			ans = min(ans, front)
		}
		if !vis[backs[i]] {
			ans = min(ans, backs[i])
		}
	}
	if ans == 0x3f3f3f3f {
		return 0
	}
	return ans
}
