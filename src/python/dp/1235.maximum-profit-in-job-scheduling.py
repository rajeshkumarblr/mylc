"""
@lc app=leetcode id=1235 lang=python3

[1235] Maximum Profit in Job Scheduling

https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

We have n jobs, where every job is scheduled to be done from startTime[i]
to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum
profit you can take such that there are no two jobs in the subset with
overlapping time range.

If you choose a job that ends at time X you will be able to start another
job that starts at time X.

Example 1:
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3] + [3-6] , we get profit of 50 + 70 = 120.

Example 2:
Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
[20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 20 + 70 + 60 = 150.

Example 3:
Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6

Constraints:
- 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
- 1 <= startTime[i] < endTime[i] <= 10^9
- 1 <= profit[i] <= 10^4
"""

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
