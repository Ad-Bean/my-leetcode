package main

import (
	"fmt"

	"github.com/emirpasic/gods/trees/redblacktree"
)

/*
寻找 nums[i] < nums[k] < nums[j] 也即 132

由于 n <= 2e5，如果枚举 i j 则会达到 n^2 超出时间复杂度

枚举一个下标：
1. 枚举 3
维护数组左侧最小值找到 1，而 2 是次小，用有序集合（平衡树）维护右侧 a[j+1:] 中所有值
*/
func find132pattern(nums []int) bool {
	n := len(nums)
	if n < 3 {
		return false
	}

	lmin, rset := nums[0], redblacktree.NewWithIntComparator()
	for _, v := range nums[2:] {
		if cnt, ok := rset.Get(v); ok {
			rset.Put(v, cnt.(int)+1)
		} else {
			rset.Put(v, 1)
		}
	}

	for j := 1; j < n-1; j++ {
		if lmin < nums[j] {
			k, ok := rset.Ceiling(lmin + 1) // <=
			if ok && k.Key.(int) < nums[j] {
				return true
			}
		} else {
			lmin = nums[j]
		}
		cnt, _ := rset.Get(nums[j+1])
		if cnt.(int) == 1 {
			rset.Remove(nums[j+1])
		} else {
			rset.Put(nums[j+1], cnt.(int)-1)
		}
	}
	return false
}

func main() {
	nums := []int{1, 4, 0, -1, -2, -3, -1, -2}
	fmt.Printf("%v\n", find132pattern(nums))
}
