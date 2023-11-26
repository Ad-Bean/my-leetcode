package main

import (
	"fmt"
	"sort"
)

func unequalTriplets(nums []int) int {
	n := len(nums)
	cnt := 0
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			for k := j + 1; k < n; k++ {
				if nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k] {
					cnt++
				}
			}
		}
	}
	return cnt
}
func unequalTriplets2(nums []int) int {
	n := len(nums)
	cnt := 0
	sort.Ints(nums)
	for i, j := 0, 0; i < n; i = j {
		for j < n && nums[i] == nums[j] {
			j++
		}
		// 左边 i 个，中间 j- i 个，右边 n - j 个
		cnt += i * (j - i) * (n - j)
	}
	return cnt
}
func unequalTriplets3(nums []int) int {
	mp := map[int]int{}
	for _, x := range nums {
		mp[x]++
	}
	cnt, n, t := 0, len(nums), 0
	for _, v := range mp {
		// fmt.Printf("%d %d \n", k, v)
		// fmt.Printf("t=%d, v=%d, n-t-v=%d \n", t, v, n-t-v)
		// t 是前面数字的个数
		//  n - t -v 是右边的数字个数
		// v 是当前的数字个数
		cnt, t = cnt+t*v*(n-t-v), t+v
	}

	return cnt
}

func main() {
	nums := []int{4, 1, 2, 4, 5}
	cnt := unequalTriplets3(nums)
	fmt.Printf("%d\n", cnt)
}
