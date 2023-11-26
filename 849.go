package main

func maxDistToClosest(seats []int) (ans int) {
	l := 0
	for l < len(seats) && seats[l] == 0 {
		l++
	}
	ans = l
	for l < len(seats) {
		r := l + 1
		for r < len(seats) && seats[r] == 0 {
			r++
		}
		if r == len(seats) {
			if ans < r-l+1 {
				ans = r - l + 1
			}
		} else {
			if ans < (r-l)/2 {
				ans = (r - l) / 2
			}
		}
		l = r
	}
	return
}