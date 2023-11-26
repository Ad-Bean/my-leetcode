package main

func decodeAtIndex(s string, k int) string {
	size := 0
	for _, c := range s {
		if 'a' <= c && c <= 'z' {
			size++
		} else if '2' <= c && c <= '9' {
			size *= int(c - '0')
		}
	}

	for i := len(s) - 1; i >= 0; i-- {
		k %= size
		if k == 0 && ('a' <= s[i] && s[i] <= 'z') {
			return string(s[i])
		}
		if '2' <= s[i] && s[i] <= '9' {
			size /= int(s[i] - '0')
		} else {
			size -= 1
		}
	}
	return ""
}

/*
leet2code3
leetleet
leetleetcodeleetleetcodeleetleetcode len=12*3=36
         |
k = 10, s[i] = o

暴力：爆内存

逆向：
先找出解码字符串长度，比如 leet2code3 len=36
再逆向求最小周期 i in [n-1, 0]
如果此时 k %= size == 0，那么就是最后一位
如果是数字，除掉 size /= num
如果是字符，减掉 size -= 1



*/
