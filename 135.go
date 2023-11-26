package main

func candy(ratings []int) (ans int) {
	n := len(ratings)
	l := make([]int, n)
	for i, rate := range ratings {
		if i > 0 && rate > ratings[i-1] {
			l[i] = l[i-1] + 1
		} else {
			l[i] = 1
		}
	}
	r := 0
	for i := n - 1; i >= 0; i-- {
		if i < n-1 && ratings[i] > ratings[i+1] {
			r++
		} else {
			r = 1
		}
		ans += max(l[i], r)
	}
	return
}
