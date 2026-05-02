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
         * OR use Bucket Sort for an O(n) solution.
         */
        public int[] topKFrequent(int[] nums, int k) {
            Map<Integer, Integer> countMap = new HashMap<>();
            PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> countMap.get(b) - countMap.get(a));
            for (int i = 0; i < nums.length; i++) {
                countMap.put(nums[i], countMap.getOrDefault(nums[i], 0) + 1);
            }
            for (int num : countMap.keySet()) {
                pq.add(num);
            }
            int topk[] = new int[k];
            for (int i = 0; i < k; i++) {
                topk[i] = pq.poll();
            }
            return topk;
        }

        /**
         * Bucket Sort Approach (O(n) Time):
         */
        public int[] topKFrequentBucket(int[] nums, int k) {
            Map<Integer, Integer> countMap = new HashMap<>();
            for (int num : nums) {
                countMap.put(num, countMap.getOrDefault(num, 0) + 1);
            }

            // Create buckets where index is the frequency
            List<Integer>[] buckets = new List[nums.length + 1];
            for (int num : countMap.keySet()) {
                int freq = countMap.get(num);
                if (buckets[freq] == null) {
                    buckets[freq] = new ArrayList<>();
                }
                buckets[freq].add(num);
            }

            // Collect results from highest frequency to lowest
            int[] result = new int[k];
            int index = 0;
            for (int i = buckets.length - 1; i >= 0 && index < k; i--) {
                if (buckets[i] != null) {
                    for (int num : buckets[i]) {
                        result[index++] = num;
                        if (index == k) break;
                    }
                }
            }
            return result;
        }
    }
    // @lc code=end

    // Wrapper for driver
    public int[] topKFrequent(int[] nums, int k) {
        return new Solution().topKFrequent(nums, k);
    }
}
