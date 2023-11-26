package main

import "sort"

func minOperations(nums []int) (ans int) {
	n := len(nums)
	sort.Ints(nums)
	k := 0
	for _, v := range nums[1:] {
		if nums[k] != v {
			k++
			nums[k] = v
		}
	}
	nums = nums[:k+1]
	for r, numr := range nums {
		l := sort.SearchInts(nums[:r], numr-n+1)
		ans = max(ans, r-l+1)
	}
	return n - ans
}

/*

返回使得 nums 连续的最少操作次数

最多就是 len - 1
最少是 0
len(nums) 1e5

可以想到二分，对 nums 排序后

对 nums[l:r]，如果保留这一段，则需要替换区间外的元素，并且补充 [nums[l], nums[r]] 中缺失的元素
所以还要对 nums 去重？

需要填充的元素个数为 (nums[r] - nums[l] + 1) - (r - l + 1)
区间外存在 n - (r - l + 1) 个元素
所以 (nums[r] - nums[l] + 1) - (r - l + 1) <= n - (r - l + 1)
nums[r] <= n + nums[l] - 1
nums[l] >= nums[r] + 1 - n
所以可以枚举 nums[r]，二分得到最小满足该式的 l，此时保留 [l,r] 用 n 减去最多可以保留的元素个数，就是答案
*/
