/*
 * @lc app=leetcode id=322 lang=java
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
    public int coinChange(int[] coins, int amount) {
   
        int dp[] = new int[amount +1];
        dp[0] = 0;

        for (int a =1; a <= amount; a++) {
        
            dp[a] =amount +1;
            
            for (int coin : coins) {
                int target =  a - coin;
                if(target >= 0) {
                    dp[a] = Math.min(dp[a],  1 + dp[target]);
                }
            }          
            
        }         
        return dp[amount]  >= (amount+1) ? -1 : dp[amount];
        }

    }
// @lc code=end