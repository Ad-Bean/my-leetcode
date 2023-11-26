package main

func majorityElement(nums []int) (ans []int) {
	cnt, n := map[int]int{}, len(nums)
	for _, num := range nums {
		cnt[num]++
	}
	for k, v := range cnt {
		if v >= n/3 {
			ans = append(ans, k)
		}
	}
	return
}
