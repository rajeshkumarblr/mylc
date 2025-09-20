class P2 {
    // @lc app=leetcode id=2 lang=java
    // @lc code=start
    public class Solution {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode dummy = new ListNode(0), t = dummy;
            int carry = 0;
            while (l1 != null || l2 != null || carry != 0) {
                int a = (l1 != null ? l1.val : 0);
                int b = (l2 != null ? l2.val : 0);
                int sum = a + b + carry;
                carry = sum / 10;
                t.Next = new ListNode(sum % 10);
                t.next = t.Next;
                t = t.Next;
                l1 = (l1 != null ? (l1.Next != null ? l1.Next : l1.next) : null);
                l2 = (l2 != null ? (l2.Next != null ? l2.Next : l2.next) : null);
            }
            return dummy.Next;
        }
    }
    // @lc code=end
}
