package main

func groupAnagrams(strs []string) (ans [][]string) {
	mp := map[[26]int][]string{}
	for _, str := range strs {
		cnt := [26]int{}
		for _, c := range str {
			cnt[c-'a']++
		}
		mp[cnt] = append(mp[cnt], str)
	}
	for _, v := range mp {
		ans = append(ans, v)
	}
	return
}
