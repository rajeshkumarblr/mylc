#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * Difficulty: Hard
 * Category: graphs
 * URL: https://leetcode.com/problems/word-ladder/
 *
 * Description:
 * A  transformation sequence  from word  beginWord  to word  endWord  using a
 * dictionary  wordList  is a sequence of words  beginWord -> s 1  -> s 2  ->
 * ... -> s k   such that:
 *          Every adjacent pair of words differs by a single letter.
 *          Every  s i   for  1 <= i <= k  is in  wordList . Note that
 * beginWord  does not need to be in  wordList .
 *           s k  == endWord
 *  Given two words,  beginWord  and  endWord , and a dictionary  wordList ,
 * return  the  number of words  in the  shortest transformation sequence
 * from   beginWord   to   endWord  , or   0   if no such sequence exists.
 *   Example 1:
 *  Input:  beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 *  Output:  5
 *  Explanation:  One shortest transformation sequence is "hit" -> "hot" ->
 * "dot" -> "dog" -> cog", which is 5 words long.
 *   Example 2:
 *  Input:  beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 *  Output:  0
 *  Explanation:  The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *   Constraints:
 *           1 <= beginWord.length <= 10
 *           endWord.length == beginWord.length
 *           1 <= wordList.length <= 5000
 *           wordList[i].length == beginWord.length
 *           beginWord ,  endWord , and  wordList[i]  consist of lowercase
 * English letters.
 *           beginWord != endWord
 *          All the words in  wordList  are  unique .
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
