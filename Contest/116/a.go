package main

import "fmt"

func sumCounts(nums []int) (sum int) {
	const mod = 1e9 + 7
	n := len(nums)
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			mp := map[int]int{}
			fmt.Printf("%v\n", nums[i:j+1])
			for _, num := range nums[i : j+1] {
				mp[num]++
			}
			sum = (sum + len(mp)*len(mp)) % mod
		}
	}
	return sum
}

func main() {
	nums := []int{1, 2, 1}
	fmt.Printf("%d\n", sumCounts(nums))
}
