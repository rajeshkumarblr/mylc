#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
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

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;
    while (l < r) {
      if (numbers[l] + numbers[r] == target) {
        return {l + 1, r + 1};
      } else if (numbers[l] + numbers[r] > target) {
        r = r - 1;
      } else {
        l = l + 1;
      }
    }
    return {};
  }
};
// @lc code=end

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  try {
    json j = json::parse(R"raw({
      "cases": [
        {
          "numbers": [2, 7, 11, 15],
          "target": 9,
          "expected": [1, 2]
        },
        {
          "numbers": [2, 3, 4],
          "target": 6,
          "expected": [1, 3]
        },
        {
          "numbers": [-1, 0],
          "target": -1,
          "expected": [1, 2]
        }
      ]
    })raw");

    for (auto &tc : j.at("cases")) {
      vector<int> numbers = tc.at("numbers").get<vector<int>>();
      int target = tc.at("target").get<int>();
      vector<int> expected = tc.at("expected").get<vector<int>>();

      Solution sol;
      vector<int> result = sol.twoSum(numbers, target);

      if (result != expected) {
        cerr << "FAIL for target " << target << " and input: [";
        for (int i = 0; i < numbers.size(); ++i) {
          cerr << numbers[i] << (i < numbers.size() - 1 ? ", " : "");
        }
        cerr << "]" << endl;
        cerr << "Expected: [";
        for (int i = 0; i < expected.size(); ++i) {
          cerr << expected[i] << (i < expected.size() - 1 ? ", " : "");
        }
        cerr << "], Got: [";
        for (int i = 0; i < result.size(); ++i) {
          cerr << result[i] << (i < result.size() - 1 ? ", " : "");
        }
        cerr << "]" << endl;
        return 1;
      }
    }
    cout << "PASS" << endl;
    return 0;
  } catch (const exception &e) {
    cerr << "Exception: " << e.what() << endl;
    return 1;
  }
}
