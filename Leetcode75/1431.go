package main

func kidsWithCandies(candies []int, extraCandies int) []bool {
	maxx := 0
	for _, num := range candies {
		if num > maxx {
			maxx = num
		}
	}
	ans := make([]bool, len(candies))
	for i, num := range candies {
		if num+extraCandies >= maxx {
			ans[i] = true
		} else {
			ans[i] = false
		}
	}
	return ans
}
