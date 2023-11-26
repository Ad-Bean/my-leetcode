package main

func findKOr(nums []int, k int) (cnt int) {
	mp := map[int]int{}
	for _, num := range nums {
		for i := 0; i <= 32; i++ {
			if (num>>i)&1 == 1 {
				mp[i]++
			}
		}
	}
	for i, v := range mp {
		if v >= k {
			cnt += (1 << i)
		}
	}
	return
}
