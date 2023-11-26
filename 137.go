package main

// -2^31 <= nums[i] <= 2^31 - 1
// 对每一位统计
func singleNumber(nums []int) int {
	ans := int32(0)
	for i := 0; i < 32; i++ {
		t := 0
		for _, num := range nums {
			t += (num >> i) & 1
		}
		if (t % 3) > 0 {
			ans |= 1 << i
		}
	}
	return int(ans)
}
