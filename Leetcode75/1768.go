package main

func mergeAlternately(word1, word2 string) string {
	n, m := len(word1), len(word2)
	// ans := make([]byte, 0, n+m)
	ans := []byte{}
	for i := 0; i < n || i < m; i++ {
		if i < n {
			ans = append(ans, word1[i])
		}
		if i < m {
			ans = append(ans, word2[i])
		}
	}
	return string(ans)
}
