package main

func countOrders(n int) int {
	const m = (1e9 + 7)
	if n == 1 {
		return 1
	}

	ans := (1)
	for i := 2; i <= n; i++ {
		ans = ans * ((i)*2 - 1) % m * (i) % m
	}
	return ans
}
