package main

func distMoney(money int, children int) int {
	if money < children {
		return -1
	}
	money -= children             // 每人一个
	cnt := min(money/7, children) // 给 cnt 个人 +7
	money -= cnt * 7
	children -= cnt
	if children == 1 && money == 3 || children == 0 && money > 0 {
		cnt -= 1 // 最后一人为 4 或者 全部为 8 但是还有钱
	}
	return cnt
}

/*
20 3

17
1 1 1

// cnt: 17 / 7 = 2
3
8 8 1

//


*/
