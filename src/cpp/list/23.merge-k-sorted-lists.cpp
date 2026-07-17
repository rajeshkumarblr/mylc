#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include "../lc_types.h"
#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
#include "../lc_types.h"
/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge K Sorted Lists
 *
 * Difficulty: Hard
 * Category: list
 * URL: https://leetcode.com/problems/merge-k-sorted-lists/
 *
 * Description:
 * You are given an array of  k  linked-lists  lists , each linked-list is
 * sorted in ascending order.
 *   Merge all the linked-lists into one sorted linked-list and return it.
 *   Example 1:
 *  Input:  lists = [[1,4,5],[1,3,4],[2,6]]
 *  Output:  [1,1,2,3,4,4,5,6]
 *  Explanation:  The linked-lists are:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * merging them into one sorted linked list:
 * 1->1->2->3->4->4->5->6
 *   Example 2:
 *  Input:  lists = []
 *  Output:  []
 *   Example 3:
 *  Input:  lists = [[]]
 *  Output:  []
 *   Constraints:
 *           k == lists.length
 *           0 <= k <= 10 4
 *           0 <= lists[i].length <= 500
 *           -10 4  <= lists[i][j] <= 10 4
 *           lists[i]  is sorted in  ascending order .
 *          The sum of  lists[i].length  will not exceed  10 4  .
 */

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
