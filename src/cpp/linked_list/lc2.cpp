/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *nextNode) : val(x), next(nextNode) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *prev = nullptr , *node = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry > 0)
        {
            node = new ListNode();
            if (prev != nullptr) 
            {
                prev->next = node;
            }
            else {
                head = node;
            }            
            int tot = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            node->val = tot % 10;
            carry = tot / 10;
            prev = node;  
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return head;
    }
};
// @lc code=end

#include "lc_test_utils.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Helper to create a linked list from vector
ListNode* makeList(const vector<int>& vals) {
    ListNode dummy;
    ListNode* curr = &dummy;
    for (int v : vals) {
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    return dummy.next;
}

// Helper to convert linked list to vector
vector<int> listToVector(ListNode* node) {
    vector<int> out;
    while (node) {
        out.push_back(node->val);
        node = node->next;
    }
    return out;
}

// Helper to free a linked list
void freeList(ListNode* node) {
    while (node) {
        ListNode* tmp = node;
        node = node->next;
        delete tmp;
    }
}

int main() {
    Solution sol;
    using input_t = pair<vector<int>, vector<int>>;
    vector<pair<input_t, vector<int>>> test_cases = {
        { {{2,4,3}, {5,6,4}}, {7,0,8} },
        { {{0}, {0}}, {0} },
        { {{9,9,9,9,9,9,9}, {9,9,9,9}}, {8,9,9,9,0,0,0,1} },
        { {{1,8}, {0}}, {1,8} }
    };
    bool all_passed = true;
    for (const auto& [input, expected] : test_cases) {
        ListNode* l1 = makeList(input.first);
        ListNode* l2 = makeList(input.second);
        ListNode* result = sol.addTwoNumbers(l1, l2);
        vector<int> result_vec = listToVector(result);
        cout << "Input: ";
        print_vector(input.first); cout << " + "; print_vector(input.second);
        cout << " | ";
        if (result_vec == expected) {
            cout << "PASS";
        } else {
            cout << "FAIL (got: "; 
            print_vector(result_vec); 
            cout << "; expected: "; 
            print_vector(expected); cout << ")";
            all_passed = false;
        }
        cout << endl;
        freeList(l1);
        freeList(l2);
        freeList(result);
    }
    return all_passed ? 0 : 1;
}

