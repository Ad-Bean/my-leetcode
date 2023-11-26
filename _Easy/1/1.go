package main

func twoSum(nums []int, target int) []int {
	mp := make(map[int]int)
	for i, num := range nums {
		if idx, ok := mp[target-num]; ok {
			return []int{i, idx}
		} else {
			mp[num] = i
		}
	}
	return []int{}
}
