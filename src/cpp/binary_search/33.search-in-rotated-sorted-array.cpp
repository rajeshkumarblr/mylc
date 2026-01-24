#include "../lc_test_utils.h"
#include <vector>

// Problem 33: Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) { return search_33(nums, target); }
};

int search_33(std::vector<int> &nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == target) {
      return m;
    }

    // Check if the left half is sorted
    if (nums[l] <= nums[m]) {
      if (nums[l] <= target && target < nums[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    // Otherwise, the right half must be sorted
    else {
      if (nums[m] < target && target <= nums[r]) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
  }
  return -1;
}

bool lc_test_33(const json &j) {
  std::cout << "Running LC33: Search in Rotated Sorted Array ...\n";

  std::vector<int> cases_to_run;
  if (j.contains("cases")) {
    for (size_t i = 0; i < j.at("cases").size(); ++i)
      cases_to_run.push_back(i);
  }

  bool all_passed = true;
  for (int i : cases_to_run) {
    const auto &tc = j.at("cases").at(i);
    std::vector<int> nums = tc.at("nums").get<std::vector<int>>();
    int target = tc.at("target").get<int>();
    int expected = tc.at("expected").get<int>();

    int result = search_33(nums, target);

    if (result != expected) {
      std::cout << "  Case " << i + 1 << " Failed. Expected: " << expected
                << ", Got: " << result << "\n";
      all_passed = false;
    }
  }

  return all_passed;
}
