
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
#include "lc_types.h"

// @lc code=start
#ifndef LC_LOCAL_TEST
class Solution {
public:
#endif
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
        carry = sum / 10;
    }
    return dummy.next;
}
#ifndef LC_LOCAL_TEST
};
#endif
// @lc code=end
