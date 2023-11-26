package main

func waysToBuyPensPencils(total int, cost1 int, cost2 int) int64 {
	if cost1 < cost2 {
		cost1, cost2 = cost2, cost1
	}
	res, cnt := int64(0), 0
	for cnt*cost1 <= total {
		res += int64((total-cnt*cost1)/cost2 + 1)
		cnt++
	}
	return res
}
