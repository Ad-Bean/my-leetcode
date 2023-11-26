package main

func longestValidParentheses(s string) (ans int) {
	stk := []int{}
	stk = append(stk, -1)
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			stk = append(stk, i)
		} else if s[i] == ')' {
			stk = stk[:len(stk)-1]
			if len(stk) == 0 {
				stk = append(stk, i)
			} else {
				ans = max(ans, i-stk[len(stk)-1])
			}
		}
	}
	return
}
