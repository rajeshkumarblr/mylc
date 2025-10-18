/*
 * @lc app=leetcode id=160 lang=java
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

 //* Definition for singly-linked list.
   class ListNode {
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
      }
  }
 
 class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lenA = getLength(headA);
            int lenB = getLength(headB);
System.out.println("lenA:" + lenA);
            System.out.println("lenB:" + lenB);
            if(lenA > lenB) {
                int diff = lenA - lenB;
                for(int i =0; i< diff; i++) {
                    headA = headA.next;
                }
            }

            if(lenB> lenA) {
                int diff = lenB - lenA;
                for(int i =0; i< diff; i++) {
                    headB= headB.next;
                }
            }

            while(headA != headB) {

                headA = headA.next;
                headB= headB.next;
                if(headA == null || headB==null) {
                    return null;
                }
                
            }

            return headA;


        }


        public int getLength(ListNode listNode) {
            int length = 0;
            while(listNode!=null) {
                listNode = listNode.next;
                length ++;
            }
            return length;
        }
    
}
// @lc code=end

