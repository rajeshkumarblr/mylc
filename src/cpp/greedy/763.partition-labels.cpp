#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * Difficulty: Medium
 * Category: greedy
 * URL: https://leetcode.com/problems/partition-labels/
 *
 * Description:
 * You are given a string  s . We want to partition the string into as many
 * parts as possible so that each letter appears in at most one part. For
 * example, the string  "ababcc"  can be partitioned into  ["abab", "cc"] ,
 * but partitions such as  ["aba", "bcc"]  or  ["ab", "ab", "cc"]  are
 * invalid.
 *  Note that the partition is done so that after concatenating all the parts
 * in order, the resultant string should be  s .
 *  Return  a list of integers representing the size of these parts .
 *   Example 1:
 *  Input:  s = "ababcbacadefegdehijhklij"
 *  Output:  [9,7,8]
 *  Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits s into less parts.
 *   Example 2:
 *  Input:  s = "eccbbbbdec"
 *  Output:  [10]
 *   Constraints:
 *           1 <= s.length <= 500
 *           s  consists of lowercase English letters.
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
    vector<int> partitionLabels(string s) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
