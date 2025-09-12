// Test harness for Merge Two Sorted Lists
#include <vector>
#include "lc_types.h"
using namespace std;

/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
#ifndef LC_LOCAL_TEST
class Solution {
public:
#endif

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

#ifndef LC_LOCAL_TEST
};
#endif
// @lc code=end

