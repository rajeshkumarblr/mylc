class P160 {
    // @lc app=leetcode id=160 lang=java
    // @lc code=start 
    public class Solution {
        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
            if (headA == null || headB == null) return null;
            
            // Calculate lengths
            int lenA = getLength(headA);
            int lenB = getLength(headB);
            
            // Align the starting points
            ListNode pA = headA;
            ListNode pB = headB;
            
            if (lenA > lenB) {
                for (int i = 0; i < lenA - lenB; i++) {
                    pA = (pA.Next != null ? pA.Next : pA.next);
                }
            } else if (lenB > lenA) {
                for (int i = 0; i < lenB - lenA; i++) {
                    pB = (pB.Next != null ? pB.Next : pB.next);
                }
            }
            
            // Find intersection
            while (pA != null && pB != null) {
                if (pA == pB) {
                    return pA;
                }
                pA = (pA.Next != null ? pA.Next : pA.next);
                pB = (pB.Next != null ? pB.Next : pB.next);
            }
            
            return null;
        }
        
        private int getLength(ListNode head) {
            int length = 0;
            ListNode curr = head;
            while (curr != null) {
                length++;
                curr = (curr.Next != null ? curr.Next : curr.next);
            }
            return length;
        }
    }
    // @lc code=end
}

