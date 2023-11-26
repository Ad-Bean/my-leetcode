package main

func lengthOfLongestSubstring(s string) (ans int) {
	mp := map[rune]int{}
	l := 0
	for r, ch := range s {
		mp[ch]++
		for mp[ch] > 1 {
			mp[rune(s[l])]--
			l++
		}
		if r-l+1 > ans {
			ans = r - l + 1
		}
	}
	return
}
