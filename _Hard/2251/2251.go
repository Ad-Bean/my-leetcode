package main

import (
	"fmt"
	"sort"
)

/*
flowers = [[1,6],[3,7],[9,12],[4,13]] 表示第 i 朵花的花期从 st 到 ed
people = [2,3,7,11] 表示第 i 个人看花的时间

返回 answer = [1,2,2,2] 返回当时的花数目


1. 差分数组 + 离线查询
对差分数组求前缀和得到当前元素值
对[0,people[j]] 求前缀和，得到时间点为 people[j] 开花数目

由于 start <= end <= 1e9 无法用数组求前缀和
需要将时间点离散化，用有序集合记录端点的变化量？
st 开花量 + 1，end + 1 开花量 - 1
用有序集合 cnt 统计每次开花区间端点的变化量

例子：[[1,6],[3,7],[9,12],[4,13]]
arr:
	1: 1
	3: 1
	4: 1
	7:-1
	8:-1
	9: 1
	13:-1
	14:-1

对于 [2,3,7,11]，当前花数 cur 0，下标 j 0
每次只要 people[i] 大于当前 arr[j] 就累加，就是当时的花数，下标要一直前进
[1, 2, 2+1-1=2, 2-1+1=2]
*/
/* func fullBloomFlowers(flowers [][]int, people []int) []int {
	cnt := map[int]int{}
	for _, flower := range flowers {
		cnt[flower[0]] += 1
		cnt[flower[1]+1] -= 1
	}
	arr, idx := [][]int{}, [][]int{}
	for k, v := range cnt {
		arr = append(arr, []int{k, v})
	}
	for i, p := range people {
		idx = append(idx, []int{p, i})
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][0] < arr[j][0] })
	sort.Slice(idx, func(i, j int) bool { return idx[i][0] < idx[j][0] })
	j, cur := 0, 0
	ans := make([]int, len(people))
	for _, p := range idx {
		for j < len(arr) && arr[j][0] <= p[0] {
			cur += arr[j][1]
			j += 1
		}
		ans[p[1]] = cur
	}
	return ans
} */

/*
二分查找

找到 start <= people[i] 的花朵数目减去 end < people[i]，就是开花数目

单独统计 start 和 end 用二分查找

所有 start，end 排序之后，对 people[i] 二分，但因为是找数目，所以先找 p+1 的位置，再找 p 的位置
golang 中 sort.SearchInts 就是二分
[[1,6],[3,7],[9,12],[4,13]]
start [1, 3,  4,  9]
end   [6, 7, 12, 13]

people [2,3,7,11]
*/
func fullBloomFlowers(flowers [][]int, people []int) []int {
	n, m := len(flowers), len(people)
	st, ed := make([]int, n), make([]int, n)
	for i, flower := range flowers {
		st[i], ed[i] = flower[0], flower[1]
	}
	sort.Ints(st)
	sort.Ints(ed)
	ans := make([]int, m)
	for i, p := range people {
		x := sort.SearchInts(st, p+1)
		y := sort.SearchInts(ed, p)
		ans[i] = x - y
	}
	return ans
}

func main() {
	flowers := [][]int{
		{1, 6}, {3, 7}, {9, 12}, {4, 13},
	}
	people := []int{2, 3, 7, 11}
	fmt.Printf("%v\n", fullBloomFlowers(flowers, people))
}
