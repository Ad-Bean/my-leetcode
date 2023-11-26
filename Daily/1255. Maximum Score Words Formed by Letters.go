package main

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

// len(words) <= 14
// state compression
// 标准子集回溯 https://www.bilibili.com/video/BV1mG4y1A7Gu/
func maxScoreWords(words []string, letters []byte, score []int) (ans int) {
	left := [26]int{}
	for _, c := range letters {
		left[c-'a']++
	}

	var dfs func(int, int)
	dfs = func(i, total int) {
		if i < 0 {
			ans = max(ans, total)
			return
		}

		dfs(i-1, total)

		for j, c := range words[i] {
			c -= 'a'
			// not enough
			if left[c] == 0 {
				// undo, add back the 0:j letters
				for _, c := range words[i][:j] {
					left[c-'a']++
				}
				return
			}
			left[c]--
			total += score[c]
		}

		dfs(i-1, total)

		// recover
		for _, c := range words[i] {
			left[c-'a']++
		}
	}

	dfs(len(words)-1, 0)
	return
}
