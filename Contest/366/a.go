package main

func differenceOfSums(n int, m int) int {
	cnt1, cnt2 := 0, 0
	for i := 1; i <= n; i++ {
		if i%m != 0 {
			cnt1 += i
		} else {
			cnt2 += i
		}
	}
	return cnt1 - cnt2
}
