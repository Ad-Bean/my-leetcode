package main

func circularGameLosers(n int, k int) []int {
	mp := make([]bool, n)
	cur := 0
	for i := k; !mp[cur]; i += k {
		mp[cur] = true
		cur = (cur + i) % n
	}

	ans := make([]int, n)
	for i := 0; i < n; i++ {
		if !mp[i] {
			ans = append(ans, i+1)
		}
	}
	return ans
}
