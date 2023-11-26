package main

func subtractProductAndSum(n int) int {
	sum, mul := 0, 1
	for n > 0 {
		d := n % 10
		sum += d
		mul *= d
		n /= 10
	}
	return mul - sum
}
