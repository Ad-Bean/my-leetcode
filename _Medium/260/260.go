package main

import (
	"fmt"
)

// O(n) O(1)
// x & -x == x & (~x + 1) ==> get the low bit of a ^ b
/*

1 2 1 3 2 5

  3 ^  5
011   101 = 110

第二位不同
1 & 2 = 0
2 & 2 = 2
1 & 2 = 0
3 & 2 = 2
2 & 2 = 2
5 & 2 = 0



*/
func singleNumber(nums []int) []int {
	ret := 0
	for _, num := range nums {
		ret ^= num
	}
	// ret == a ^ b
	low := ret & -ret
	num1 := 0
	for _, num := range nums {
		if num&low == 0 {
			num1 ^= num
		}
	}
	return []int{num1, ret ^ num1}
}

func main() {
	nums := []int{1, 2, 1, 3, 2, 5}
	for _, num := range nums {
		fmt.Printf("%v\n", num&2)
	}
}
