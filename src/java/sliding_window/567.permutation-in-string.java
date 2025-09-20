class P567 {
    // @lc app=leetcode id=567 lang=java
    // @lc code=start
    public class Solution {
        public boolean checkInclusion(String s1, String s2) {
            int n1 = s1.length(), n2 = s2.length();
            if (n1 > n2) return false;
            int[] need = new int[26], have = new int[26];
            for (int i=0;i<n1;i++) need[s1.charAt(i)-'a']++;
            for (int i=0;i<n2;i++){
                have[s2.charAt(i)-'a']++;
                if (i>=n1) have[s2.charAt(i-n1)-'a']--;
                if (i+1>=n1 && same(have, need)) return true;
            }
            return false;
        }
        private boolean same(int[] a, int[] b){ for(int i=0;i<26;i++) if (a[i]!=b[i]) return false; return true; }
    }
    // @lc code=end
}
