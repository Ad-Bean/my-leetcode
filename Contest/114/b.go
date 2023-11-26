package main

import "fmt"

func minOperations(nums []int) (cnt int) {
	mp := map[int]int{}
	for _, num := range nums {
		mp[num]++
	}
	for _, v := range mp {
		if v == 1 {
			return -1
		}
		if v%3 == 0 {
			cnt += (v / 3)
		} else if v%3 == 2 {
			cnt += (v-2)/3 + 1
		} else if v%3 == 1 {
			cnt += (v-4)/3 + 2
		}
	}
	return
}

func main() {
	nums := []int{19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19}
	fmt.Printf("%v\n", minOperations(nums))
}

/*
11
9 + 2

10
6 + 4
*/
