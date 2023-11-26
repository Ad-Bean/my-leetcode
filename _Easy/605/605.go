package main

/*
[1,0,0,0,1] n = 1

只能种在两个 0 之间


数两个一之间的零个数
arr  [1,0,0,0,1], [1,0,0,0,0,1]
1. 如果两边间隔 1：放 (i - pre - 2) / 2 表示减掉两个 1 附近的 0
2. 如果左边没有 1：放 i / 2
3. 如果一直没有 1：放 (len + 1) / 2 贪心多放一个
4. 如果只有一个 1：还要处理右边，(len - pre - 1) / 2
*/

func canPlaceFlowers(flowerbed []int, n int) bool {
	pre, cnt := -1, 0
	for i, flower := range flowerbed {
		if flower == 1 {
			if pre != -1 {
				cnt += (i - pre - 2) / 2
			} else {
				cnt += i / 2
			}
			pre = i
		}
	}
	if pre == -1 {
		cnt += (len(flowerbed) + 1) / 2
	} else {
		cnt += (len(flowerbed) - pre - 1) / 2
	}
	return cnt >= n
}
