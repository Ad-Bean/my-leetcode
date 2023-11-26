package main

func numJewelsInStones(jewels string, stones string) (cnt int) {
	mp := map[rune]bool{}
	for _, jewel := range jewels {
		mp[jewel] = true
	}

	for _, stone := range stones {
		if _, ok := mp[stone]; ok {
			cnt++
		}
	}
	return
}
