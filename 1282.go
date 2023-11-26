package main

func groupThePeople(groupSizes []int) (ans [][]int) {
	mp := map[int][]int{}
	for i, sz := range groupSizes {
		mp[sz] = append(mp[sz], i)
	}
	for k, v := range mp {
		for i := 0; i < len(v); i += k {
			ans = append(ans, v[i:i+k])
		}
	}
	return
}
