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
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find The Duplicate Number
 *
 * Difficulty: Medium
 * Category: list
 * URL: https://leetcode.com/problems/find-the-duplicate-number/
 *
 * Description:
 * Given an array of integers  nums  containing  n + 1  integers where each
 * integer is in the range  [1, n]  inclusive.
 *  There is only  one repeated number  in  nums , return  this repeated
 * number .
 *  You must solve the problem  without  modifying the array  nums  and using
 * only constant extra space.
 *   Example 1:
 *  Input:  nums = [1,3,4,2,2]
 *  Output:  2
 *   Example 2:
 *  Input:  nums = [3,1,3,4,2]
 *  Output:  3
 *   Example 3:
 *  Input:  nums = [3,3,3,3,3]
 *  Output:  3
 *   Constraints:
 *           1 <= n <= 10 5
 *           nums.length == n + 1
 *           1 <= nums[i] <= n
 *          All the integers in  nums  appear only  once  except for
 * precisely one integer  which appears  two or more  times.
 *   Follow up:
 *          How can we prove that at least one duplicate number must exist in
 * nums ?
 *          Can you solve the problem in linear runtime complexity?
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
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
