package main

import (
	"fmt"
)

/*
枚举 k

对于 30 要分成每个都是 10 or 11，则有 10，10，10
对于 33 要分成每个都是 10 or 11，则有 10，10，10 （3可以任意给）
对于 34 要分成每个都是 10 or 11，则有 10，10，10 （4，此时 34 % 10 > 34 / 10）

*/

func minGroupsForValidAssignment(nums []int) int {
	mp := map[int]int{}
	for _, num := range nums {
		mp[num]++
	}
	// 记数
	vmin := 0x3f3f3f3f
	// 找到最少的一个
	for _, v := range mp {
		if v <= vmin {
			vmin = v
		}
	}

	for k := vmin; k >= 0; k-- {
		ans := 0
		for _, v := range mp {
			q, r := v/k, v%k
			if q < r {
				break
			}
			ans += (v + k) / (k + 1)
		}
		if ans != 0 {
			return ans
		}
	}
}

func main() {
	// nums := []int{10, 10, 10, 3, 1, 1}
	nums := []int{3, 2, 2, 3, 3, 2}
	fmt.Printf("%v\n", minGroupsForValidAssignment(nums))
}

/*
3,2,2,3,3,2


map[2:1 3:1]
l := 6/3 = 2
mp[3] = 3 - 2 = 1
cnt = 1
mp[2] = 3- 2 = 1
cnt = 2


-----------------

10,10,10,3,1,1

m = (0+6)/2 = 3
6/3 + 1 = 3
g1 10 10
g2 10
g3 3
g4 2 2
m = (4+6)/2 = 5
6/5=1

m = (4+4)/2 = 4
6/4 = 1 + 1 = 2



*/
