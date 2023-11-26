package main

import (
	"fmt"
	"sort"
)

func filterRestaurants(restaurants [][]int, veganFriendly int, maxPrice int, maxDistance int) []int {
	sort.Slice(restaurants, func(i, j int) bool {
		if restaurants[i][1] > restaurants[j][1] {
			return true
		} else if restaurants[i][1] == restaurants[j][1] {
			return restaurants[i][0] > restaurants[j][0]
		}
		return false
	})
	ans := []int{}
	for _, res := range restaurants {
		if res[3] <= maxPrice && res[4] <= maxDistance {
			if veganFriendly == 1 && res[2] == 1 {
				ans = append(ans, res[0])
			} else if veganFriendly == 0 {
				ans = append(ans, res[0])
			}
		}
	}
	return ans
}
func main() {
	restaurants := [][]int{{1, 4, 1, 40, 10}, {2, 8, 0, 50, 5}, {3, 8, 1, 30, 4}, {4, 10, 0, 10, 3}, {5, 1, 1, 15, 1}}
	veganFriendly := 1
	maxPrice := 50
	maxDistance := 10
	fmt.Printf("%v\n", filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance))
}
