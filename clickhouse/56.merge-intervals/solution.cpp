#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.empty()) return {};
    
    // Sort intervals by start time
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    size_t writeIdx = 0;
    for (size_t i = 1; i < intervals.size(); ++i) {
      // Check for overlap
      if (intervals[writeIdx][1] >= intervals[i][0]) {
        intervals[writeIdx][1] = max(intervals[writeIdx][1], intervals[i][1]);
      } else {
        // No overlap: increment index and move interval
        writeIdx++;
        if (writeIdx != i) {
          intervals[writeIdx] = std::move(intervals[i]);
        }
      }
    }
    
    // Shrink original vector to fit merged intervals
    intervals.resize(writeIdx + 1);
    return intervals;
  }
};
