#include <unordered_set>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <utility>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> counts;
    for (int num : nums) {
      counts[num]++;
    }

    // Min-heap to keep top k elements
    // Pair: {frequency, number}
    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> minHeap;

    for (auto const &[num, count] : counts) {
      minHeap.push({count, num});
      if (minHeap.size() > (size_t)k) {
        minHeap.pop();
      }
    }

    std::vector<int> result;
    while (!minHeap.empty()) {
      result.push_back(minHeap.top().second);
      minHeap.pop();
    }
    return result;
  }
};
// @lc code=end

















// Wrapper for the runner





int main() {
    Solution sol;
    // Case 1
    {
        vector<int> nums = {1, 1, 1, 2, 2, 3};
        int k = 2;
        auto got = sol.topKFrequent(nums, k);
        if (got != std::vector<int>{1, 2}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<int> nums = {1};
        int k = 1;
        auto got = sol.topKFrequent(nums, k);
        if (got != std::vector<int>{1}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<int> nums = {4, 1, -1, 2, -1, 2, 3};
        int k = 2;
        auto got = sol.topKFrequent(nums, k);
        if (got != std::vector<int>{-1, 2}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
