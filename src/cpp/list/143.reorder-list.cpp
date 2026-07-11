/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * Difficulty: Medium
 * Category: list
 * URL: https://leetcode.com/problems/reorder-list/
 *
 * Description:
 * You are given the head of a singly linked-list. The list can be represented
 * as:
 * L 0  &rarr; L 1  &rarr; &hellip; &rarr; L n - 1  &rarr; L n
 *   Reorder the list to be on the following form:
 * L 0  &rarr; L n  &rarr; L 1  &rarr; L n - 1  &rarr; L 2  &rarr; L n - 2
 * &rarr; &hellip;
 *  You may not modify the values in the list's nodes. Only nodes themselves
 * may be changed.
 *   Example 1:
 *  Input:  head = [1,2,3,4]
 *  Output:  [1,4,2,3]
 *   Example 2:
 *  Input:  head = [1,2,3,4,5]
 *  Output:  [1,5,2,4,3]
 *   Constraints:
 *          The number of nodes in the list is in the range  [1, 5 * 10 4 ] .
 *           1 <= Node.val <= 1000
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
    void reorderList(ListNode* head) {
        
    }
};
// @lc code=end
