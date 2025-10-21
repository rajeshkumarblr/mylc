import java.util.HashSet;
import java.util.Set;

class P3_alt_hashset {
    
     // @lc app=leetcode id=3 lang=java
    // @lc code=start
    public class Solution {
         public int lengthOfLongestSubstring(String s) {
        
        if(s == null ) {
            return 0;
        }

        int len = s.length();

        if(len ==1){
            return 1;
        }

        Set<Character> uniChars = new HashSet<>();

        int left=0 , right  =0;
        int maxLen = 0;
        while (right <len) {
            if(!uniChars.contains(s.charAt(right))){
                 uniChars.add(s.charAt(right));
                right ++;
               
            } else{
                 maxLen = Math.max(right-left , maxLen);
                 right = ++left;
                uniChars.clear();
            
            }

            if(right == len) {
                maxLen = Math.max(right-left , maxLen);
                
            }
        }
   
        return maxLen;
    }
    }
    // @lc code=end

    
    
}
