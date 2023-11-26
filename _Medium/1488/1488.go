package main

import "fmt"

/*
1 2 0 0 2 1
1 2 填满
没下雨: 2 3
2 要下雨，
	// 第 i 天下雨到 lake，先抽（找一个之前最近的日子）

*/
func avoidFlood(rains []int) []int {
	rainDay := map[int]int{} // 记录湖在哪一天下过雨
	noRainDay := []int{}
	ans := make([]int, len(rains))
	for i := range ans {
		ans[i] = -1
	}
	for i, lake := range rains {
		if lake == 0 {
			noRainDay = append(noRainDay, i) // 第 i 天没下雨，这一天可以抽
			ans[i] = 1
		} else {
			_, ok := rainDay[lake]
			fmt.Printf("%d rainDay[lake] %v\n", i, ok)
			if ok {
				if len(noRainDay) == 0 {
					return []int{}
				}
				// 找到下雨那天
				ans[noRainDay[0]] = lake
				noRainDay = noRainDay[1:]
			}
		}
		rainDay[lake] = i
	}
	return ans
}

func main() {
	rains := []int{0, 1, 1}
	fmt.Printf("%d\n", avoidFlood(rains))
}
