class P739 {
    // @lc app=leetcode id=739 lang=java
    // @lc code=start
    public class Solution {
        public int[] dailyTemperatures(int[] t) {
            int n=t.length; int[] ans=new int[n];
            java.util.ArrayDeque<Integer> st = new java.util.ArrayDeque<>();
            for(int i=0;i<n;i++){
                while(!st.isEmpty() && t[i] > t[st.peek()]){
                    int j = st.pop();
                    ans[j] = i - j;
                }
                st.push(i);
            }
            return ans;
        }
    }
    // @lc code=end
}
