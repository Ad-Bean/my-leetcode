package main

func queryString(s string, n int) bool {
	vis := map[int]struct{}{}
	for i, b := range s {
		x := int(b - '0')
		if x == 0 {
			continue
		}
		// 枚举 s 子串中在 [1, n] 的数
		for j := i + 1; x <= n; j++ {
			vis[x] = struct{}{}
			if j == len(s) {
				break
			}
			x = x<<1 | int(s[j]-'0')
		}
	}
	return len(vis) == n
}

// 1 <= s.length <= 1000
// 1 <= n <= 109

//   1101101

// 1. 暴力枚举 1 -> n 是否在 S 中
// strings.Contains(s, strconv.FormatUint(uint64(i), 2))
// O(min(m,n) * m log(min(m,n))),  m = len(s)

// 2. s 子串转成二进制，如果数字在 [1, n]，哈希存储最后 len(mp) == n
// 枚举子串 [i, j] -> 二进制
// 假设当前是 x, s[j + 1] => c
// x' = (x << 1) | ('c' - 0), 跳过 s[i] == 0
// O(m logn), m == len(s)
