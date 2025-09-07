// Test harness for Merge Two Sorted Lists
#include <vector>
#include <iostream>
#include <initializer_list>
#include <cassert>
#include "lc_test_utils.h"
using namespace std;

/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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

// Helper to create a linked list from a vector
ListNode* vec_to_list(const vector<int>& v) {
    ListNode dummy;
    ListNode* curr = &dummy;
    for (int x : v) {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy.next;
}

// Helper to convert a linked list to a vector
vector<int> list_to_vec(ListNode* head) {
    vector<int> v;
    while (head) {
        v.push_back(head->val);
        head = head->next;
    }
    return v;
}

// Helper to free a linked list
void free_list(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution sol;
    vector<tuple<vector<int>, vector<int>, vector<int>>> tests = {
        {{1,2,4}, {1,3,4}, {1,1,2,3,4,4}},
        {{}, {}, {}},
        {{}, {0}, {0}},
        {{2}, {1}, {1,2}},
        {{1,3,5}, {2,4,6}, {1,2,3,4,5,6}},
        {{1,2,3}, {}, {1,2,3}},
        {{}, {1,2,3}, {1,2,3}}
    };
    bool all_passed = true;
    for (const auto& [v1, v2, expected] : tests) {
        ListNode* l1 = vec_to_list(v1);
        ListNode* l2 = vec_to_list(v2);
        ListNode* merged = sol.mergeTwoLists(l1, l2);
        vector<int> v = list_to_vec(merged);
        bool pass = (v == expected);
        cout << "Input: " << v1 << v2;
        cout << "| Expected: " << expected;
        cout << "| Got: "<< v;
        cout << (pass ? "| PASS" : "| FAIL") << endl;
        all_passed &= pass;
        free_list(merged);
    }
    cout << "\nFinal Result: " << (all_passed ? "PASS" : "FAIL") << endl;
    return all_passed ? 0 : 1;  
}
