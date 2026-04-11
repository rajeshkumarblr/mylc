package dp;
import common.*;


import java.util.*;

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
