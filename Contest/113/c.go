package main

func countPairs(coordinates [][]int, k int) int {
	count := 0
	mp := make(map[[2]int]int)

	for _, point := range coordinates {
		for key, v := range mp {
			res := key[0] ^ point[0] + key[1] ^ point[1]
			if res == k {
				count += v
			}
		}

		mp[[2]int{point[0], point[1]}]++
	}

	return count
}
