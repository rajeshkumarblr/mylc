class P3_alt_hashmap {
    public class Solution {
        // HashMap with last seen index approach (optimal)
        public int lengthOfLongestSubstring(String s) {
            java.util.Map<Character, Integer> map = new java.util.HashMap<>();
            int maxLen = 0, left = 0;
            
            for (int right = 0; right < s.length(); right++) {
                char c = s.charAt(right);
                if (map.containsKey(c) && map.get(c) >= left) {
                    left = map.get(c) + 1;
                }
                map.put(c, right);
                maxLen = Math.max(maxLen, right - left + 1);
            }
            
            return maxLen;
        }
    }
}