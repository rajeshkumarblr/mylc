import java.util.*;

public class P139 {
    static class Solution {
        public boolean wordBreak(String s, List<String> wordDict) {
            int n = s.length();
            boolean[] dp = new boolean[n + 1];
            dp[0] = true; // Empty string can always be broken
            
            // Convert wordDict to HashSet for O(1) lookup
            Set<String> wordSet = new HashSet<>(wordDict);
            
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    String word = s.substring(j, i);
                    if (dp[j] && wordSet.contains(word)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            
            return dp[n];
        }
    }
    
    // Wrapper method for driver compatibility
    public boolean wordBreak(String s, List<String> wordDict) {
        return new Solution().wordBreak(s, wordDict);
    }
}