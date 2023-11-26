package main

func canCompleteCircuit(gas []int, cost []int) int {
	n := len(gas)
	for i := 0; i < n; {
		gases, costs, cnt := 0, 0, 0
		for cnt < n {
			j := (i + cnt) % n
			gases += gas[j]
			costs += cost[j]
			if costs > gases {
				break
			}
			cnt++
		}
		if cnt == n {
			return i
		} else {
			i += cnt + 1
		}
	}
	return -1
}
