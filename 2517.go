package main

import (
	"fmt"
	"sort"
)

// 如果题目中有「最大化最小值」或者「最小化最大值」，一般都是二分答案，请记住这个套路。
func maximumTastiness(price []int, k int) int {
	sort.Ints(price)
	return sort.Search((price[len(price)-1]-price[0])/(k-1), func(d int) bool {
		d++ // 二分最小的 f(d+1) < k，从而知道最大的 f(d) >= k
		fmt.Printf("%d\n", d)
		cnt, pre := 1, price[0]
		for _, p := range price[1:] {
			if p >= pre+d {
				cnt++
				pre = p
			}
		}
		return cnt < k
	})
}

func main() {
	price := []int{13, 5, 1, 8, 21, 2}
	k := 3
	res := maximumTastiness(price, k)
	fmt.Printf("%d\n", res)
}
