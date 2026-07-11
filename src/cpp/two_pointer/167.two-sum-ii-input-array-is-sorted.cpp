/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II Input Array Is Sorted
 *
 * Difficulty: Medium
 * Category: two_pointer
 * URL: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *
 * Description:
 * Given a  1-indexed  array of integers  numbers  that is already   sorted in
 * non-decreasing order  , find two numbers such that they add up to a
 * specific  target  number. Let these two numbers be  numbers[index 1 ]  and
 * numbers[index 2 ]  where  1 <= index 1  < index 2  <= numbers.length .
 *  Return  the indices of the two numbers   index 1    and   index 2   ,
 * each incremented by one,  as an integer array   [index 1 , index 2 ]   of
 * length 2.
 *  The tests are generated such that there is  exactly one solution . You
 * may not  use the same element twice.
 *  Your solution must use only constant extra space.
 *   Example 1:
 *  Input:  numbers = [ 2 , 7 ,11,15], target = 9
 *  Output:  [1,2]
 *  Explanation:  The sum of 2 and 7 is 9. Therefore, index 1  = 1, index 2  =
 * 2. We return [1, 2].
 *   Example 2:
 *  Input:  numbers = [ 2 ,3, 4 ], target = 6
 *  Output:  [1,3]
 *  Explanation:  The sum of 2 and 4 is 6. Therefore index 1  = 1, index 2  =
 * 3. We return [1, 3].
 *   Example 3:
 *  Input:  numbers = [ -1 , 0 ], target = -1
 *  Output:  [1,2]
 *  Explanation:  The sum of -1 and 0 is -1. Therefore index 1  = 1, index 2
 * = 2. We return [1, 2].
 *   Constraints:
 *           2 <= numbers.length <= 3 * 10 4
 *           -1000 <= numbers[i] <= 1000
 *           numbers  is sorted in  non-decreasing order .
 *           -1000 <= target <= 1000
 *          The tests are generated such that there is  exactly one solution .
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
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
    }
};
// @lc code=end
