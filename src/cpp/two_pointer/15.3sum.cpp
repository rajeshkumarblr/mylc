#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * Difficulty: Medium
 * Category: two_pointer
 * URL: https://leetcode.com/problems/3sum/
 *
 * Description:
 * Given an integer array nums, return all the triplets  [nums[i], nums[j],
 * nums[k]]  such that  i != j ,  i != k , and  j != k , and  nums[i] +
 * nums[j] + nums[k] == 0 .
 *  Notice that the solution set must not contain duplicate triplets.
 *   Example 1:
 *  Input:  nums = [-1,0,1,2,-1,-4]
 *  Output:  [[-1,-1,2],[-1,0,1]]
 *  Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 *   Example 2:
 *  Input:  nums = [0,1,1]
 *  Output:  []
 *  Explanation:  The only possible triplet does not sum up to 0.
 *   Example 3:
 *  Input:  nums = [0,0,0]
 *  Output:  [[0,0,0]]
 *  Explanation:  The only possible triplet sums up to 0.
 *   Constraints:
 *           3 <= nums.length <= 3000
 *           -10 5  <= nums[i] <= 10 5
 */

#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) {
      return {};
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int l = i + 1;
      int r = nums.size() - 1;
      int target = -nums[i];
      while (l < r) {
        if (nums[l] + nums[r] == target) {
          res.push_back({nums[i], nums[l], nums[r]});
          l++;
          while (l < r && nums[l] == nums[l - 1]) {
            l++;
          }
        } else if (nums[l] + nums[r] > target) {
          r = r - 1;
        } else {
          l = l + 1;
        }
      }
    }
    return res;
  }
};
// @lc code=end

#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  try {
    json j = json::parse(R"raw({
      "cases": [
        {
          "nums": [-1,0,1,2,-1,-4],
          "expected": [[-1,-1,2],[-1,0,1]]
        },
        {
          "nums": [0,1,1],
          "expected": []
        },
        {
          "nums": [0,0,0],
          "expected": [[0,0,0]]
        }
      ]
    })raw");

    for (auto &tc : j.at("cases")) {
      vector<int> nums = tc.at("nums").get<vector<int>>();
      vector<vector<int>> expected =
          tc.at("expected").get<vector<vector<int>>>();

      Solution sol;
      vector<vector<int>> result = sol.threeSum(nums);

      // Sort inner vectors and outer vectors to ensure order-independent
      // comparison
      for (auto &vec : expected)
        sort(vec.begin(), vec.end());
      sort(expected.begin(), expected.end());

      for (auto &vec : result)
        sort(vec.begin(), vec.end());
      sort(result.begin(), result.end());

      if (result != expected) {
        cerr << "FAIL for input: [";
        for (int i = 0; i < nums.size(); ++i) {
          cerr << nums[i] << (i < nums.size() - 1 ? ", " : "");
        }
        cerr << "]" << endl;
        cerr << "Expected: [";
        for (int i = 0; i < expected.size(); ++i) {
          cerr << "[";
          for (int k = 0; k < expected[i].size(); ++k) {
            cerr << expected[i][k] << (k < expected[i].size() - 1 ? "," : "");
          }
          cerr << "]" << (i < expected.size() - 1 ? ", " : "");
        }
        cerr << "], Got: [";
        for (int i = 0; i < result.size(); ++i) {
          cerr << "[";
          for (int k = 0; k < result[i].size(); ++k) {
            cerr << result[i][k] << (k < result[i].size() - 1 ? "," : "");
          }
          cerr << "]" << (i < result.size() - 1 ? ", " : "");
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
