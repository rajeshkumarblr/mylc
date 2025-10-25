#include <vector>
#include "lc_types.h"
using namespace std;

/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
ListNode* reverseList(ListNode* head) {
    Solution sol;
    return sol.reverseList(head);
}