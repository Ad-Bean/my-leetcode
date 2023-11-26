package main

import "fmt"

func maxSum(nums []int, k int) (ans int) {
	const mod = 1e9 + 7
	cnt := make([]int, 32)
	for _, num := range nums {
		for i := range cnt {
			fmt.Printf("%d: %d \n", i, num&(1<<i))
			if num&(1<<i) > 0 {
				cnt[i]++
			}
		}
	}
	for i := 0; i < k; i++ {
		cur := 0
		for j, v := range cnt {
			if v > 0 {
				cur += (1 << j)
				cnt[j]--
			}
		}
		ans += cur * cur
		ans = ans % mod
	}
	return ans
}

func main() {
	nums := []int{2, 6, 5, 8}
	k := 2
	fmt.Printf("%v\n", maxSum(nums, k))
}
