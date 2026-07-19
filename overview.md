# NeetCode 150 Overview

Track your interview preparation progress here.

## 📊 Progress Summary

| Category | Solved | Total | Progress |
|----------|--------|-------|----------|
| 1-D Dynamic Programming | 5 | 12 | 🟩🟩🟩🟩⬜⬜⬜⬜⬜⬜ 41% |
| 2-D Dynamic Programming | 1 | 11 | ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ 9% |
| Advanced Graphs | 0 | 6 | ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ 0% |
| Arrays & Hashing | 7 | 9 | 🟩🟩🟩🟩🟩🟩🟩⬜⬜⬜ 77% |
| Backtracking | 0 | 10 | ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ 0% |
| Binary Search | 2 | 7 | 🟩🟩⬜⬜⬜⬜⬜⬜⬜⬜ 28% |
| Bit Manipulation | 0 | 7 | ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ 0% |
| Graphs | 3 | 13 | 🟩🟩⬜⬜⬜⬜⬜⬜⬜⬜ 23% |
| Greedy | 0 | 8 | ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ 0% |
| Heap / Priority Queue | 3 | 7 | 🟩🟩🟩🟩⬜⬜⬜⬜⬜⬜ 42% |
| Intervals | 1 | 6 | 🟩⬜⬜⬜⬜⬜⬜⬜⬜⬜ 16% |
| Linked List | 5 | 11 | 🟩🟩🟩🟩⬜⬜⬜⬜⬜⬜ 45% |
| Math & Geometry | 0 | 8 | ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ 0% |
| Sliding Window | 4 | 6 | 🟩🟩🟩🟩🟩🟩⬜⬜⬜⬜ 66% |
| Stack | 2 | 6 | 🟩🟩🟩⬜⬜⬜⬜⬜⬜⬜ 33% |
| Trees | 6 | 15 | 🟩🟩🟩🟩⬜⬜⬜⬜⬜⬜ 40% |
| Tries | 1 | 3 | 🟩🟩🟩⬜⬜⬜⬜⬜⬜⬜ 33% |
| Two Pointers | 3 | 5 | 🟩🟩🟩🟩🟩🟩⬜⬜⬜⬜ 60% |
| Bonus: Concurrency (Not NeetCode 150) | 4 | 4 | 🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩 100% |
| **Total** | **47** | **154** | **🟩🟩🟩⬜⬜⬜⬜⬜⬜⬜ 30%** |

## 📚 STL Quick References

I have generated 10 heavily-commented, comprehensive C++ STL reference examples in the `src/cpp/stl/` folder to help you with standard library syntax during your practice.

You can compile and run any of them on the fly using the `./run -e <number>` command:
- `./run -e 1` : **vector** (Dynamic Array)
- `./run -e 2` : **list** (Doubly Linked List)
- `./run -e 3` : **deque** (Double-Ended Queue)
- `./run -e 4` : **queue** (FIFO)
- `./run -e 5` : **stack** (LIFO)
- `./run -e 6` : **set** (Ordered Set / Red-Black Tree)
- `./run -e 7` : **map** (Ordered Map)
- `./run -e 8` : **unordered_set** (Hash Set)
- `./run -e 9` : **unordered_map** (Hash Map - LeetCode MVP)
- `./run -e 10` : **priority_queue** (Min/Max Heap)

---

## 1-D Dynamic Programming

- [x] **[LC 70](src/cpp/dp/70.climbing-stairs.cpp)**: [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=Y0lT9Fck7qI)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      int climbStairs(int n) {
          // Base cases: 
          // 1 step -> 1 way (just climb 1)
          // 2 steps -> 2 ways (1+1 or 2)
          if (n <= 2) return n;
          
          // Dynamic Programming approach:
          // To reach step i, we can come from step (i-1) or step (i-2)
          // So: ways[i] = ways[i-1] + ways[i-2] (Fibonacci sequence!)
          
          int waysToReachPrevPrev = 1;  // ways to reach step (i-2)
          int waysToReachPrev = 2;      // ways to reach step (i-1)
          
          // Calculate ways to reach each step from 3 to n
          for (int currentStep = 3; currentStep <= n; currentStep++) {
              int waysToReachCurrent = waysToReachPrevPrev + waysToReachPrev;
              
              // Slide the window forward
              waysToReachPrevPrev = waysToReachPrev;
              waysToReachPrev = waysToReachCurrent;
          }
          
          return waysToReachPrev;  // This holds ways to reach step n
      }
  };
  ```
  </details>
- [x] **[LC 746](src/cpp/dp/746.min-cost-climbing-stairs.cpp)**: [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=ktmzAZWkEZ0)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
      int n = cost.size();
      vector<int> dp(n + 1);
      dp[0] = 0;
      dp[1] = 0;
      for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
      }
      return dp[n];
    }
  };
  ```
  </details>
- [x] **[LC 198](src/cpp/dp/198.house-robber.cpp)**: [House Robber](https://leetcode.com/problems/house-robber/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=73r3KWiEvyk)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      int rob(vector<int>& nums) {
          const int n = nums.size();
          
          // Edge cases
          if (n == 0) return 0;           // No houses
          if (n == 1) return nums[0];     // Only 1 house
          
          // Option 2: Constant Space O(1) - BEST for memory!
          // We only need the last 2 values: dp[i-2] and dp[i-1]
          int prev2 = nums[0];                    // dp[i-2] 
          int prev1 = max(nums[0], nums[1]);      // dp[i-1]
          
          for (int i = 2; i < n; i++) {
              int current = max(prev1, prev2 + nums[i]);
              prev2 = prev1;    // Slide the window
              prev1 = current;  // Slide the window
          }
          
          return prev1;  // This holds the maximum money
      }
  };
  ```
  </details>
- [x] **[LC 213](src/cpp/dp/213.house-robber-ii.cpp)**: [House Robber II](https://leetcode.com/problems/house-robber-ii/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=rWAJCfYYOvM)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      int rob(vector<int>& nums) {
          return {};
      }
  };
  ```
  </details>
- [ ] **[LC 5](src/cpp/dp/5.longest-palindromic-substring.cpp)**: [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=XYQecbcd6_c)
- [ ] **[LC 647](src/cpp/dp/647.palindromic-substrings.cpp)**: [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=4RACzI5-du8)
- [ ] **[LC 91](src/cpp/dp/91.decode-ways.cpp)**: [Decode Ways](https://leetcode.com/problems/decode-ways/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=6aEyTjOwlJU)
- [ ] **[LC 322](src/cpp/dp/322.coin-change.cpp)**: [Coin Change](https://leetcode.com/problems/coin-change/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=H9bfqozjoqs)
- [ ] **[LC 152](src/cpp/dp/152.maximum-product-subarray.cpp)**: [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=lXVy6YWFcRM)
- [x] **[LC 139](src/cpp/dp/139.word-break.cpp)**: [Word Break](https://leetcode.com/problems/word-break/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=Sx9NNgInc3A)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      bool wordBreak(string s, vector<string>& wordDict) {
          int n = s.size();
          vector<bool> dp(n + 1, false);
          dp[0] = true; // Empty string can always be broken
          
          // Convert wordDict to unordered_set for O(1) lookup
          unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
          
          for (int i = 1; i <= n; i++) {
              for (int j = 0; j < i; j++) {
                  string word = s.substr(j, i - j);
                  if (dp[j] && wordSet.find(word) != wordSet.end()) {
                      dp[i] = true;
                      break;
                  }
              }
          }
          
          return dp[n];
      }
  };
  ```
  </details>
- [ ] **[LC 300](src/cpp/dp/300.longest-increasing-subsequence.cpp)**: [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=cjWnW0hdF1Y)
- [ ] **[LC 416](src/cpp/dp/416.partition-equal-subset-sum.cpp)**: [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=IsvocB5BJhw)

## 2-D Dynamic Programming

- [ ] **[LC 62](src/cpp/dp/62.unique-paths.cpp)**: [Unique Paths](https://leetcode.com/problems/unique-paths/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=IlEsdxuD4lY)
- [ ] **[LC 1143](src/cpp/dp/1143.longest-common-subsequence.cpp)**: [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=Ua0GhsJSlWM)
- [ ] **[LC 309](src/cpp/dp/309.best-time-to-buy-and-sell-stock-with-cooldown.cpp)**: [Best Time to Buy And Sell Stock With Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=I7j0F7AHpb8)
- [ ] **[LC 518](src/cpp/dp/518.coin-change-ii.cpp)**: [Coin Change II](https://leetcode.com/problems/coin-change-ii/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=Mjy4hd2xgrs)
- [ ] **[LC 494](src/cpp/dp/494.target-sum.cpp)**: [Target Sum](https://leetcode.com/problems/target-sum/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=dwMOrl85Xes)
- [ ] **[LC 97](src/cpp/dp/97.interleaving-string.cpp)**: [Interleaving String](https://leetcode.com/problems/interleaving-string/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=3Rw3p9LrgvE)
- [ ] **[LC 329](src/cpp/dp/329.longest-increasing-path-in-a-matrix.cpp)**: [Longest Increasing Path In a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=wCc_nd-GiEc)
- [ ] **[LC 115](src/cpp/dp/115.distinct-subsequences.cpp)**: [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=-RDzMJ33nx8)
- [x] **[LC 72](src/cpp/dp/72.edit-distance.cpp)**: [Edit Distance](https://leetcode.com/problems/edit-distance/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=Sfm_b4HVEKE)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
    int minDistance(string word1, string word2) {
      int m = word1.size();
      int n = word2.size();
      
      // Create a 2D vector for DP
      vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
      
      // Base cases
      for (int i = 0; i <= m; i++) dp[i][0] = i; // Deleting characters to match empty string
      for (int j = 0; j <= n; j++) dp[0][j] = j; // Inserting characters to match word2
      
      // Fill the grid
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          if (word1[i - 1] == word2[j - 1]) {
            // Characters match, no operation needed. Copy diagonal.
            dp[i][j] = dp[i - 1][j - 1];
          } else {
            // Characters don't match, take minimum of 3 operations + 1
            dp[i][j] = min({
              dp[i - 1][j - 1], // Replace (diagonal)
              dp[i - 1][j],     // Delete (up)
              dp[i][j - 1]      // Insert (left)
            }) + 1;
          }
        }
      }
      
      return dp[m][n];
    }
  };
  ```
  </details>
- [ ] **[LC 312](src/cpp/dp/312.burst-balloons.cpp)**: [Burst Balloons](https://leetcode.com/problems/burst-balloons/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=VFskby7lUbw)
- [ ] **[LC 10](src/cpp/dp/10.regular-expression-matching.cpp)**: [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=HAA8mgxlov8)

## Advanced Graphs

- [ ] **[LC 743](src/cpp/graphs/743.network-delay-time.cpp)**: [Network Delay Time](https://leetcode.com/problems/network-delay-time/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=EaphyqKU4PQ)
- [ ] **[LC 332](src/cpp/graphs/332.reconstruct-itinerary.cpp)**: [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=ZyB_gQ8vqGA)
- [ ] **[LC 1584](src/cpp/graphs/1584.min-cost-to-connect-all-points.cpp)**: [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=f7JOBJIC-NA)
- [ ] **[LC 778](src/cpp/graphs/778.swim-in-rising-water.cpp)**: [Swim In Rising Water](https://leetcode.com/problems/swim-in-rising-water/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=amvrKlMLuGY)
- [ ] **[LC 269](src/cpp/graphs/269.alien-dictionary.cpp)**: [Alien Dictionary](https://leetcode.com/problems/alien-dictionary/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=6kTZYvNNyps)
- [ ] **[LC 787](src/cpp/graphs/787.cheapest-flights-within-k-stops.cpp)**: [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=5eIK3zUdYmE)

## Arrays & Hashing

- [x] **[LC 217](src/cpp/hash/217.contains-duplicate.cpp)**: [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=3OamzN90kPg)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
      // std::sort operates directly on the vector's contiguous memory.
      // Zero dynamic allocations = Huge savings in CPU and Memory!
      std::sort(nums.begin(), nums.end());
      
      // Check adjacent elements
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
          return true;
        }
      }
      return false;
    }
  };
  ```
  </details>
- [x] **[LC 242](src/cpp/hash/242.valid-anagram.cpp)**: [Valid Anagram](https://leetcode.com/problems/valid-anagram/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=9UtInBqnCgA)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
    bool isAnagram(string s, string t) {
      if (s.length() != t.length()) {
        return false;
      }
      
      // Since we only have lowercase English letters, a fixed array of size 26 is much 
      // faster and uses way less memory than an unordered_map (zero dynamic allocations!).
      int counts[26] = {0};
      
      // We can even do this in a single pass!
      for (int i = 0; i < s.length(); i++) {
        counts[s[i] - 'a']++;
        counts[t[i] - 'a']--;
      }
      
      // If they are anagrams, every bucket should be perfectly balanced back to 0
      for (int count : counts) {
        if (count != 0) {
          return false;
        }
      }
      
      return true;
    }
  };
  ```
  </details>
- [x] **[LC 1](src/cpp/hash/1.two-sum.cpp)**: [Two Sum](https://leetcode.com/problems/two-sum/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=KLlXCFG5TnA)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
      unordered_map<int, int> complements;
      for (int i = 0; i < nums.size(); i++) {
        if (const auto it = complements.find(nums[i]); it != complements.end()) {
          return {it->second, i};
        } else {
          complements[target - nums[i]] = i;
        }
      }
      return {};
    }
  };
  ```
  </details>
- [x] **[LC 49](src/cpp/hash/49.group-anagrams.cpp)**: [Group Anagrams](https://leetcode.com/problems/group-anagrams/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=vzdNOK2oB2E)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
      unordered_map<string, vector<string>> countsMap;
      for (auto &s : strs) {
        int counts[26] = {0};
        for (char ch : s) {
          counts[ch - 'a']++;
        }
        string key = "";
        for (int i = 0; i < 26; i++) {
          if (counts[i]) {
            char ch = 'a' + i;
            key += ch;
            key += counts[i];
          }
        }
        countsMap[key].push_back(std::move(s));
      }

      vector<vector<string>> res;
      res.reserve(countsMap.size());
      for (auto &pair : countsMap) {
        res.push_back(std::move(pair.second));
      }
      return res;
    }
  };
  ```
  </details>
- [x] **[LC 347](src/cpp/hash/347.top-k-frequent-elements.cpp)**: [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=YPTqKIgVk-k)
- [ ] **[LC 271](src/cpp/hash/271.encode-and-decode-strings.cpp)**: [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=B1k_sxOSgv8)
- [x] **[LC 238](src/cpp/hash/238.product-of-array-except-self.cpp)**: [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=bNvIQI2wAjk)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      vector<int> productExceptSelf(vector<int>& nums) {
          return {};
      }
  };
  ```
  </details>
- [x] **[LC 36](src/cpp/hash/36.valid-sudoku.cpp)**: [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=TjFXEUCMqI8)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      bool isValidSudoku(vector<vector<char>>& board) {
          // Use bitsets for maximum efficiency
          // Each int represents 9 digits as bits
          int rows[9] = {0};
          int cols[9] = {0}; 
          int boxes[9] = {0};
  
          for (int i = 0; i < 9; ++i) {
              for (int j = 0; j < 9; ++j) {
                  char c = board[i][j];
                  if (c == '.') continue;
  
                  int bit = 1 << (c - '1'); // Create bit mask for digit
                  int box = (i / 3) * 3 + (j / 3);
  
                  // Check if bit is already set (duplicate found)
                  if ((rows[i] & bit) || (cols[j] & bit) || (boxes[box] & bit))
                      return false;
  
                  // Set the bit
                  rows[i] |= bit;
                  cols[j] |= bit;
                  boxes[box] |= bit;
              }
          }
          return true;
      }
  };
  ```
  </details>
- [ ] **[LC 128](src/cpp/hash/128.longest-consecutive-sequence.cpp)**: [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=ahysrRu0bHw)

## Backtracking

- [ ] **[LC 78](src/cpp/backtracking/78.subsets.cpp)**: [Subsets](https://leetcode.com/problems/subsets/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=REOH22Xwdkk)
- [ ] **[LC 39](src/cpp/backtracking/39.combination-sum.cpp)**: [Combination Sum](https://leetcode.com/problems/combination-sum/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=GBKI9VSKdGg)
- [ ] **[LC 40](src/cpp/backtracking/40.combination-sum-ii.cpp)**: [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=rSA3t6BDDwg)
- [ ] **[LC 46](src/cpp/backtracking/46.permutations.cpp)**: [Permutations](https://leetcode.com/problems/permutations/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=KPgQQWSqss4)
- [ ] **[LC 90](src/cpp/backtracking/90.subsets-ii.cpp)**: [Subsets II](https://leetcode.com/problems/subsets-ii/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=Vn2v6ajA7U0)
- [ ] **[LC 22](src/cpp/backtracking/22.generate-parentheses.cpp)**: [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=s9fokUqJ76A)
- [ ] **[LC 79](src/cpp/backtracking/79.word-search.cpp)**: [Word Search](https://leetcode.com/problems/word-search/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=pfiQ_PS1g8E)
- [ ] **[LC 131](src/cpp/backtracking/131.palindrome-partitioning.cpp)**: [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=YKEU-dhqKmA)
- [ ] **[LC 17](src/cpp/backtracking/17.letter-combinations-of-a-phone-number.cpp)**: [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=0snEunUacZY)
- [ ] **[LC 51](src/cpp/backtracking/51.n-queens.cpp)**: [N Queens](https://leetcode.com/problems/n-queens/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=Ph95IHmRp5M)

## Binary Search

- [ ] **[LC 704](src/cpp/binary_search/704.binary-search.cpp)**: [Binary Search](https://leetcode.com/problems/binary-search/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=s4DPM8ct1pI)
- [ ] **[LC 74](src/cpp/binary_search/74.search-a-2d-matrix.cpp)**: [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=Ber2pi2C0j0)
- [ ] **[LC 875](src/cpp/binary_search/875.koko-eating-bananas.cpp)**: [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=U2SozAs9RzA)
- [ ] **[LC 153](src/cpp/binary_search/153.find-minimum-in-rotated-sorted-array.cpp)**: [Find Minimum In Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=nIVW4P8b1VA)
- [x] **[LC 33](src/cpp/binary_search/33.search-in-rotated-sorted-array.cpp)**: [Search In Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=U8XENwh8Oy8)
- [x] **[LC 981](src/cpp/binary_search/981.time-based-key-value-store.cpp)**: [Time Based Key Value Store](https://leetcode.com/problems/time-based-key-value-store/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=fu2cD_6E8Hw)
  <details><summary>View Solution</summary>
  
  ```cpp
  class TimeMap {
  private:
    unordered_map<string, vector<Data>> store;
  
  public:
    TimeMap() : store() {}
  
    void set(string key, string value, int timestamp) {
      store[key].push_back({timestamp, value});
    }
  
    string get(string key, int timestamp) {
      // check if the key is available in store first
      auto it = store.find(key);
      if (it == store.end()) {
        return "";
      }
  
      // key is available, get the values vector.
      const auto &values = it->second;
  
      // custom comparator for finding timestamp.
      auto cmp = [](int ts, const Data &data) { return ts < data.timestamp; };
  
      // upper_bound finds the first element strictly greater than timestamp
      auto upper = upper_bound(values.begin(), values.end(), timestamp, cmp);
  
      // If upper is at the beginning, all timestamps are strictly greater than
      // the target
      if (upper == values.begin()) {
        return "";
      }
  
      // The element just before upper has a timestamp <= target
      return prev(upper)->val;
    }
  };
  
  /**
   * Your TimeMap object will be instantiated and called as such:
   * TimeMap* obj = new TimeMap();
   * obj->set(key,value,timestamp);
   * string param_2 = obj->get(key,timestamp);
   */
  ```
  </details>
- [ ] **[LC 4](src/cpp/binary_search/4.median-of-two-sorted-arrays.cpp)**: [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=q6IEA26hvXc)

## Bit Manipulation

- [ ] **[LC 136](src/cpp/bit_manipulation/136.single-number.cpp)**: [Single Number](https://leetcode.com/problems/single-number/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=qMPX1AOa83k)
- [ ] **[LC 191](src/cpp/bit_manipulation/191.number-of-1-bits.cpp)**: [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=5Km3utixwZs)
- [ ] **[LC 338](src/cpp/bit_manipulation/338.counting-bits.cpp)**: [Counting Bits](https://leetcode.com/problems/counting-bits/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=RyBM56RIWrM)
- [ ] **[LC 190](src/cpp/bit_manipulation/190.reverse-bits.cpp)**: [Reverse Bits](https://leetcode.com/problems/reverse-bits/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=UcoN6UjAI64)
- [ ] **[LC 268](src/cpp/bit_manipulation/268.missing-number.cpp)**: [Missing Number](https://leetcode.com/problems/missing-number/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=WnPLSRLSANE)
- [ ] **[LC 371](src/cpp/bit_manipulation/371.sum-of-two-integers.cpp)**: [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=gVUrDV4tZfY)
- [ ] **[LC 7](src/cpp/bit_manipulation/7.reverse-integer.cpp)**: [Reverse Integer](https://leetcode.com/problems/reverse-integer/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=HAgLH58IgJQ)

## Graphs

- [x] **[LC 200](src/cpp/graphs/200.number-of-islands.cpp)**: [Number of Islands](https://leetcode.com/problems/number-of-islands/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=pV2kpPD66nE)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      int numIslands(vector<vector<char>>& grid) {
          if (grid.empty() || grid[0].empty()) return 0;
          
          int rows = grid.size();
          int cols = grid[0].size();
          int count = 0;
          
          for (int i = 0; i < rows; ++i) {
              for (int j = 0; j < cols; ++j) {
                  if (grid[i][j] == '1') {
                      count++;
                      dfs(grid, i, j);
                  }
              }
          }
          
          return count;
      }
      
  private:
      void dfs(vector<vector<char>>& grid, int i, int j) {
          if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
              return;
          }
          
          grid[i][j] = '0'; // Mark as visited
          
          // Visit all 4 directions
          dfs(grid, i + 1, j);
          dfs(grid, i - 1, j);
          dfs(grid, i, j + 1);
          dfs(grid, i, j - 1);
      }
  };
  ```
  </details>
- [ ] **[LC 695](src/cpp/graphs/695.max-area-of-island.cpp)**: [Max Area of Island](https://leetcode.com/problems/max-area-of-island/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=iJGr1OtmH0c)
- [ ] **[LC 133](src/cpp/graphs/133.clone-graph.cpp)**: [Clone Graph](https://leetcode.com/problems/clone-graph/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=mQeF6bN8hMk)
- [ ] **[LC 286](src/cpp/graphs/286.walls-and-gates.cpp)**: [Walls And Gates](https://leetcode.com/problems/walls-and-gates/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=e69C6xhiSQE)
- [ ] **[LC 994](src/cpp/graphs/994.rotting-oranges.cpp)**: [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=y704fEOx0s0)
- [ ] **[LC 417](src/cpp/graphs/417.pacific-atlantic-water-flow.cpp)**: [Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=s-VkcjHqkGI)
- [ ] **[LC 130](src/cpp/graphs/130.surrounded-regions.cpp)**: [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=9z2BunfoZ5Y)
- [x] **[LC 207](src/cpp/graphs/207.course-schedule.cpp)**: [Course Schedule](https://leetcode.com/problems/course-schedule/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=EgI5nU9etnU)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          return {};
      }
  };
  ```
  </details>
- [x] **[LC 210](src/cpp/graphs/210.course-schedule-ii.cpp)**: [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=Akt3glAwyfY)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          return {};
      }
  };
  ```
  </details>
- [ ] **[LC 261](src/cpp/graphs/261.graph-valid-tree.cpp)**: [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=bXsUuownnoQ)
- [ ] **[LC 323](src/cpp/graphs/323.number-of-connected-components-in-an-undirected-graph.cpp)**: [Number of Connected Components In An Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=8f1XPm4WOUc)
- [ ] **[LC 684](src/cpp/graphs/684.redundant-connection.cpp)**: [Redundant Connection](https://leetcode.com/problems/redundant-connection/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=1lNK80tOTfc)
- [ ] **[LC 127](src/cpp/graphs/127.word-ladder.cpp)**: [Word Ladder](https://leetcode.com/problems/word-ladder/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=h9iTnkgv05E)

## Greedy

- [ ] **[LC 53](src/cpp/greedy/53.maximum-subarray.cpp)**: [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=5WZl3MMT0Eg)
- [ ] **[LC 55](src/cpp/greedy/55.jump-game.cpp)**: [Jump Game](https://leetcode.com/problems/jump-game/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=Yan0cv2cLy8)
- [ ] **[LC 45](src/cpp/greedy/45.jump-game-ii.cpp)**: [Jump Game II](https://leetcode.com/problems/jump-game-ii/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=dJ7sWiOoK7g)
- [ ] **[LC 134](src/cpp/greedy/134.gas-station.cpp)**: [Gas Station](https://leetcode.com/problems/gas-station/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=lJwbPZGo05A)
- [ ] **[LC 846](src/cpp/greedy/846.hand-of-straights.cpp)**: [Hand of Straights](https://leetcode.com/problems/hand-of-straights/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=amnrMCVd2YI)
- [ ] **[LC 1899](src/cpp/greedy/1899.merge-triplets-to-form-target-triplet.cpp)**: [Merge Triplets to Form Target Triplet](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=kShkQLQZ9K4)
- [ ] **[LC 763](src/cpp/greedy/763.partition-labels.cpp)**: [Partition Labels](https://leetcode.com/problems/partition-labels/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=B7m8UmZE-vw)
- [ ] **[LC 678](src/cpp/greedy/678.valid-parenthesis-string.cpp)**: [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=QhPdNS143Qg)

## Heap / Priority Queue

- [ ] **[LC 703](src/cpp/heap/703.kth-largest-element-in-a-stream.cpp)**: [Kth Largest Element In a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=hOjcdrqMoQ8)
- [ ] **[LC 1046](src/cpp/heap/1046.last-stone-weight.cpp)**: [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=B-QCq79-Vfw)
- [x] **[LC 973](src/cpp/heap/973.k-closest-points-to-origin.cpp)**: [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=rI2EBUEMfTk)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          return {};
      }
  };
  ```
  </details>
- [x] **[LC 215](src/cpp/heap/215.kth-largest-element-in-an-array.cpp)**: [Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=XEmy13g1Qxc)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      int findKthLargest(vector<int>& nums, int k) {
          return {};
      }
  };
  ```
  </details>
- [ ] **[LC 621](src/cpp/heap/621.task-scheduler.cpp)**: [Task Scheduler](https://leetcode.com/problems/task-scheduler/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=s8p8ukTyA2I)
- [ ] **[LC 355](src/cpp/heap/355.design-twitter.cpp)**: [Design Twitter](https://leetcode.com/problems/design-twitter/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=pNichitDD2E)
- [x] **[LC 295](src/cpp/heap/295.find-median-from-data-stream.cpp)**: [Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=itmhHWaHupI)
  <details><summary>View Solution</summary>
  
  ```cpp
  class MedianFinder {
  public:
      MedianFinder() {
          
      }
      
      void addNum(int num) {
          
      }
      
      double findMedian() {
          
      }
  };
  
  /**
   * Your MedianFinder object will be instantiated and called as such:
   * MedianFinder* obj = new MedianFinder();
   * obj->addNum(num);
   * double param_2 = obj->findMedian();
   */
  ```
  </details>

## Intervals

- [ ] **[LC 57](src/cpp/intervals/57.insert-interval.cpp)**: [Insert Interval](https://leetcode.com/problems/insert-interval/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=A8NUOmlwOlM)
- [x] **[LC 56](src/cpp/intervals/56.merge-intervals.cpp)**: [Merge Intervals](https://leetcode.com/problems/merge-intervals/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=44H3cEC2fFM)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      vector<vector<int>> merge(vector<vector<int>>& intervals) {
          return {};
      }
  };
  ```
  </details>
- [ ] **[LC 435](src/cpp/intervals/435.non-overlapping-intervals.cpp)**: [Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=nONCGxWoUfM)
- [ ] **[LC 252](src/cpp/intervals/252.meeting-rooms.cpp)**: [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=PaJxqZVPhbg)
- [ ] **[LC 253](src/cpp/intervals/253.meeting-rooms-ii.cpp)**: [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=FdzJmTCVyJU)
- [ ] **[LC 1851](src/cpp/intervals/1851.minimum-interval-to-include-each-query.cpp)**: [Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=5hQ5WWW5awQ)

## Linked List

- [x] **[LC 206](src/cpp/list/206.reverse-linked-list.cpp)**: [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=uyTL80yvTrw)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      ListNode* reverseList(ListNode* head) {
          ListNode* prev = nullptr;
          ListNode* curr = head;
          
          while (curr != nullptr) {
              ListNode* next = curr->next;
              curr->next = prev;
              prev = curr;
              curr = next;
          }
          
          return prev;
      }
  };
  ```
  </details>
- [x] **[LC 21](src/cpp/list/21.merge-two-sorted-lists.cpp)**: [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=XIdigk956u0)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
      {
          ListNode dummy;
          dummy.next =  nullptr;
          ListNode *tail = &dummy;
          while (list1 != nullptr && list2 != nullptr) {
              if (list1->val < list2->val) {
                  tail->next = list1;
                  list1 = list1->next;
              } else {
                  tail->next = list2;
                  list2 = list2->next;
              }
              tail = tail->next;
          }
  
          if (list1 != nullptr) {
              tail->next = list1;
          } else {
              tail->next = list2;
          }
          return dummy.next;
      }
  };
  ```
  </details>
- [x] **[LC 141](src/cpp/list/141.linked-list-cycle.cpp)**: [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=gBTe7lFR3vc)
  <details><summary>View Solution</summary>
  
  ```cpp
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     ListNode *next;
   *     ListNode(int x) : val(x), next(NULL) {}
   * };
   */
  class Solution {
  public:
    bool hasCycle(ListNode *head) {
      ListNode *slow = head, *fast = head;
  
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
          return true;
        }
      }
      return false;
    }
  };
  ```
  </details>
- [ ] **[LC 143](src/cpp/list/143.reorder-list.cpp)**: [Reorder List](https://leetcode.com/problems/reorder-list/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=S5bfdUTrKLM)
- [ ] **[LC 19](src/cpp/list/19.remove-nth-node-from-end-of-list.cpp)**: [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=XVuQxVej6y8)
- [ ] **[LC 138](src/cpp/list/138.copy-list-with-random-pointer.cpp)**: [Copy List With Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=5Y2EiZST97Y)
- [x] **[LC 2](src/cpp/list/2.add-two-numbers.cpp)**: [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=wgFPrzTjm7s)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode dummy;
          ListNode* tail = &dummy;
          int carry = 0;
          while (l1 || l2 || carry) {
              int sum = carry;
              if (l1) { sum += l1->val; l1 = l1->next; }
              if (l2) { sum += l2->val; l2 = l2->next; }
              tail->next = new ListNode(sum % 10);
              tail = tail->next;
              carry = sum / 10;
          }
          return dummy.next;
      }
  };
  ```
  </details>
- [ ] **[LC 287](src/cpp/list/287.find-the-duplicate-number.cpp)**: [Find The Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=wjYnzkAhcNk)
- [x] **[LC 146](src/cpp/list/146.lru-cache.cpp)**: [LRU Cache](https://leetcode.com/problems/lru-cache/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=7ABFKPK2hD4)
  <details><summary>View Solution</summary>
  
  ```cpp
  class LRUCache {
  public:
      LRUCache(int capacity) {
          
      }
      
      int get(int key) {
          return -1;
      }
      
      void put(int key, int value) {
          
      }
  };
  
  /**
   * Your LRUCache object will be instantiated and called as such:
   * LRUCache* obj = new LRUCache(capacity);
   * int param_1 = obj->get(key);
   * obj->put(key,value);
   */
  ```
  </details>
- [ ] **[LC 23](src/cpp/list/23.merge-k-sorted-lists.cpp)**: [Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=q5a5OiGbT6Q)
- [ ] **[LC 25](src/cpp/list/25.reverse-nodes-in-k-group.cpp)**: [Reverse Nodes In K Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=1UOPsfP85V4)

## Math & Geometry

- [ ] **[LC 48](src/cpp/math/48.rotate-image.cpp)**: [Rotate Image](https://leetcode.com/problems/rotate-image/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=fMSJSS7eO1w)
- [ ] **[LC 54](src/cpp/math/54.spiral-matrix.cpp)**: [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=BJnMZNwUk1M)
- [ ] **[LC 73](src/cpp/math/73.set-matrix-zeroes.cpp)**: [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=T41rL0L3Pnw)
- [ ] **[LC 202](src/cpp/math/202.happy-number.cpp)**: [Happy Number](https://leetcode.com/problems/happy-number/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=HtO5NTmFHR0)
- [ ] **[LC 66](src/cpp/math/66.plus-one.cpp)**: [Plus One](https://leetcode.com/problems/plus-one/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=FSZx33537oU)
- [ ] **[LC 50](src/cpp/math/50.powx-n.cpp)**: [Pow(x, n)](https://leetcode.com/problems/powx-n/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=g9YQyYi4IQQ)
- [ ] **[LC 43](src/cpp/math/43.multiply-strings.cpp)**: [Multiply Strings](https://leetcode.com/problems/multiply-strings/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=1IsHMY1r7dc)
- [ ] **[LC 2013](src/cpp/math/2013.detect-squares.cpp)**: [Detect Squares](https://leetcode.com/problems/detect-squares/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=bahebearrDc)

## Sliding Window

- [ ] **[LC 121](src/cpp/sliding_window/121.best-time-to-buy-and-sell-stock.cpp)**: [Best Time to Buy And Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=1pkOgXD63yU)
- [x] **[LC 3](src/cpp/sliding_window/3.longest-substring-without-repeating-characters.cpp)**: [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=wiGpQwVHdE0)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      size_t i = 0;
      int l = 0;
      int maxlen = 0;
      unordered_map<char, int> charind;
      while (i < s.size()) {
        char ch = s[i];
        if (charind.count(ch) && charind[ch] >= l) {
          l = charind[ch] + 1;
        }
        charind[ch] = i;
        int wind = i - l + 1;
        maxlen = std::max(maxlen, wind);
        i++;
      }
      return maxlen;
    }
  };
  ```
  </details>
- [x] **[LC 424](src/cpp/sliding_window/424.longest-repeating-character-replacement.cpp)**: [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=gqXU1UyA8pk)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution
  {
  public:
      int characterReplacement(string s, int k)
      {
          return characterReplacement_vector(s,k);
          //return characterReplacement_map(s,k);
      }
  
      int characterReplacement_vector(string s, int k)
      {
          vector<int> cnt(26, 0);
          int l = 0, best = 0, maxCount = 0;
  
          for (int r = 0; r < (int)s.size(); ++r)
          {
              int idx = s[r] - 'A';
              maxCount = max(maxCount, ++cnt[idx]);
  
              // enforce: window size - most frequent char count <= k
              while ((r - l + 1) - maxCount > k)
              {
                  cnt[s[l] - 'A']--;
                  l++;
              }
  
              best = max(best, r - l + 1);
          }
          return best;
      }
  
      int characterReplacement_map(string s, int k)
      {
          map<char, int> charFreq;
          int l = 0, r = 0, best = 0, maxCount = 0;
  
          for (const auto &ch : s)
          {
              charFreq[ch]++;
              maxCount = max(maxCount, charFreq[ch]);
  
              // enforce: window size - most frequent char count <= k
              if ((r - l + 1) - maxCount > k)
              {
                  charFreq[s[l]]--;
                  l++;
              }
  
              best = max(best, r - l + 1);
              r++;
          }
          return best;
      }
  };
  ```
  </details>
- [x] **[LC 567](src/cpp/sliding_window/567.permutation-in-string.cpp)**: [Permutation In String](https://leetcode.com/problems/permutation-in-string/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=UbyhOgBN834)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      bool checkInclusion(string s1, string s2) {
          return checkInclusion_vector(s1,s2);
          //return checkInclusion_map(s1,s2);
      }
      bool checkInclusion_vector(string s1, string s2) {
          if (s1.size() > s2.size()) return false;
          vector<int> count1(26, 0), count2(26, 0);
          for (char c : s1) count1[c - 'a']++;
          for (int i = 0; i < (int)s1.size(); ++i) count2[s2[i] - 'a']++;
          if (count1 == count2) return true;
          for (int i = (int)s1.size(); i < (int)s2.size(); ++i) {
              count2[s2[i] - 'a']++;
              count2[s2[i - s1.size()] - 'a']--;
              if (count1 == count2) return true;
          }
          return false;
      }
      
      bool checkInclusion_map(string s1, string s2) {
          map<char,int> s1Map, s2Map;
          for (const auto& c:s1) {
              s1Map[c]++;
          }
  
          int left = 0;
          int windowLen = (int)s1.length();
          for (auto right = 0; right <(int)s2.length(); right++) {
  
              auto nextChar = s2[right];
              s2Map[nextChar]++;
  
              int curWindowLen = right - left + 1;
              if (curWindowLen < windowLen) {
                  continue;
              } else  if ( (curWindowLen == windowLen) && (s1Map == s2Map) ) {
                  return true;
              }
  
              auto prevChar = s2[left];
              s2Map[prevChar]--;
              if (s2Map[prevChar] == 0)
              {
                  s2Map.erase(prevChar);
              }
  
  
              left++;
          }
          return (s1Map == s2Map);
      }
  };
  ```
  </details>
- [x] **[LC 76](src/cpp/sliding_window/76.minimum-window-substring.cpp)**: [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=jSto0O4AJbM)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
    string minWindow(string s, string t) {
      if (s.empty() || t.empty())
        return "";
  
      unordered_map<char, int> dictT;
      for (char c : t)
        dictT[c]++;
  
      int required = dictT.size();
      int l = 0, r = 0;
      int formed = 0;
      unordered_map<char, int> windowCounts;
  
      int ans[3] = {-1, 0, 0}; // length, left, right
  
      while (r < s.length()) {
        char c = s[r];
        windowCounts[c]++;
  
        if (dictT.count(c) && windowCounts[c] == dictT[c]) {
          formed++;
        }
  
        while (l <= r && formed == required) {
          c = s[l];
          if (ans[0] == -1 || r - l + 1 < ans[0]) {
            ans[0] = r - l + 1;
            ans[1] = l;
            ans[2] = r;
          }
  
          windowCounts[c]--;
          if (dictT.count(c) && windowCounts[c] < dictT[c]) {
            formed--;
          }
          l++;
        }
        r++;
      }
  
      return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
  };
  ```
  </details>
- [ ] **[LC 239](src/cpp/sliding_window/239.sliding-window-maximum.cpp)**: [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=DfljaUwZsOk)

## Stack

- [x] **[LC 20](src/cpp/stack/20.valid-parentheses.cpp)**: [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=WTzjTskDFMg)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
    bool isValid(string s) {
      stack<char> st;
      for (auto ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
          st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
          if (st.empty())
            return false; // No matching opening bracket
          char ctop = st.top();
          st.pop();
          if ((ch == ')' && ctop != '(') || (ch == '}' && ctop != '{') ||
              (ch == ']' && ctop != '[')) {
            return false;
          }
        }
      }
      return st.empty(); // All brackets should be matched
    }
  };
  ```
  </details>
- [ ] **[LC 155](src/cpp/stack/155.min-stack.cpp)**: [Min Stack](https://leetcode.com/problems/min-stack/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=qkLl7nAwDPo)
- [ ] **[LC 150](src/cpp/stack/150.evaluate-reverse-polish-notation.cpp)**: [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=iu0082c4HDE)
- [x] **[LC 739](src/cpp/stack/739.daily-temperatures.cpp)**: [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=cTBiBSnjO3c)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      vector<int> dailyTemperatures(vector<int>& temperatures) {
          vector<int> out(temperatures.size(),0);
  
          stack<int> maxTemps;
          for (int ind = 0; ind < (int)temperatures.size(); ind++) {
              while (!maxTemps.empty() && temperatures[ind] > temperatures[maxTemps.top()]) {
                  out[maxTemps.top()] = ind - maxTemps.top();
                  maxTemps.pop();
              }
              maxTemps.push(ind);
          }
          return out;
      }
  };
  ```
  </details>
- [ ] **[LC 853](src/cpp/stack/853.car-fleet.cpp)**: [Car Fleet](https://leetcode.com/problems/car-fleet/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=Pr6T-3yB9RM)
- [ ] **[LC 84](src/cpp/stack/84.largest-rectangle-in-histogram.cpp)**: [Largest Rectangle In Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=zx5Sw9130L0)

## Trees

- [x] **[LC 226](src/cpp/tree/226.invert-binary-tree.cpp)**: [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=OnSn2XEQ4MY)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      TreeNode* invertTree(TreeNode* root) {
          if (root == nullptr) return nullptr;
          
          // Swap left and right children
          TreeNode* temp = root->left;
          root->left = root->right;
          root->right = temp;
          
          // Recursively invert left and right subtrees
          invertTree(root->left);
          invertTree(root->right);
          
          return root;
      }
  };
  ```
  </details>
- [x] **[LC 104](src/cpp/tree/104.maximum-depth-of-binary-tree.cpp)**: [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=hTM3phVI6YQ)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      int maxDepth(TreeNode* root) {
          return maxDepth_bfs(root);
          //return maxDepth_recursive(root);
          //return maxDepth_dfs(root);
      }
  
      int maxDepth_dfs(TreeNode* root) {
          if (!root) return 0;
  
          stack<pair<TreeNode*,int>> st;
          st.push({root, 1});
          int depth = 0;
  
          while (!st.empty()) {
              auto [node, d] = st.top(); st.pop();
              depth = max(depth, d);
              if (node->left) st.push({node->left, d+1});
              if (node->right) st.push({node->right, d+1});
          }
          return depth;
      }
  
      int maxDepth_bfs(TreeNode* root) {
          if (!root) return 0;
          
          queue<TreeNode*> q;
          q.push(root);
          int depth = 0;
          
          while (!q.empty()) {
              int levelSize = q.size();  // Current level's node count
              depth++;                   // Increment depth for each level
              
              // Process all nodes in current level
              for (int i = 0; i < levelSize; i++) {
                  TreeNode* node = q.front(); 
                  q.pop();
                  
                  // Add children to queue for next level
                  if (node->left) q.push(node->left);
                  if (node->right) q.push(node->right);
              }
          }
          
          return depth;
      }
  
      int maxDepth_recursive(TreeNode* root) {
          if (!root) return 0;                       // base: empty subtree has depth 0
          return 1 + max(maxDepth_recursive(root->left),       // child depth
                         maxDepth_recursive(root->right));     // +1 for the current node
      }
  };
  ```
  </details>
- [ ] **[LC 543](src/cpp/tree/543.diameter-of-binary-tree.cpp)**: [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=K81C31ytOZE)
- [x] **[LC 110](src/cpp/tree/110.balanced-binary-tree.cpp)**: [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=QfJsau0ItOY)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      bool isBalanced(TreeNode* root) {
          return height(root) != -1;
      }
  
      int height(TreeNode* node) {
          if (!node) return 0;
          int L = height(node->left);   if (L == -1) return -1;
          int R = height(node->right);  if (R == -1) return -1;  
          if (abs(L - R) > 1) return -1;      
          return 1 + max(L,R);
      }
  };
  ```
  </details>
- [x] **[LC 100](src/cpp/tree/100.same-tree.cpp)**: [Same Tree](https://leetcode.com/problems/same-tree/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=vRbbcKXCxOw)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
  
      bool isSameTree(TreeNode* p, TreeNode* q) {
          if (!p && !q) return true;
          else if (!p || !q) return false;
          else if (p->val != q->val) return false;
  
          return (isSameTree(p->left, q->left)  &&
                  isSameTree(p->right, q->right));
      }
  };
  ```
  </details>
- [ ] **[LC 572](src/cpp/tree/572.subtree-of-another-tree.cpp)**: [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=E36O5SWp-LE)
- [ ] **[LC 235](src/cpp/tree/235.lowest-common-ancestor-of-a-binary-search-tree.cpp)**: [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=gs2LMfuOR9k)
- [x] **[LC 102](src/cpp/tree/102.binary-tree-level-order-traversal.cpp)**: [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=6ZnyEApgFYg)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      vector<vector<int>> levelOrder(TreeNode* root) {
          vector<vector<int>> res;
          if (!root) return res; // empty => [] not [[]]
          queue<TreeNode*> q;
          q.push(root);
          while (!q.empty()) {
              int n = q.size();
              vector<int> level;
              level.reserve(n);
              for (int i = 0; i < n; ++i) {
                  TreeNode* node = q.front(); q.pop();
                  level.push_back(node->val);
                  if (node->left) q.push(node->left);
                  if (node->right) q.push(node->right);
              }
              res.push_back(std::move(level));
          }
          return res;
      }
  };
  ```
  </details>
- [ ] **[LC 199](src/cpp/tree/199.binary-tree-right-side-view.cpp)**: [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=d4zLyf32e3I)
- [ ] **[LC 1448](src/cpp/tree/1448.count-good-nodes-in-binary-tree.cpp)**: [Count Good Nodes In Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=7cp5imvDzl4)
- [x] **[LC 98](src/cpp/tree/98.validate-binary-search-tree.cpp)**: [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=s6ATEkipzow)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      bool isValidBST(TreeNode* root) {
          if (!root) return true;
          if (!root->left && !root->right) return true;
          return isValidBSTRange(root,LONG_MIN, LONG_MAX);
      }
  
      bool isValidBSTRange(TreeNode* root, long min, long max)
      {
          if (!root) return true;
          return ((root->val > min && root->val < max)
              && isValidBSTRange(root->left, min, root->val)
              && isValidBSTRange(root->right, root->val, max));
      }
  };
  ```
  </details>
- [ ] **[LC 230](src/cpp/tree/230.kth-smallest-element-in-a-bst.cpp)**: [Kth Smallest Element In a Bst](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=5LUXSvjmGCw)
- [ ] **[LC 105](src/cpp/tree/105.construct-binary-tree-from-preorder-and-inorder-traversal.cpp)**: [Construct Binary Tree From Preorder And Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=ihj4IQGZ2zc)
- [ ] **[LC 124](src/cpp/tree/124.binary-tree-maximum-path-sum.cpp)**: [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=Hr5cWUld4vU)
- [ ] **[LC 297](src/cpp/tree/297.serialize-and-deserialize-binary-tree.cpp)**: [Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=u4JAi2JJhI8)

## Tries

- [ ] **[LC 208](src/cpp/trie/208.implement-trie-prefix-tree.cpp)**: [Implement Trie Prefix Tree](https://leetcode.com/problems/implement-trie-prefix-tree/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=oobqoCJlHA0)
- [x] **[LC 211](src/cpp/trie/211.design-add-and-search-words-data-structure.cpp)**: [Design Add And Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=BTf05gs_8iU)
  <details><summary>View Solution</summary>
  
  ```cpp
  class WordDictionary {
    struct TrieNode {
      TrieNode *children[26];
      bool isWord;
      TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
          children[i] = nullptr;
        }
      }
    };
  
    TrieNode *root;
  
  public:
    WordDictionary() { root = new TrieNode(); }
  
    void addWord(string word) {
      TrieNode *curr = root;
      for (char c : word) {
        int idx = c - 'a';
        if (curr->children[idx] == nullptr) {
          curr->children[idx] = new TrieNode();
        }
        curr = curr->children[idx];
      }
      curr->isWord = true;
    }
  
    bool searchHelper(string &word, int index, TrieNode *curr) {
      if (index == word.size()) {
        return curr->isWord;
      }
      char ch = word[index];
  
      if (ch == '.') {
        for (int i = 0; i < 26; i++) {
          if (curr->children[i] != nullptr) {
            if (searchHelper(word, index + 1, curr->children[i])) {
              return true;
            }
          }
        }
      } else {
        int ind = ch - 'a';
        if (curr->children[ind] != nullptr) {
          return searchHelper(word, index + 1, curr->children[ind]);
        }
      }
      return false;
    }
  
    bool search(string word) { return searchHelper(word, 0, root); }
  };
  
  /**
   * Your WordDictionary object will be instantiated and called as such:
   * WordDictionary* obj = new WordDictionary();
   * obj->addWord(word);
   * bool param_2 = obj->search(word);
   */
  ```
  </details>
- [ ] **[LC 212](src/cpp/trie/212.word-search-ii.cpp)**: [Word Search II](https://leetcode.com/problems/word-search-ii/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=asbcE9mZz_U)

## Two Pointers

- [ ] **[LC 125](src/cpp/two_pointer/125.valid-palindrome.cpp)**: [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) 🟢
  [🎬 Video](https://www.youtube.com/watch?v=jJXJ16kPFWg)
- [ ] **[LC 167](src/cpp/two_pointer/167.two-sum-ii-input-array-is-sorted.cpp)**: [Two Sum II Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=cQ1Oz4ckceM)
- [x] **[LC 15](src/cpp/two_pointer/15.3sum.cpp)**: [3Sum](https://leetcode.com/problems/3sum/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=jzZsG8n2R9A)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      vector<vector<int>> threeSum(vector<int>& nums) {
          return {};
      }
  };
  ```
  </details>
- [x] **[LC 11](src/cpp/two_pointer/11.container-with-most-water.cpp)**: [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=UuiTKBwPgAo)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      int maxArea(vector<int>& height) {
          int l = 0, r = (int)height.size() - 1, ans = 0;
          while (l < r) {
              ans = max(ans, (r - l) * min(height[l], height[r]));
              if (height[l] < height[r]) ++l;
              else --r;
          }
          return ans;
      }
  };
  ```
  </details>
- [x] **[LC 42](src/cpp/two_pointer/42.trapping-rain-water.cpp)**: [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) 🔴
  [🎬 Video](https://www.youtube.com/watch?v=ZI2z5pq0TqA)
  <details><summary>View Solution</summary>
  
  ```cpp
  class Solution {
  public:
      int trap(vector<int>& height) {
          int len = (int)height.size();
          if (len <=2) return 0;
  
          int l = 0, r = len - 1, res = 0;
  
          //initialize the leftMax to the leftmost array item.
          int leftMax = height[l];
  
          //initialize the rightMax to the rightMost array item.
          int rightMax = height[r];
  
          // Loop until left and right cross over.
      while (l < r) {
  
              // If the current max left we have seen  is lesser
              // than the current max right, then increment left.
              // we get the water in current position by subtracting
              // the height of current item from leftmax, because leftMax
              // is lesser than the right side's max, we only need that
              // to calculate. the same logic applies for the right side as well.
              if (leftMax < rightMax) {
                  l++;
                  leftMax = max(leftMax, height[l]);
                  res += leftMax - height[l];
              } else {
                  r--;
                  rightMax = max(rightMax, height[r]);
                  res += rightMax - height[r];
              }
          }
          return res;
      }
  
      int trap_minmax(vector<int>& height) {
          int len = (int)height.size();
          /* At least 3 elements must be there to trap rain water.*/
          if (len <=2) return 0;
  
          // Fill maxLeft
          vector<int> maxLeft(len,0);
          int maxL = height[0];
          for (int i = 1; i < len; i++) {
              maxL = std::max(maxL, height[i]);
              maxLeft[i] = maxL;
          }
  
          // Fill maxRight
          vector<int> maxRight(len,0);
          int maxR = height[len - 1];
          for (int i = len - 2; i >= 0; i--) {
              maxR = std::max(maxR, height[i]);
              maxRight[i] = maxR;
          }
  
          // Now calculate the trapped rain water based on the max left and max right.
          int res = 0;
          for (int i=1; i<len; i++) {
              res += max (0,(min(maxLeft[i], maxRight[i]) - height[i]));
          }
          return res;
      }
  };
  ```
  </details>

## Bonus: Concurrency (Not NeetCode 150)

- [x] **[LC 362](src/cpp/concurrency/362.design-hit-counter.cpp)**: [Design Hit Counter](https://leetcode.com/problems/design-hit-counter/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=MKihMUdG3O8)
  <details><summary>View Solution</summary>
  
  ```cpp
  #include <mutex>
  
  class HitCounter {
  private:
    vector<int> times;
    vector<int> hits;
    mutex mtx;
  
  public:
    HitCounter() : times(300, 0), hits(300, 0) {}
  
    void hit(int timestamp) {
      lock_guard<mutex> lock(mtx);
      int idx = timestamp % 300;
      if (times[idx] != timestamp) {
        times[idx] = timestamp;
        hits[idx] = 1;
      } else {
        hits[idx]++;
      }
    }
  
    int getHits(int timestamp) {
      lock_guard<mutex> lock(mtx);
      int total = 0;
      for (int i = 0; i < 300; ++i) {
        if (timestamp - times[i] < 300) {
          total += hits[i];
        }
      }
      return total;
    }
  };
  ```
  </details>
- [x] **[LC 1188](src/cpp/concurrency/1188.bounded-blocking-queue.cpp)**: [Design Bounded Blocking Queue](https://leetcode.com/problems/bounded-blocking-queue/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=p4PnZjKqZpc)
  <details><summary>View Solution</summary>
  
  ```cpp
  class BoundedBlockingQueue {
  private:
    // TODO: Add member variables for synchronization (mutexes, condition
    // variables) and storage
    std::vector<int> q;
    std::mutex mtx;
    std::condition_variable cv_full, cv_empty;
    int capacity;
    int sz;
  
  public:
    BoundedBlockingQueue(int capacity) {
      // TODO: Initialize your queue and capacity
      this->capacity = capacity;
      sz = 0;
    }
  
    void enqueue(int element) {
      // TODO: Implement thread-safe enqueue with blocking when full
      std::unique_lock<std::mutex> lck(mtx);
      cv_full.wait(lck, [this] { return sz < capacity; });
      q.push_back(element);
      ++sz;
      cv_empty.notify_one();
    }
  
    int dequeue() {
      // TODO: Implement thread-safe dequeue with blocking when empty
      std::unique_lock<std::mutex> lck(mtx);
      cv_empty.wait(lck, [this] { return sz > 0; });
      int val = q.front();
      q.erase(q.begin());
      --sz;
      cv_full.notify_one();
      return val;
    }
  
    int size() {
      // TODO: Implement thread-safe size query
      std::unique_lock<std::mutex> lck(mtx);
      return sz;
    }
  };
  ```
  </details>
- [x] **[LC 1117](src/cpp/concurrency/1117.building-h2o.cpp)**: [Building H2O](https://leetcode.com/problems/building-h2o/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=vMVA1HcTjno)
  <details><summary>View Solution</summary>
  
  ```cpp
  class H2O {
  private:
    std::counting_semaphore<2> h_sem{2};
    std::counting_semaphore<2> o_sem{0};
    std::binary_semaphore o_mutex{1};
  
  public:
    H2O() {}
  
    void hydrogen(function<void()> releaseHydrogen) {
      h_sem.acquire();
      releaseHydrogen();
      o_sem.release();
    }
  
    void oxygen(function<void()> releaseOxygen) {
      o_mutex.acquire();
      o_sem.acquire();
      o_sem.acquire();
      o_mutex.release();
  
      releaseOxygen();
      h_sem.release(2);
    }
  };
  ```
  </details>
- [x] **[LC 1242](src/cpp/concurrency/1242.web-crawler-multithreaded.cpp)**: [Web Crawler Multithreaded](https://leetcode.com/problems/web-crawler-multithreaded/) 🟡
  [🎬 Video](https://www.youtube.com/watch?v=4jVu1E2SCE4)
  <details><summary>View Solution</summary>
  
  ```cpp
  // This is the HtmlParser's API interface.
  // You should not implement it, or speculate about its implementation
  class HtmlParser {
  private:
    unordered_map<string, vector<string>> adj;
  public:
    HtmlParser() {}
    HtmlParser(const unordered_map<string, vector<string>>& graph) : adj(graph) {}
  
    vector<string> getUrls(string url) const {
      auto it = adj.find(url);
      if (it != adj.end()) {
        return it->second;
      }
      return {};
    }
  };
  
  class Solution {
  private:
    string getHostname(const string& url) {
      size_t pos = url.find("//");
      if (pos == string::npos) return "";
      size_t start = pos + 2;
      size_t end = url.find('/', start);
      if (end == string::npos) {
        return url.substr(start);
      }
      return url.substr(start, end - start);
    }
  
  public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
      string hostname = getHostname(startUrl);
  
      mutex mtx;
      condition_variable cv;
      queue<string> q;
      unordered_set<string> visited;
      int active_workers = 0;
      bool done = false;
  
      q.push(startUrl);
      visited.insert(startUrl);
  
      auto worker = [&]() {
        while (true) {
          string url;
          {
            unique_lock<mutex> lock(mtx);
            while (q.empty() && !done) {
              cv.wait(lock);
            }
            if (done) {
              return;
            }
            url = q.front();
            q.pop();
            active_workers++;
          }
  
          vector<string> next_urls = htmlParser.getUrls(url);
  
          {
            unique_lock<mutex> lock(mtx);
            active_workers--;
  
            for (const string& next_url : next_urls) {
              if (getHostname(next_url) == hostname) {
                if (visited.insert(next_url).second) {
                  q.push(next_url);
                }
              }
            }
  
            if (q.empty() && active_workers == 0) {
              done = true;
              cv.notify_all();
              return;
            } else if (!q.empty()) {
              cv.notify_all();
            }
          }
        }
      };
  
      int num_threads = 4;
      vector<thread> threads;
      for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(worker);
      }
  
      for (auto& t : threads) {
        t.join();
      }
  
      return vector<string>(visited.begin(), visited.end());
    }
  };
  ```
  </details>
