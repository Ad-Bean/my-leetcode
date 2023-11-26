package main

import (
	"sort"
	"strings"
)

func topStudents(positive_feedback []string, negative_feedback []string, report []string, student_id []int, k int) (ans []int) {
	mp := map[string]int{}
	for _, p := range positive_feedback {
		mp[p] = 3
	}
	for _, n := range negative_feedback {
		mp[n] = -1
	}
	type pair struct{ score, id int }
	stus := make([]pair, len(student_id))
	for i, r := range report {
		score := 0
		for _, w := range strings.Split(r, " ") {
			score += mp[w]
		}
		stus[i] = pair{score, student_id[i]}
	}
	sort.Slice(stus, func(i, j int) bool {
		return stus[i].score > stus[j].score || stus[i].score == stus[j].score && stus[i].id < stus[j].id
	})
	for _, stu := range stus[:k] {
		ans = append(ans, stu.id)
	}
	return
}
