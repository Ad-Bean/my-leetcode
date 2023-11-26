package main

import (
	"fmt"
	"sort"
)

/*
plantTime = [] 第 i 枚种子所需的完整天数
growTime =  [] 第 i 枚种子完全种下后生长的完整天数，但之后一天
返回 所有种子 都开花的最早一天

plantTime = [1,4,3]
growTime =  [2,3,1]
ans = 9

	p[0]  p[1]                  p[2]
	  1    2    3    4     5     6     7   8    9
	                p[0]                      p[1]
	                                          p[2]

按照 Plant time 贪心不行？按照 growtime 排序

首先我们可以发现，一定存在一种播种方法，是每次完整播种完一颗种子再接着播种下一颗的？

排序
对于 C++，sort(a.begin(), a.end(), [](int a, int b) {return a > b};) lambda 参数传的是元素
*/
func earliestFullBloom(plantTime []int, growTime []int) int {
	id := make([]int, len(plantTime))
	for i := range id {
		id[i] = i
	}
	sort.Slice(id, func(i, j int) bool { return growTime[id[i]] > growTime[id[j]] })
	// 按照 growTime 降序排序，但得到的是 idx
	pre, ans := 0, 0
	for _, idx := range id {
		ans = max(ans, pre+plantTime[idx]+growTime[idx])
		pre += plantTime[idx]
	}
	return ans
}

func main() {
	p := []int{3, 11, 29, 4, 4, 26, 26, 12, 13, 10, 30, 19, 27, 2, 10}
	g := []int{10, 13, 22, 17, 18, 15, 21, 11, 24, 14, 18, 23, 1, 30, 6}
	fmt.Printf("%v\n", earliestFullBloom(p, g))
}
