package list;
import common.*;


/*
 * @lc app=leetcode id=2 lang=java
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a
 * linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 * Example 2:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 * Example 3:
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 * Constraints:
 * - The number of nodes in each linked list is in the range [1, 100].
 * - 0 <= Node.val <= 9
 * - It is guaranteed that the list represents a number that does not have leading zeros.
 */

public class P2 {
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
