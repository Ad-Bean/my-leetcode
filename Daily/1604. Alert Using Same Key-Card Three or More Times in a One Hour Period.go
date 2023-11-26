package main

import "sort"

func alertNames(keyName []string, keyTime []string) (ans []string) {
	mp := map[string][]int{}
	for i, name := range keyName {
		t := keyTime[i]
		hour := int(t[0]-'0')*10 + int(t[1]-'0')
		mins := int(t[3]-'0')*10 + int(t[4]-'0')

		mp[name] = append(mp[name], hour*60+mins)
	}

	for name, times := range mp {
		sort.Ints(times)
		for i, t := range times[2:] {
			if t-times[i] <= 60 {
				ans = append(ans, name)
				break
			}
		}
	}
	sort.Strings(ans)
	return
}
