#include <vector>
#include <iostream>
#include "../lc_types.h"
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

// Helper: build two linked lists that intersect at a given value
static void buildIntersectingLists(
    const vector<int> &arrA, const vector<int> &arrB,
    int intersectVal, int skipA, int skipB,
    ListNode *&headA, ListNode *&headB) {

    if (intersectVal == 0) {
        headA = vec_to_list(arrA);
        headB = vec_to_list(arrB);
        return;
    }

    ListNode *shared = nullptr;
    ListNode *sharedTail = nullptr;
    for (int i = skipA; i < (int)arrA.size(); ++i) {
        ListNode *node = new ListNode(arrA[i]);
        if (!shared) { shared = node; sharedTail = node; }
        else { sharedTail->next = node; sharedTail = node; }
    }

    ListNode dummyA;
    ListNode *curr = &dummyA;
    for (int i = 0; i < skipA; ++i) {
        curr->next = new ListNode(arrA[i]);
        curr = curr->next;
    }
    curr->next = shared;
    headA = dummyA.next;

    ListNode dummyB;
    curr = &dummyB;
    for (int i = 0; i < skipB; ++i) {
        curr->next = new ListNode(arrB[i]);
        curr = curr->next;
    }
    curr->next = shared;
    headB = dummyB.next;
}

int main() {
    Solution sol;
    // Case 1
    {
        vector<int> listA = {4, 1, 8, 4, 5};
        vector<int> listB = {5, 6, 1, 8, 4, 5};
        ListNode *headA, *headB;
        buildIntersectingLists(listA, listB, 8, 2, 3, headA, headB);
        auto got = sol.getIntersectionNode(headA, headB);
        if (!got || got->val != 8) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}