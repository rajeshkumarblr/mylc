class P438 {
    // @lc app=leetcode id=438 lang=java
    // @lc code=start
    public class Solution {
        public java.util.List<Integer> findAnagrams(String s, String p) {
            int[] need = new int[26], have = new int[26];
            for (int i=0;i<p.length();i++) need[p.charAt(i)-'a']++;
            java.util.List<Integer> ans = new java.util.ArrayList<>();
            int m=p.length();
            for (int i=0;i<s.length();i++){
                have[s.charAt(i)-'a']++;
                if (i>=m) have[s.charAt(i-m)-'a']--;
                if (i+1>=m && same(have, need)) ans.add(i-m+1);
            }
            return ans;
        }
        private boolean same(int[] a, int[] b){
            for(int i=0;i<26;i++) if (a[i]!=b[i]) return false; return true;
        }
    }
    // @lc code=end
}
