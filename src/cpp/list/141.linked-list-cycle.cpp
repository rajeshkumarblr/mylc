#include "../lc_types.h"
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 *
 * Difficulty: Easy
 * Category: list
 * URL: https://leetcode.com/problems/linked-list-cycle/
 *
 * Description:
 * Given  head , the head of a linked list, determine if the linked list has a
 * cycle in it.
 *  There is a cycle in a linked list if there is some node in the list that
 * can be reached again by continuously following the  next  pointer.
 * Internally,  pos  is used to denote the index of the node that tail's  next
 * pointer is connected to.  Note that  pos  is not passed as a parameter .
 *  Return  true   if there is a cycle in the linked list . Otherwise, return
 * false .
 *   Example 1:
 *  Input:  head = [3,2,0,-4], pos = 1
 *  Output:  true
 *  Explanation:  There is a cycle in the linked list, where the tail connects
 * to the 1st node (0-indexed).
 *   Example 2:
 *  Input:  head = [1,2], pos = 0
 *  Output:  true
 *  Explanation:  There is a cycle in the linked list, where the tail connects
 * to the 0th node.
 *   Example 3:
 *  Input:  head = [1], pos = -1
 *  Output:  false
 *  Explanation:  There is no cycle in the linked list.
 *   Constraints:
 *          The number of the nodes in the list is in the range  [0, 10 4 ] .
 *           -10 5  <= Node.val <= 10 5
 *           pos  is  -1  or a  valid index  in the linked-list.
 *   Follow up:  Can you solve it using  O(1)  (i.e. constant) memory?
 */

#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution sol;
  int failed = 0;

  // Case 1: head = [3,2,0,-4], pos = 1 (cycle at index 1)
  {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creates cycle to '2'

    if (sol.hasCycle(head) != true) {
      cerr << "FAIL: Case 1" << endl;
      failed++;
    }
  }

  // Case 2: head = [1,2], pos = 0 (cycle at index 0)
  {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head; // Creates cycle to '1'

    if (sol.hasCycle(head) != true) {
      cerr << "FAIL: Case 2" << endl;
      failed++;
    }
  }

  // Case 3: head = [1], pos = -1 (no cycle)
  {
    ListNode *head = new ListNode(1);

    if (sol.hasCycle(head) != false) {
      cerr << "FAIL: Case 3" << endl;
      failed++;
    }
  }

  if (failed == 0) {
    cout << "PASS" << endl;
    return 0;
  }
  return 1;
}
