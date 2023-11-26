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

// DP
func longestArithSeqLength(nums []int) int {
	minv, maxv := nums[0], nums[0]
	for _, num := range nums[1:] {
		if num < minv {
			minv = num
		} else if num > maxv {
			maxv = num
		}
	}

	diff := maxv - minv
	ans := 1
	for d := -diff; d <= diff; d++ {
		f := make([]int, maxv+1)
		for i := range f {
			f[i] = -1
		}
		for _, num := range nums {
			prev := num - d
			if prev >= minv && prev <= maxv && f[prev] != -1 {
				f[num] = max(f[num], f[prev]+1)
				ans = max(f[num], ans)
			}
			f[num] = max(f[num], 1)
		}
	}
	return ans
}
