package main

import "sort"

type jobEntry struct{ end, start, p int }

// latestNonOverlapping returns the number of jobs (in sorted jobs[0..hi))
// whose end time is <= start, i.e. the index of the first job with end > start.
func latestNonOverlapping(jobs []jobEntry, hi, start int) int {
	lo := 0
	for lo < hi {
		mid := (lo + hi) / 2
		if jobs[mid].end <= start {
			lo = mid + 1
		} else {
			hi = mid
		}
	}
	return lo
}

func jobScheduling(startTime []int, endTime []int, profit []int) int {
	n := len(startTime)
	jobs := make([]jobEntry, n)
	for i := 0; i < n; i++ {
		jobs[i] = jobEntry{endTime[i], startTime[i], profit[i]}
	}
	sort.Slice(jobs, func(i, j int) bool { return jobs[i].end < jobs[j].end })

	dp := make([]int, n+1)
	for i := 0; i < n; i++ {
		lo := latestNonOverlapping(jobs, i, jobs[i].start)
		if take := dp[lo] + jobs[i].p; take > dp[i] {
			dp[i+1] = take
		} else {
			dp[i+1] = dp[i]
		}
	}
	return dp[n]
}
