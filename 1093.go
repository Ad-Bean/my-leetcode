package main

func sampleStats(count []int) []float64 {
	n := len(count)
	total := 0
	for i := 0; i < n; i++ {
		total += count[i]
	}
	mean, median, minimum, maximum, mode := 0.0, 0.0, 256, 0, 0
	l, r := (total+1)/2, (total+2)/2
	cnt, maxfreq, sum := 0, 0, 0
	for i := 0; i < n; i++ {
		sum += int(count[i]) * int(i)
		if count[i] > maxfreq {
			maxfreq = count[i]
			mode = i
		}
		if count[i] > 0 {
			if minimum == 256 {
				minimum = i
			}
			maximum = i
		}
		if cnt < r && cnt+count[i] >= r {
			median += float64(i)
		}
		if cnt < l && cnt+count[i] >= l {
			median += float64(i)
		}
		cnt += count[i]
	}
	mean = float64(sum) / float64(total)
	median = median / 2
	return []float64{float64(minimum), float64(maximum), mean, median, float64(mode)}
}
