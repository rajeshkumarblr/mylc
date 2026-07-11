/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * Difficulty: Medium
 * Category: hash
 * URL: https://leetcode.com/problems/group-anagrams/
 *
 * Description:
 * Given an array of strings  strs , group the  anagrams  together. You can
 * return the answer in  any order .
 *   Example 1:
 *   Input:   strs = ["eat","tea","tan","ate","nat","bat"]
 *   Output:   [["bat"],["nat","tan"],["ate","eat","tea"]]
 *   Explanation:
 *          There is no string in strs that can be rearranged to form  "bat" .
 *          The strings  "nat"  and  "tan"  are anagrams as they can be
 * rearranged to form each other.
 *          The strings  "ate" ,  "eat" , and  "tea"  are anagrams as they can
 * be rearranged to form each other.
 *   Example 2:
 *   Input:   strs = [""]
 *   Output:   [[""]]
 *   Example 3:
 *   Input:   strs = ["a"]
 *   Output:   [["a"]]
 *   Constraints:
 *           1 <= strs.length <= 10 4
 *           0 <= strs[i].length <= 100
 *           strs[i]  consists of lowercase English letters.
 */

#include "../lc_test_utils.h"
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    }
};
// @lc code=end
