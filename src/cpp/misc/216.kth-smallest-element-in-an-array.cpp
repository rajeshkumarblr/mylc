#include <unordered_set>
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
/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Kth Smallest Element in an Array
 */

#include <vector>
#include <queue>
using namespace std;


// @lc code=start
class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for (int num : nums) {
            maxHeap.push(num);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};
// @lc code=end


int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {3, 2, 1, 5, 6, 4};
        int k = 2;
        auto got = sol.findKthSmallest(nums, k);
        if (got != 2) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        int k = 4;
        auto got = sol.findKthSmallest(nums, k);
        if (got != 3) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
