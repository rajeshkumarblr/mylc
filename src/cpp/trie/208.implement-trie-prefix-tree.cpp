#include <set>
#include <cmath>
#include <map>
#include <nlohmann/json.hpp>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie Prefix Tree
 *
 * Difficulty: Medium
 * Category: trie
 * URL: https://leetcode.com/problems/implement-trie-prefix-tree/
 *
 * Description:
 * A   trie   (pronounced as "try") or  prefix tree  is a tree data structure
 * used to efficiently store and retrieve keys in a dataset of strings. There
 * are various applications of this data structure, such as autocomplete and
 * spellchecker.
 *  Implement the Trie class:
 *           Trie()  Initializes the trie object.
 *           void insert(String word)  Inserts the string  word  into the
 * trie.
 *           boolean search(String word)  Returns  true  if the string  word
 * is in the trie (i.e., was inserted before), and  false  otherwise.
 *           boolean startsWith(String prefix)  Returns  true  if there is a
 * previously inserted string  word  that has the prefix  prefix , and  false
 * otherwise.
 *   Example 1:
 *  Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 *  Output
 * [null, null, true, false, true, null, true]
 *  Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *   Constraints:
 *           1 <= word.length, prefix.length <= 2000
 *           word  and  prefix  consist only of lowercase English letters.
 *          At most  3 * 10 4   calls  in total  will be made to  insert ,
 * search , and  startsWith .
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
class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end


int main() {
    try {
        json j = json::parse(R"raw({
  "cases": []
})raw");
        for (const auto &tc : j.at("cases")) {
            const auto &commands = tc.at("commands");
            const auto &args = tc.contains("arguments") ? tc.at("arguments") : tc.at("args");
            const auto &expected = tc.at("expected");
            Trie* obj = nullptr;
            for (size_t i = 0; i < commands.size(); ++i) {
                string cmd = commands[i].get<string>();
                if (cmd == "Trie") {
                    if (obj) delete obj;
                    obj = new Trie();
                } else if (cmd == "insert") {
                    obj->insert(args[i][0].get<string>());
                } else if (cmd == "search") {
                    bool got = obj->search(args[i][0].get<string>());
                    bool exp = expected[i].get<bool>();
                    if (got != exp) { cerr << "FAIL search" << endl; return 1; }
                } else if (cmd == "startsWith") {
                    bool got = obj->startsWith(args[i][0].get<string>());
                    bool exp = expected[i].get<bool>();
                    if (got != exp) { cerr << "FAIL startsWith" << endl; return 1; }
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
