package main

import (
	"fmt"
)

// p[j] -> primes[j] * p[j] = next ugly num
// nums[j]
// dp[i] = min( dp[p[j]] * primes[j])
func nthSuperUglyNumber(n int, primes []int) int {
	dp := make([]int, n+1)
	m := len(primes)
	pointers, nums := make([]int, m), make([]int, m)
	for i := range nums {
		nums[i] = 1
	}

	for i := 1; i <= n; i++ {
		minn := 0x3f3f3f3f
		for j := range pointers {
			minn = min(minn, nums[j])
		}
		dp[i] = minn
		for j := range nums {
			if nums[j] == minn {
				pointers[j]++
				nums[j] = dp[pointers[j]] * primes[j]
			}
		}
	}
	return dp[n]
}

func main() {
	n := 12
	primes := []int{2, 7, 13, 19}
	ans := nthSuperUglyNumber(n, primes)
	fmt.Printf("%d\n", ans)
}
