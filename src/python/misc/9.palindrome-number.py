"""
@lc app=leetcode id=9 lang=python3

[9] Palindrome Number

https://leetcode.com/problems/palindrome-number/description/

Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:
- -2^31 <= x <= 2^31 - 1
"""

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        
        original = x
        reversed_num = 0
        while x > 0:
            reversed_num = reversed_num * 10 + x % 10
            x //= 10
            
        return original == reversed_num
