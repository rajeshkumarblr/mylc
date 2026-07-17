#include <set>
#include <cmath>
#include <map>
#include <nlohmann/json.hpp>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median From Data Stream
 *
 * Difficulty: Hard
 * Category: heap
 * URL: https://leetcode.com/problems/find-median-from-data-stream/
 *
 * Description:
 * The  median  is the middle value in an ordered integer list. If the size of
 * the list is even, there is no middle value, and the median is the mean of
 * the two middle values.
 *          For example, for  arr = [2,3,4] , the median is  3 .
 *          For example, for  arr = [2,3] , the median is  (2 + 3) / 2 = 2.5 .
 *  Implement the MedianFinder class:
 *           MedianFinder()  initializes the  MedianFinder  object.
 *           void addNum(int num)  adds the integer  num  from the data stream
 * to the data structure.
 *           double findMedian()  returns the median of all elements so far.
 * Answers within  10 -5   of the actual answer will be accepted.
 *   Example 1:
 *  Input
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 *  Output
 * [null, null, null, 1.5, null, 2.0]
 *  Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *   Constraints:
 *           -10 5  <= num <= 10 5
 *          There will be at least one element in the data structure before
 * calling  findMedian .
 *          At most  5 * 10 4   calls will be made to  addNum  and  findMedian
 * .
 *   Follow up:
 *          If all integer numbers from the stream are in the range  [0, 100]
 * , how would you optimize your solution?
 *          If  99%  of all integer numbers from the stream are in the range
 * [0, 100] , how would you optimize your solution?
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
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;


// @lc code=start
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
// @lc code=end


int main() {
    try {
        json j = json::parse(R"raw({
  "cases": [
    {
      "commands": [
        "MedianFinder",
        "addNum",
        "addNum",
        "findMedian",
        "addNum",
        "findMedian"
      ],
      "arguments": [
        [],
        [
          1
        ],
        [
          2
        ],
        [],
        [
          3
        ],
        []
      ],
      "expected": [
        null,
        null,
        null,
        1.5,
        null,
        2.0
      ]
    }
  ]
})raw");
        for (const auto &tc : j.at("cases")) {
            const auto &commands = tc.at("commands");
            const auto &args = tc.contains("arguments") ? tc.at("arguments") : tc.at("args");
            const auto &expected = tc.at("expected");
            MedianFinder* obj = nullptr;
            for (size_t i = 0; i < commands.size(); ++i) {
                string cmd = commands[i].get<string>();
                if (cmd == "MedianFinder") {
                    if (obj) delete obj;
                    obj = new MedianFinder();
                } else if (cmd == "addNum") {
                    obj->addNum(args[i][0].get<int>());
                } else if (cmd == "findMedian") {
                    double got = obj->findMedian();
                    double exp = expected[i].get<double>();
                    if (fabs(got - exp) > 1e-9) { cerr << "FAIL findMedian" << endl; return 1; }
                }
            }
            if (obj) delete obj;
        }
        cout << "PASS" << endl;
        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 4;
    }
}
