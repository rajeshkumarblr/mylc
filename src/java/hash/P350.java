package hash;
import common.*;
import java.util.*;

/*
 * @lc app=leetcode id=350 lang=java
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must appear as many times as it
 * shows in both arrays and you may return the result in any order.
 *
 * Example 1:
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 * Example 2:
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * Explanation: [9,4] is also accepted.
 *
 * Constraints:
 * - 1 <= nums1.length, nums2.length <= 1000
 * - 0 <= nums1[i], nums2[i] <= 1000
 *
 * Follow up:
 * - What if the given array is already sorted? How would you optimize your
 *   algorithm?
 * - What if nums1's size is small compared to nums2's size? Which algorithm is
 *   better?
 * - What if elements of nums2 are stored on disk, and the memory is limited
 *   such that you cannot load all elements into the memory at once?
 */
public class P350 {
    // @lc app=leetcode id=350 lang=java
    // @lc code=start
    public static class Solution {
        public int[] intersect(int[] nums1, int[] nums2) {
            // Your code here
            HashMap<Integer, Integer> map1 = new HashMap<>();
            HashMap<Integer, Integer> map2 = new HashMap<>();
            for (int i : nums1) {
                map1.put(i, map1.getOrDefault(i, 0) + 1);
            }
            for (int i : nums2) {
                map2.put(i, map2.getOrDefault(i, 0) + 1);
            }
            List<Integer> list = new ArrayList<>();
            for (int i : map1.keySet()) {
                if (map2.containsKey(i)) {
                    int count = Math.min(map1.get(i), map2.get(i));
                    for (int j = 0; j < count; j++) {
                        list.add(i);
                    }
                }
            }
            int[] result = new int[list.size()];
            for (int i = 0; i < list.size(); i++) {
                result[i] = list.get(i);
            }
            return result;
        }
    }
    // @lc code=end

    // Wrapper for compatibility with your driver
    public int[] intersect(int[] nums1, int[] nums2) {
        return new Solution().intersect(nums1, nums2);
    }
}
