#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <utility>
#include "../lc_types.h"
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






int main() {
    Solution sol;
    // Case 1
    {
        vector<int> l1_arr{1, 2, 4};
        ListNode* l1 = vec_to_list(l1_arr);
        vector<int> l2_arr{1, 3, 4};
        ListNode* l2 = vec_to_list(l2_arr);
        ListNode* got_node = sol.mergeTwoLists(l1, l2);
        vector<int> got = list_to_vec(got_node);
        if (got != vector<int>{1, 1, 2, 3, 4, 4}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> l1_arr{};
        ListNode* l1 = vec_to_list(l1_arr);
        vector<int> l2_arr{};
        ListNode* l2 = vec_to_list(l2_arr);
        ListNode* got_node = sol.mergeTwoLists(l1, l2);
        vector<int> got = list_to_vec(got_node);
        if (got != vector<int>{}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> l1_arr{};
        ListNode* l1 = vec_to_list(l1_arr);
        vector<int> l2_arr{0};
        ListNode* l2 = vec_to_list(l2_arr);
        ListNode* got_node = sol.mergeTwoLists(l1, l2);
        vector<int> got = list_to_vec(got_node);
        if (got != vector<int>{0}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        vector<int> l1_arr{2};
        ListNode* l1 = vec_to_list(l1_arr);
        vector<int> l2_arr{1};
        ListNode* l2 = vec_to_list(l2_arr);
        ListNode* got_node = sol.mergeTwoLists(l1, l2);
        vector<int> got = list_to_vec(got_node);
        if (got != vector<int>{1, 2}) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        vector<int> l1_arr{1, 3, 5};
        ListNode* l1 = vec_to_list(l1_arr);
        vector<int> l2_arr{2, 4, 6};
        ListNode* l2 = vec_to_list(l2_arr);
        ListNode* got_node = sol.mergeTwoLists(l1, l2);
        vector<int> got = list_to_vec(got_node);
        if (got != vector<int>{1, 2, 3, 4, 5, 6}) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    // Case 6
    {
        vector<int> l1_arr{1, 2, 3};
        ListNode* l1 = vec_to_list(l1_arr);
        vector<int> l2_arr{};
        ListNode* l2 = vec_to_list(l2_arr);
        ListNode* got_node = sol.mergeTwoLists(l1, l2);
        vector<int> got = list_to_vec(got_node);
        if (got != vector<int>{1, 2, 3}) {
            cerr << "FAIL case 6" << endl;
            return 1;
        }
    }
    // Case 7
    {
        vector<int> l1_arr{};
        ListNode* l1 = vec_to_list(l1_arr);
        vector<int> l2_arr{1, 2, 3};
        ListNode* l2 = vec_to_list(l2_arr);
        ListNode* got_node = sol.mergeTwoLists(l1, l2);
        vector<int> got = list_to_vec(got_node);
        if (got != vector<int>{1, 2, 3}) {
            cerr << "FAIL case 7" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
