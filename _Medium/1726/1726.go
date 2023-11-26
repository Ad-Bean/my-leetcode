package main

/*
2 3 4 6
两两乘积：6 8 12 12 18 24

对于 12 来说有 2 * 2 * 2 = 8 搭配

1 2 4 5 10
两两乘积： 2 4 5 10 8 10 20 20 40 50

对 10 有 8
对 20 有 8

1 2 4 5 10 20
乘积：2 4 5 10 20 8 10 20 40 20 40 80 50 100 200
三个 20： C(3,2) * 2 * 2 * 2 = 24
两个 10： C(2,2) * 8
两个 40： C(2,2) * 8

四个？： C(v-1,2) * 8

*/
func tupleSameProduct(nums []int) (ans int) {
	n := len(nums)
	mp := map[int]int{}
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			mp[nums[i]*nums[j]]++
		}
	}
	for _, v := range mp {
		ans += (v - 1) * v * 4
	}
	return
}
