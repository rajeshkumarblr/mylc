#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * Difficulty: Medium
 * Category: binary_search
 * URL: https://leetcode.com/problems/koko-eating-bananas/
 *
 * Description:
 * Koko loves to eat bananas. There are  n  piles of bananas, the  i th   pile
 * has  piles[i]  bananas. The guards have gone and will come back in  h
 * hours.
 *  Koko can decide her bananas-per-hour eating speed of  k . Each hour, she
 * chooses some pile of bananas and eats  k  bananas from that pile. If the
 * pile has less than  k  bananas, she eats all of them instead and will not
 * eat any more bananas during this hour.
 *  Koko likes to eat slowly but still wants to finish eating all the bananas
 * before the guards return.
 *  Return  the minimum integer   k   such that she can eat all the bananas
 * within   h   hours .
 *   Example 1:
 *  Input:  piles = [3,6,7,11], h = 8
 *  Output:  4
 *   Example 2:
 *  Input:  piles = [30,11,23,4,20], h = 5
 *  Output:  30
 *   Example 3:
 *  Input:  piles = [30,11,23,4,20], h = 6
 *  Output:  23
 *   Constraints:
 *           1 <= piles.length <= 10 4
 *           piles.length <= h <= 10 9
 *           1 <= piles[i] <= 10 9
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
    int minEatingSpeed(vector<int>& piles, int h) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
