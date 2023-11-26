package main

import "sort"

/*
最长词链，只添加而不修改顺序

按照长度排序，
遍历 words[i]，以 words[i] 为结尾的长链，长度 cnt[words[i]] 为 1
去掉 words[i] 每个字符，找到前身 prev，对应最长链长度，如果 cnt + 1 大于 cnt[words[i]]，更新 cnt[words[i]]
*/
func longestStrChain(words []string) (res int) {
	sort.Slice(words, func(i, j int) bool { return len(words[i]) < len(words[j]) })
	cnt := map[string]int{}
	for _, word := range words {
		cnt[word] = 1
		for i := range word {
			prev := word[:i] + word[i+1:]
			if cnt[prev]+1 > cnt[word] {
				cnt[word] = cnt[prev] + 1
			}
		}
		res = max(res, cnt[word])
	}
	return
}
