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

// multiple both 2 and n
// if gcd (2, n) == 2, return n, else 2 * n / gcd

// 最小公倍数 = n * m / gcd

func smallestEvenMultiple(n int) int {
	if n%2 == 0 {
		return n
	} else {
		return 2 * n
	}
}
