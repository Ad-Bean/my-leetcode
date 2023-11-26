package main

func jump(nums []int) int {
	n := len(nums)
	end, maxPos, steps := 0, 0, 0
	for i := 0; i < n-1; i++ {
		maxPos = max(maxPos, i+nums[i])
		if i == end {
			end = maxPos
			steps++
		}
	}
	return steps
}

/*
2,3,1,1,4

贪心，每次拿最远的位置，如果说这个位置是之前过来的 i == end， step++
maxPos = max(0, 0 + 2) = 2
i == 0 == end, end = 2, step ++

maxPos = max(2, 1 + 3) = 4
i == 1, end = 2

maxPos = max(4, 2+1) = 4
i == 2 == end, end = 4, step++

maxPos = max(4, 3+1) = 4
i == 3, end == 4

i == 4 == n - 1 到了

*/
