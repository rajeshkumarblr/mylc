#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * Difficulty: Medium
 * Category: hash
 * URL: https://leetcode.com/problems/longest-consecutive-sequence/
 *
 * Description:
 * Given an unsorted array of integers  nums , return  the length of the
 * longest consecutive elements sequence.
 *  You must write an algorithm that runs in  O(n)  time.
 *   Example 1:
 *  Input:  nums = [100,4,200,1,3,2]
 *  Output:  4
 *  Explanation:  The longest consecutive elements sequence is  [1, 2, 3, 4] .
 * Therefore its length is 4.
 *   Example 2:
 *  Input:  nums = [0,3,7,2,5,8,4,6,0,1]
 *  Output:  9
 *   Example 3:
 *  Input:  nums = [1,0,1,2]
 *  Output:  3
 *   Constraints:
 *           0 <= nums.length <= 10 5
 *           -10 9  <= nums[i] <= 10 9
 */

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> numset(nums.begin(), nums.end());

    int maxSequence = 0;
    for (auto num : numset) {
      if (numset.contains(num - 1)) {
        continue;
      } else {
        int n;
        for (n = num + 1; numset.contains(n); n++)
          ;
        maxSequence = max(n - num, maxSequence);
      }
    }
    return maxSequence;
  }
};
// @lc code=end

int main() {
  Solution sol;

  // Case 1
  {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int expected = 4;
    if (sol.longestConsecutive(nums) != expected) {
      cerr << "FAIL case 1" << endl;
      return 1;
    }
  }

  // Case 2
  {
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int expected = 9;
    if (sol.longestConsecutive(nums) != expected) {
      cerr << "FAIL case 2" << endl;
      return 1;
    }
  }

  // Case 3
  {
    vector<int> nums = {1, 0, 1, 2};
    int expected = 3;
    if (sol.longestConsecutive(nums) != expected) {
      cerr << "FAIL case 3" << endl;
      return 1;
    }
  }

  // Case 4 (Empty array)
  {
    vector<int> nums = {};
    int expected = 0;
    if (sol.longestConsecutive(nums) != expected) {
      cerr << "FAIL case 4" << endl;
      return 1;
    }
  }

  cout << "PASS" << endl;
  return 0;
}
