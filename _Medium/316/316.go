package main

/*
贪心+单调栈
字符串 s 去掉一个字符 ch 使得字符串字典序最小？找到满足 s[i] > s[i+1] 的最小下标，并去除 s[i]

从前向后处理 s[i] > s[i+1]
用单调栈维护剩余字符串，栈底到栈顶的字符递增
如果栈顶字符大于当前 s[i]，则去除栈顶，继续比较新栈顶与 s[i] 直到栈空或者 s[i] >= 栈顶

如果 s[i] 已在栈中，则不能加入（保证唯一）
弹出栈顶时，如果字符后没有这个位置，则不能弹出？？

*/
func removeDuplicateLetters(s string) string {
	mp := [26]int{}
	for _, c := range s {
		mp[c-'a']++
	}
	stk := []rune{}
	instk := [26]bool{}
	for _, c := range s {
		if instk[c-'a'] {
			mp[c-'a']--
			continue
		}
		for len(stk) > 0 && stk[len(stk)-1] > c {
			pop := stk[len(stk)-1] - 'a'
			if mp[pop] == 0 {
				break
			}
			stk = stk[:len(stk)-1]
			instk[pop] = false
		}
		stk = append(stk, c)
		instk[c-'a'] = true
		mp[c-'a']--
	}
	return string(stk)
}
