import java.util.*;

class P560 {
    // @lc app=leetcode id=560 lang=java
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

