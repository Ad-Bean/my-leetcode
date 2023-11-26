package main

func mergeTriplets(triplets [][]int, target []int) bool {
	maxx := [3]bool{}
	for _, triplet := range triplets {
		if triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2] {
			maxx[0] = maxx[0] || (triplet[0] == target[0])
			maxx[1] = maxx[1] || (triplet[1] == target[1])
			maxx[2] = maxx[2] || (triplet[2] == target[2])
		}
	}
	return maxx[0] && maxx[1] && maxx[2]
}
