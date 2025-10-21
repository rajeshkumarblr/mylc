class P206 {
    // @lc app=leetcode id=206 lang=java
    // @lc code=start
    public class Solution {
        public ListNode reverseList(ListNode head) {
            ListNode prev = null;
            ListNode curr = head;
            
            while (curr != null) {
                ListNode next = (curr.Next != null ? curr.Next : curr.next);
                // Update both fields to maintain consistency
                curr.next = prev;
                curr.Next = prev;
                prev = curr;
                curr = next;
            }
            
            return prev;
        }
    }
    // @lc code=end
}
