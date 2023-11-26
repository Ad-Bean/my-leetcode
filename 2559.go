package main

func vowelStrings(words []string, queries [][]int) []int {
	mp := map[byte]bool{
		'a': true,
		'e': true,
		'i': true,
		'o': true,
		'u': true,
	}

	n := len(words)
	prev := make([]int, n+1)
	for i := 0; i < n; i++ {
		head, tail := words[i][0], words[i][len(words[i])-1]
		_, headVowel := mp[head]
		_, tailVowel := mp[tail]

		prev[i+1] = prev[i]
		if headVowel && tailVowel {
			prev[i+1] += 1
		}
	}
	ans := make([]int, len(queries))
	for i, query := range queries {
		ans[i] = prev[query[1]+1] - prev[query[0]]
	}
	return ans
}
