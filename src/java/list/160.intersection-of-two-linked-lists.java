class P160 {
    // @lc app=leetcode id=160 lang=java
    // @lc code=start 
    public class Solution {
        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
            if (headA == null || headB == null) return null;
            
            ListNode pA = headA;
            ListNode pB = headB;
            
            // Two pointer technique: when one reaches end, start from other head
            while (pA != pB) {
                pA = (pA == null) ? headB : pA.next;
                pB = (pB == null) ? headA : pB.next;
            }
            
            return pA; // Either intersection node or null
        }
    }
    // @lc code=end
}

