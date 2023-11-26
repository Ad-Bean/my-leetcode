package main

func averageValue(nums []int) int {
	ans, cnt := 0, 0
	for _, num := range nums {
		// if num%3 == 0 && num%2 == 0 {
		if num%6 == 0 {
			ans += num
			cnt += 1
		}
	}
	if cnt == 0 {
		return 0
	}
	return ans / cnt
}
