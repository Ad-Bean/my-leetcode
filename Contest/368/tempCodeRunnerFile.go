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