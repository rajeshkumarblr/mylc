package list;
import common.*;


/*
 * @lc app=leetcode id=21 lang=java
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * You are given the heads of two sorted linked lists list1 and list2.
 *
 * Merge the two lists in a single sorted list. The list should be made by
 * splicing together the nodes of the first two lists.
 *
 * Return the head of the merged linked list.
 *
 * Example 1:
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 * Example 2:
 * Input: list1 = [], list2 = []
 * Output: []
 *
 * Example 3:
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 *
 * Constraints:
 * - The number of nodes in both lists is in the range [0, 50].
 * - -100 <= Node.val <= 100
 * - Both list1 and list2 are sorted in non-decreasing order.
 */

public class P21 {
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
