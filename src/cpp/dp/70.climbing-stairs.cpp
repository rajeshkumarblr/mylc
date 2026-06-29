/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Example 1:
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 * Example 2:
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 * Constraints:
 * - 1 <= n <= 45
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // Base cases: 
        // 1 step -> 1 way (just climb 1)
        // 2 steps -> 2 ways (1+1 or 2)
        if (n <= 2) return n;
        
        // Dynamic Programming approach:
        // To reach step i, we can come from step (i-1) or step (i-2)
        // So: ways[i] = ways[i-1] + ways[i-2] (Fibonacci sequence!)
        
        int waysToReachPrevPrev = 1;  // ways to reach step (i-2)
        int waysToReachPrev = 2;      // ways to reach step (i-1)
        
        // Calculate ways to reach each step from 3 to n
        for (int currentStep = 3; currentStep <= n; currentStep++) {
            int waysToReachCurrent = waysToReachPrevPrev + waysToReachPrev;
            
            // Slide the window forward
            waysToReachPrevPrev = waysToReachPrev;
            waysToReachPrev = waysToReachCurrent;
        }
        
        return waysToReachPrev;  // This holds ways to reach step n
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
int climbStairs(int n) {
    Solution sol;
    return sol.climbStairs(n);
}

