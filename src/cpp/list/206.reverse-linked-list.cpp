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
#include <vector>
#include "lc_types.h"
using namespace std;

/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * Description:
 * Given the  head  of a singly linked list, reverse the list, and return  the
 * reversed list .
 *   Example 1:
 *  Input:  head = [1,2,3,4,5]
 *  Output:  [5,4,3,2,1]
 *   Example 2:
 *  Input:  head = [1,2]
 *  Output:  [2,1]
 *   Example 3:
 *  Input:  head = []
 *  Output:  []
 *   Constraints:
 *          The number of nodes in the list is the range  [0, 5000] .
 *           -5000 <= Node.val <= 5000
 *   Follow up:  A linked list can be reversed either iteratively or
 * recursively. Could you implement both?
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





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> head_arr{1, 2, 3, 4, 5};
        ListNode* head = vec_to_list(head_arr);
        ListNode* got_node = sol.reverseList(head);
        vector<int> got = list_to_vec(got_node);
        if (got != vector<int>{5, 4, 3, 2, 1}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> head_arr{1, 2};
        ListNode* head = vec_to_list(head_arr);
        ListNode* got_node = sol.reverseList(head);
        vector<int> got = list_to_vec(got_node);
        if (got != vector<int>{2, 1}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> head_arr{};
        ListNode* head = vec_to_list(head_arr);
        ListNode* got_node = sol.reverseList(head);
        vector<int> got = list_to_vec(got_node);
        if (got != vector<int>{}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
