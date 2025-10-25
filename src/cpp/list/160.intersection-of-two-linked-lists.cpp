#include <vector>
#include "lc_types.h"
using namespace std;

/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        // Two pointer technique: when one reaches end, start from other head
        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        
        return pA; // Either intersection node or nullptr
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    Solution sol;
    return sol.getIntersectionNode(headA, headB);
}