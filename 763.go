package main

func partitionLabels(s string) (ans []int) {
	pos := [26]int{}
	for i, c := range s {
		pos[c-'a'] = i
	}

	start, end := 0, 0
	for i, c := range s {
		if pos[c-'a'] > end {
			end = pos[c-'a']
		}
		if i == end {
			ans = append(ans, end-start+1)
			start = end + 1
		}
	}
	return
}
