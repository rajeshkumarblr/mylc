/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * Difficulty: Hard
 * Category: trie
 * URL: https://leetcode.com/problems/word-search-ii/
 *
 * Description:
 * Given an  m x n   board  of characters and a list of strings  words ,
 * return  all words on the board .
 *  Each word must be constructed from letters of sequentially adjacent cells,
 * where  adjacent cells  are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once in a word.
 *   Example 1:
 *  Input:  board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 *  Output:  ["eat","oath"]
 *   Example 2:
 *  Input:  board = [["a","b"],["c","d"]], words = ["abcb"]
 *  Output:  []
 *   Constraints:
 *           m == board.length
 *           n == board[i].length
 *           1 <= m, n <= 12
 *           board[i][j]  is a lowercase English letter.
 *           1 <= words.length <= 3 * 10 4
 *           1 <= words[i].length <= 10
 *           words[i]  consists of lowercase English letters.
 *          All the strings of  words  are unique.
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
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
    }
};
// @lc code=end
