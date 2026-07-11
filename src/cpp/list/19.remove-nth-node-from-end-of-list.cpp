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

#include "../lc_test_utils.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    }
};
// @lc code=end
