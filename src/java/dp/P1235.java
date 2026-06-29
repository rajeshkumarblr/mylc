package dp;
import common.*;


import java.util.*;

/*
 * @lc app=leetcode id=1235 lang=java
 *
 * [1235] Maximum Profit in Job Scheduling
 *
 * https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
 *
 * We have n jobs, where every job is scheduled to be done from startTime[i]
 * to endTime[i], obtaining a profit of profit[i].
 *
 * You're given the startTime, endTime and profit arrays, return the maximum
 * profit you can take such that there are no two jobs in the subset with
 * overlapping time range.
 *
 * If you choose a job that ends at time X you will be able to start another
 * job that starts at time X.
 *
 * Example 1:
 * Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 * Output: 120
 * Explanation: The subset chosen is the first and fourth job.
 * Time range [1-3] + [3-6] , we get profit of 50 + 70 = 120.
 *
 * Example 2:
 * Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
 * [20,20,100,70,60]
 * Output: 150
 * Explanation: The subset chosen is the first, fourth and fifth job.
 * Profit obtained 20 + 70 + 60 = 150.
 *
 * Example 3:
 * Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
 * Output: 6
 *
 * Constraints:
 * - 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
 * - 1 <= startTime[i] < endTime[i] <= 10^9
 * - 1 <= profit[i] <= 10^4
 */

public class P1235 {
    public static class Solution {
        // Returns count of jobs (in sorted jobs[0..hi)) with end <= start.
        private int latestNonOverlapping(int[][] jobs, int hi, int start) {
            int lo = 0;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (jobs[mid][0] <= start)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            return lo;
        }

        public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
            int n = startTime.length;
            int[][] jobs = new int[n][3];
            for (int i = 0; i < n; i++)
                jobs[i] = new int[] { endTime[i], startTime[i], profit[i] };
            Arrays.sort(jobs, (a, b) -> a[0] - b[0]);

            int[] dp = new int[n + 1];
            for (int i = 0; i < n; i++) {
                int lo = latestNonOverlapping(jobs, i, jobs[i][1]);
                dp[i + 1] = Math.max(dp[i], dp[lo] + jobs[i][2]);
            }
            return dp[n];
        }
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        return new Solution().jobScheduling(startTime, endTime, profit);
    }
}
