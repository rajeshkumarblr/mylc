package prefix_sum;
import common.*;


import java.util.*;

public class P560 {
/*
 * @lc app=leetcode id=560 lang=java
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * Given an array of integers nums and an integer k, return the total number
 * of continuous subarrays whose sum equals k.
 *
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 *
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 *
 * Constraints:
 * - 1 <= nums.length <= 2 * 10^4
 * - -1000 <= nums[i] <= 1000
 * - -10^7 <= k <= 10^7
 */
    // @lc code=start
    public class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer,Integer> prefixMap = new HashMap<>();
                        //base case
                        prefixMap.put(0,1);

                        int currentSum  =0;
                        int numOfSubarray = 0;
                        for(int num:nums) {
                            currentSum += num;
                            int subArrayPreviousSum = currentSum - k;


                            Integer integer = prefixMap.get(subArrayPreviousSum);
                            if(integer != null){
                                numOfSubarray += integer;}

                                prefixMap.compute(currentSum,(key,v) -> v == null ? 1 : v +1);
                
            }

        return numOfSubarray;
    }
    }
    // @lc code=end
}

