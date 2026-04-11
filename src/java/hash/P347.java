package hash;

import java.util.*;

/**
 * 347. Top K Frequent Elements
 * Difficulty: Medium
 * 
 * Problem:
 * Given an integer array `nums` and an integer `k`, return the `k` most 
 * frequent elements. You may return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 */
public class P347 {
    // @lc app=leetcode id=347 lang=java
    // @lc code=start
    public static class Solution {
        /**
         * Strategy:
         * 1. Count frequencies using a HashMap.
         * 2. Use a PriorityQueue (Min-Heap) to keep track of the top K elements.
         *    OR use Bucket Sort for an O(n) solution.
         */
        public int[] topKFrequent(int[] nums, int k) {
            // Your code here
            return new int[0];
        }
    }
    // @lc code=end

    // Wrapper for driver
    public int[] topKFrequent(int[] nums, int k) {
        return new Solution().topKFrequent(nums, k);
    }
}
