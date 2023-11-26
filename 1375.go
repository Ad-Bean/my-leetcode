package main

// [1, i] 全是 1
// 所以 flips[:i] 包含 1 到 i
// 所以判断在 i 步，有 1 到 i
func numTimesAllBlue(flips []int) int {
	ans, maxNum := 0, 0
	for i, num := range flips {
		maxNum = max(maxNum, num)
		if maxNum == i+1 {
			ans++
		}
	}
	return ans
}
