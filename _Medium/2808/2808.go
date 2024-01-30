package main

import "fmt"

func minimumSeconds(nums []int) int {
	pos := map[int][]int{}
	for i, num := range nums {
		pos[num] = append(pos[num], i)
	}
	n := len(nums)
	ans := n
	for _, v := range pos {
		v = append(v, v[0]+n)
		mx := 0
		for i := 1; i < len(v); i++ {
			mx = max(mx, (v[i]-v[i-1])/2)
		}
		ans = min(ans, mx)
	}
	return ans
}

func main() {
	nums := []int{2, 1, 3, 3, 2}
	fmt.Printf("%d\n", minimumSeconds(nums))
}
