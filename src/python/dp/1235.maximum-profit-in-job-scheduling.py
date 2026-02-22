from typing import List

class Solution:
    def latest_non_overlapping(self, ends: List[int], hi: int, start: int) -> int:
        """Return the count of jobs (in ends[0..hi)) with end <= start."""
        lo = 0
        while lo < hi:
            mid = (lo + hi) // 2
            if ends[mid] <= start:
                lo = mid + 1
            else:
                hi = mid
        return lo

    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(endTime, startTime, profit))
        ends = [j[0] for j in jobs]

        dp = [0] * (len(jobs) + 1)
        for i, (end, start, p) in enumerate(jobs):
            lo = self.latest_non_overlapping(ends, i, start)
            dp[i + 1] = max(dp[i], dp[lo] + p)
        return dp[len(jobs)]
