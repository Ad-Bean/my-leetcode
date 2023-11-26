package main

func peakIndexInMountainArray(arr []int) (ans int) {
	n := len(arr)
	l, r := 1, n-2
	for l <= r {
		m := l + (r-l)/2
		if arr[m] > arr[m+1] {
			r = m - 1
			ans = m
		} else {
			l = m + 1
		}
	}
	return ans
}
