package main

import (
	"fmt"
	"sort"
)

func wiggleSort(nums []int) {
	n := len(nums)
	arr := append([]int{}, nums...)
	sort.Ints(arr)
	x := (n + 1) / 2
	for i, j, k := 0, x-1, n-1; i < n; i += 2 {
		nums[i] = arr[j]
		if i+1 < n {
			nums[i+1] = arr[k]
		}
		j--
		k--
	}
}

func main() {
	nums := []int{1, 5, 1, 1, 6, 4}
	arr := append([]int{}, nums...)
	sort.Ints(arr)
	fmt.Printf("%v\n%v\n", nums, arr)
}
