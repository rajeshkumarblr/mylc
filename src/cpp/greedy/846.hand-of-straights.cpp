#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 *
 * Difficulty: Medium
 * Category: greedy
 * URL: https://leetcode.com/problems/hand-of-straights/
 *
 * Description:
 * Alice has some number of cards and she wants to rearrange the cards into
 * groups so that each group is of size  groupSize , and consists of
 * groupSize  consecutive cards.
 *  Given an integer array  hand  where  hand[i]  is the value written on the
 * i th   card and an integer  groupSize , return  true  if she can rearrange
 * the cards, or  false  otherwise.
 *   Example 1:
 *  Input:  hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
 *  Output:  true
 *  Explanation:  Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
 *   Example 2:
 *  Input:  hand = [1,2,3,4,5], groupSize = 4
 *  Output:  false
 *  Explanation:  Alice's hand can not be rearranged into groups of 4.
 *   Constraints:
 *           1 <= hand.length <= 10 4
 *           0 <= hand[i] <= 10 9
 *           1 <= groupSize <= hand.length
 *   Note:  This question is the same as 1296:
 * https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-
 * numbers/
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
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
