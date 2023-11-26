package main

func tilingRectangle(n int, m int) int {
	rect := make([][]bool, n)
	for i := 0; i < n; i++ {
		rect[i] = make([]bool, m)
	}

	isAvailable := func(x, y, k int) bool {
		for i := 0; i < k; i++ {
			for j := 0; j < k; j++ {
				if rect[x+i][y+j] {
					return false
				}
			}
		}
		return true
	}

	fillUp := func(x, y, k int, val bool) {
		for i := 0; i < k; i++ {
			for j := 0; j < k; j++ {
				rect[x+i][y+j] = val
			}
		}
	}

	ans := max(n, m)
	var dfs func(int, int, int)
	dfs = func(x, y, cnt int) {
		if cnt >= ans {
			return
		}

		if x >= n {
			ans = cnt
			return
		}

		if y >= m {
			dfs(x+1, 0, cnt)
			return
		}

		if rect[x][y] {
			dfs(x, y+1, cnt)
			return
		}

		for k := min(n-x, m-y); k >= 1 && isAvailable(x, y, k); k-- {
			fillUp(x, y, k, true)
			dfs(x, y+k, cnt+1)
			fillUp(x, y, k, false)
		}
	}

	dfs(0, 0, 0)
	return ans
}
