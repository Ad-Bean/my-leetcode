package main

import "sort"

func sumDistance(nums []int, s string, d int) (ans int) {
	for i := range nums {
		if s[i] == 'L' {
			nums[i] -= d
		} else {
			nums[i] += d
		}
	}
	const mod = int(1e9 + 7)
	sort.Ints(nums)
	sum := 0
	for i, num := range nums {
		ans += (i*num - sum)
		ans %= mod
		sum += num
	}
	return
}

// d 1e9, nums.length 1e5
// 不能模拟
// 相撞换方向 -> 继续走但是换编号 = 不用处理 -> 只是顺序不同
// [-2,0,2] RLL 3 真实模拟结果 [-3,-1,1] 直接走 [1,-3,-1]
// 对 nums 求 abs|i-j| 两两差，从后往前（升序） / 前往后（降序）
// 升序排序后，a[i] 与其前面的距离：
//   (a[i] - a[0]) + ... + (a[i] - a[i-1]) +...  + 0
// =  i*a[i] - (a[0] + .. + a[i-1])
// 后者递推，
