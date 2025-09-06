/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
#include "lc_test_utils.h"

// @lc code=start
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val < b->val) { tail->next = a; a = a->next; }
            else                  { tail->next = b; b = b->next; }
            tail = tail->next;
        }
        tail->next = a ? a : b;       // append remaining nodes
        return dummy.next;
    }
};
// @lc code=end

#include <vector>
using namespace std;

int main() {
    Solution sol;
    using In  = pair<vector<int>, vector<int>>;
    using Out = vector<int>;
    vector<pair<In, Out>> tests = {
        { {{1,2,4}, {}},            {1,2,4} },
        { {{}, {1,3,4}},            {1,3,4} },
        { {{1,2,4}, {1,3,4}},       {1,1,2,3,4,4} },
        { {{}, {}},                 {} },
        { {{2}, {1}},               {1,2} },
        { {{1,3,5}, {2,4,6}},       {1,2,3,4,5,6} }
    };

    auto fn = [&](auto* l1, auto* l2){ return sol.mergeTwoLists(l1, l2); };

    // LC21 reuses input nodes → free ONLY the returned merged list
    return run_ll_cases<ListNode>(tests, fn, /* reuse_inputs = */ true) ? 0 : 1;
}
