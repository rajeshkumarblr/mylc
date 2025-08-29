/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *node = nullptr, *head = nullptr, *prev = nullptr;
        while (list1 != nullptr && list2 != nullptr)
        {
            ListNode *tmp = new ListNode();
            if (list1->val < list2->val) {
                tmp->val = list1->val;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     tmp->val = list1->val;
            } else {
                tmp->val = list2 ->val;
            }

            if (prev) {
                prev->next = tmp;
            } else {
                head = tmp;
            }

            prev = tmp;
        }

        return head;
    }
};
// @lc code=end

