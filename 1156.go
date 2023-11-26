package main

func maxRepOpt1(text string) int {
	cnt := make(map[rune]int)
	for _, c := range text {
		cnt[c]++
	}

	res, i, n := 0, 0, len(text)
	for i < n {
		// find first [i, j) that matches 'xxxxx'
		j := i
		for j < n && text[i] == text[j] {
			j++
		}
		curCnt := j - i

		// still has empty pos
		if curCnt < cnt[rune(text[i])] && (j < n || i > 0) {
			res = max(res, curCnt+1)
		}

		// find another [j+1, k) that matches 'xxxxx'
		k := j + 1
		for k < n && text[k] == text[i] {
			k++
		}
		res = max(res, min(k-i, cnt[rune(text[i])]))
		i = j
	}
	return res
}
