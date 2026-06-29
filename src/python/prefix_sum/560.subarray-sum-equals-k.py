"""
@lc app=leetcode id=560 lang=python3

[560] Subarray Sum Equals K

https://leetcode.com/problems/subarray-sum-equals-k/description/

Given an array of integers nums and an integer k, return the total number
of continuous subarrays whose sum equals k.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Constraints:
- 1 <= nums.length <= 2 * 10^4
- -1000 <= nums[i] <= 1000
- -10^7 <= k <= 10^7
"""

from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        curSum = 0
        prefixSums = {0: 1}
        
        for n in nums:
            curSum += n
            diff = curSum - k
            
            res += prefixSums.get(diff, 0)
            prefixSums[curSum] = prefixSums.get(curSum, 0) + 1
            
        return res
