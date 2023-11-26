package main

// 连续子数组
/*
    1. 从后往前 O(n^2)
	for i:=0; i<n; i++ {
		for j:=i; j>=0; j-- {
			sum += nums[j]
		}
	}

	2. 前缀和 + 哈希表优化
	pre[i] = sum(nums[:i])
	pre[i] = pre[i-1] + nums[i]
	sum(nums[j:i]) = pre[i] - pre[j - 1] == k
	所以 pre[j - 1] == pre[i] - k

*/
func subarraySum(nums []int, k int) int {
	cnt, pre := 0, 0
	mp := map[int]int{}
	mp[0] = 1
	for i := 0; i < len(nums); i++ {
		pre += nums[i]
		if _, ok := mp[pre-k]; ok {
			cnt += mp[pre-k]
		}
		mp[pre] += 1
	}
	return cnt
}
