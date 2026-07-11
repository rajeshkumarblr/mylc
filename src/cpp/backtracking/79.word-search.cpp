/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * Difficulty: Medium
 * Category: backtracking
 * URL: https://leetcode.com/problems/word-search/
 *
 * Description:
 * Given an  m x n  grid of characters  board  and a string  word , return
 * true   if   word   exists in the grid .
 *  The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *   Example 1:
 *  Input:  board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
 * word = "ABCCED"
 *  Output:  true
 *   Example 2:
 *  Input:  board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
 * word = "SEE"
 *  Output:  true
 *   Example 3:
 *  Input:  board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
 * word = "ABCB"
 *  Output:  false
 *   Constraints:
 *           m == board.length
 *           n = board[i].length
 *           1 <= m, n <= 6
 *           1 <= word.length <= 15
 *           board  and  word  consists of only lowercase and uppercase
 * English letters.
 *   Follow up:  Could you use search pruning to make your solution faster
 * with a larger  board ?
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
    bool exist(vector<vector<char>>& board, string word) {
        
    }
};
// @lc code=end
