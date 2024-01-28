package main

/*
dfs
栈模拟

*/
func canMeasureWater(jug1 int, jug2 int, target int) bool {
	min := func(a, b int) int {
		if a < b {
			return a
		}
		return b
	}
	type pair struct{ x, y int }
	stk := []pair{pair{0, 0}}
	vis := map[pair]bool{}
	for len(stk) > 0 {
		cur := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		if cur.x == target || cur.y == target || cur.x+cur.y == target {
			return true
		}
		if vis[cur] {
			continue
		}

		vis[cur] = true
		stk = append(stk, pair{jug1, cur.y})                                                    // x 灌满
		stk = append(stk, pair{cur.x, jug2})                                                    // y 灌满
		stk = append(stk, pair{0, cur.y})                                                       // x 清空
		stk = append(stk, pair{cur.x, 0})                                                       // y 清空
		stk = append(stk, pair{cur.x - min(jug2-cur.y, cur.x), cur.y + min(jug2-cur.y, cur.x)}) // x 倒入 y
		stk = append(stk, pair{cur.x + min(jug1-cur.x, cur.y), cur.y - min(jug1-cur.x, cur.y)}) // y 倒入 x
	}
	return false
}
