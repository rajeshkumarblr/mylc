#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include <cmath>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * Difficulty: Medium
 * Category: list
 * URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Description:
 * Given the  head  of a linked list, remove the  n th   node from the end of
 * the list and return its head.
 *   Example 1:
 *  Input:  head = [1,2,3,4,5], n = 2
 *  Output:  [1,2,3,5]
 *   Example 2:
 *  Input:  head = [1], n = 1
 *  Output:  []
 *   Example 3:
 *  Input:  head = [1,2], n = 1
 *  Output:  [1]
 *   Constraints:
 *          The number of nodes in the list is  sz .
 *           1 <= sz <= 30
 *           0 <= Node.val <= 100
 *           1 <= n <= sz
 *   Follow up:  Could you do this in one pass?
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

void printList(ListNode *head);


void printList(ListNode *head);


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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int i = 0;
    if (head == nullptr)
      return nullptr;
    ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    ListNode *front = &dummy;
    while (front != nullptr && i <= n) {
      front = front->next;
      i++;
    }
    ListNode *nd = &dummy;
    while (front != nullptr) {
      front = front->next;
      nd = nd->next;
    }

    nd->next = (nd->next) ? nd->next->next : nullptr;

    return dummy.next;
  }
};
// @lc code=end







// Helper function to create a linked list from a vector
ListNode *createList(const vector<int> &vals) {
  if (vals.empty())
    return nullptr;
  ListNode *head = new ListNode(vals[0]);
  ListNode *current = head;
  for (size_t i = 1; i < vals.size(); ++i) {
    current->next = new ListNode(vals[i]);
    current = current->next;
  }
  return head;
}

// Helper function to print a linked list in LeetCode format
void printList(ListNode *head) {
  cout << "[";
  while (head != nullptr) {
    cout << head->val;
    if (head->next != nullptr) {
      cout << ",";
    }
    head = head->next;
  }
  cout << "]" << endl;
}



int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
