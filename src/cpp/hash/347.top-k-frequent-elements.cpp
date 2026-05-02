#include <queue>
#include <unordered_map>
#include <vector>

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

// Wrapper for the runner
std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
  Solution sol;
  return sol.topKFrequent(nums, k);
}
