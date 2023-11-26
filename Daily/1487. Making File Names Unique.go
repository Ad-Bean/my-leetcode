package main

import "strconv"

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func getFolderNames(names []string) []string {
	ans := make([]string, len(names))
	mp := map[string]int{}

	for i, name := range names {
		cnt := mp[name]
		if cnt == 0 {
			mp[name] = 1
			ans[i] = name
			continue
		}

		for mp[name+"("+strconv.Itoa(cnt)+")"] > 0 {
			cnt++
		}
		curName := name + "(" + strconv.Itoa(cnt) + ")"
		ans[i] = curName
		mp[name] = cnt + 1
		mp[curName] = 1
	}
	return ans
}
