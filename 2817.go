package main

// 红黑树 + 双指针
// 调库 + 枚举
import (
	"math"

	rbt "github.com/emirpasic/gods/trees/redblacktree"
)

func minAbsoluteDifference(nums []int, x int) int {
	min := func(a, b int) int {
		if b < a {
			return b
		}
		return a
	}
	t := rbt.NewWithIntComparator()
	ans := math.MaxInt
	// 哨兵，保证一定找到
	t.Put(math.MaxInt, nil)
	t.Put(math.MinInt/2, nil)
	for i, num := range nums[x:] {
		t.Put(nums[i], nil) // 放前面的入有序集合
		c, _ := t.Ceiling(num)
		f, _ := t.Floor(num)
		ans = min(ans, min(c.Key.(int)-num, num-f.Key.(int)))
	}
	return ans
}
