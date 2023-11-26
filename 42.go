package main

func trap(height []int) (ans int) {
	l, r := 0, len(height)-1
	lmax, rmax := 0, 0
	for l < r {
		lmax = max(lmax, height[l])
		rmax = max(rmax, height[r])
		if height[l] < height[r] {
			ans += lmax - height[l]
			l++
		} else {
			ans += rmax - height[r]
			r++
		}
	}
	return ans
}
