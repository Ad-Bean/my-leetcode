package main

func countOnes(num int) (cnt int) {
	for num > 0 {
		num &= num - 1
		cnt++
	}
	return
}
func sumIndicesWithKSetBits(nums []int, k int) (sum int) {
	for i, num := range nums {
		if countOnes(i) == k {
			sum += num
		}
	}
	return
}
