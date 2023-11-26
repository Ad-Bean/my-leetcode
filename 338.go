package main

func countBits(n int) (ans []int) {
	countBits := func(num int) (cnt int) {
		for num > 0 {
			cnt += 1
			num &= num - 1
		}
		return
	}
	for i := 0; i <= n; i++ {
		ans = append(ans, countBits(i))
	}
	return
}
