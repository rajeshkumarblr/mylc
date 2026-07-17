#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
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
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    // Case 1
    {
        vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        auto got = sol.groupAnagrams(strs);
        if (got != vector<vector<string>>{{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<string> strs = {""};
        auto got = sol.groupAnagrams(strs);
        if (got != vector<vector<string>>{{""}}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        vector<string> strs = {"a"};
        auto got = sol.groupAnagrams(strs);
        if (got != vector<vector<string>>{{"a"}}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
