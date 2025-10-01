/*
 * @lc app=leetcode id=206 lang=java
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {

        if (head != null) {
            return getReversdList(head);
        }

        return head;

    }

    public ListNode getReversdList(ListNode head) {

        if (head.next == null) {
            return head;
        }

        ListNode newHead = getReversdList(head.next);

        head.next.next = head;
        head.next = null;
        return newHead;
    }

}
// @lc code=end
