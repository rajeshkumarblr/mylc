package misc;

import java.util.*;

/*
 * @lc app=leetcode id=56 lang=java
 *
 * [56] Merge Intervals
 * 
 * Problem Description:
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
 * and return an array of the non-overlapping intervals that cover all the intervals in the input.
 * 
 * Example 1:
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 * 
 * Example 2:
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * URL: https://leetcode.com/problems/merge-intervals/
 */

// @lc code=start

public class P56 {
    /**
     * @param intervals Array of [start, end] intervals
     * @return Merged intervals
     */
    public int[][] merge(int[][] intervals) {
        if (intervals.length <= 1) {
            return intervals;
        }

        // 1. Sort the intervals by start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> merged = new ArrayList<>();
        // Add the first interval to our list so we have something to compare against
        merged.add(intervals[0]);

        // 2. Iterate from the second interval
        for (int i = 1; i < intervals.length; i++) {
            int[] current = intervals[i];
            // Get the last interval we added to the merged list
            int[] lastMerged = merged.get(merged.size() - 1);

            // 3. Comparison Logic
            // If the current interval overlaps with the last merged interval
            // (i.e., current start <= lastMerged end)
            if (current[0] <= lastMerged[1]) {
                // Update the end of the last merged interval to be the max end
                lastMerged[1] = Math.max(lastMerged[1], current[1]);
            } else {
                // No overlap, so we add the current interval to the merged list
                merged.add(current);
            }
        }

        // 4. Convert the List<int[]> back to a 2D array (int[][])
        return merged.toArray(new int[merged.size()][]);
    }
}
// @lc code=end
