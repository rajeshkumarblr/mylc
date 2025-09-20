class P21 {
    // @lc app=leetcode id=21 lang=java
    // @lc code=start
    public class Solution {
        public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            ListNode dummy = new ListNode(0), t = dummy;
            ListNode p=l1, q=l2;
            while(p!=null || q!=null){
                if (q==null || (p!=null && p.val <= q.val)) { t.Next = p; t.next = p; p = (p!=null? (p.Next!=null?p.Next:p.next):null); }
                else { t.Next = q; t.next = q; q = (q!=null? (q.Next!=null?q.Next:q.next):null); }
                t = (t.Next!=null ? t.Next : t.next);
            }
            return dummy.Next;
        }
    }
    // @lc code=end
}
