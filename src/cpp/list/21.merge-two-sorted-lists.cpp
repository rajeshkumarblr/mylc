// Test harness for Merge Two Sorted Lists
#include <vector>
#include "lc_types.h"
using namespace std;

/*
 * @lc app=leetcode id=21 lang=cpp
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
 *
 * Description:
 * You are given the heads of two sorted linked lists  list1  and  list2 .
 *  Merge the two lists into one  sorted  list. The list should be made by
 * splicing together the nodes of the first two lists.
 *  Return  the head of the merged linked list .
 *   Example 1:
 *  Input:  list1 = [1,2,4], list2 = [1,3,4]
 *  Output:  [1,1,2,3,4,4]
 *   Example 2:
 *  Input:  list1 = [], list2 = []
 *  Output:  []
 *   Example 3:
 *  Input:  list1 = [], list2 = [0]
 *  Output:  [0]
 *   Constraints:
 *          The number of nodes in both lists is in the range  [0, 50] .
 *           -100 <= Node.val <= 100
 *          Both  list1  and  list2  are sorted in  non-decreasing  order.
 */

// @lc code=start
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode dummy;
        dummy.next =  nullptr;
        ListNode *tail = &dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        return dummy.next;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    Solution sol;
    return sol.mergeTwoLists(l1, l2);
}

