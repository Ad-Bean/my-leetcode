package main

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxArea(height []int) int {
	n := len(height)
	ans := 0
	i, j := 0, n-1
	for i <= j {
		area := min(height[i], height[j]) * (j - i)
		if height[i] < height[j] {
			i++
		} else {
			j--
		}
		ans = max(area, ans)
	}
	return ans
}
