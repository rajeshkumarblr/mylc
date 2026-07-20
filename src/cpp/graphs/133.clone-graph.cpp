#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 *
 * Difficulty: Medium
 * Category: graphs
 * URL: https://leetcode.com/problems/clone-graph/
 *
 * Description:
 * Given a reference of a node in a   connected   undirected graph.
 *  Return a   deep copy   (clone) of the graph.
 *  Each node in the graph contains a value ( int ) and a list ( List[Node] )
 * of its neighbors.
 * class Node {
 *     public int val;
 *     public List<Node> neighbors;
 * }
 *   Test case format:
 *  For simplicity, each node's value is the same as the node's index
 * (1-indexed). For example, the first node with  val == 1 , the second node
 * with  val == 2 , and so on. The graph is represented in the test case using
 * an adjacency list.
 *   An adjacency list  is a collection of unordered  lists  used to represent
 * a finite graph. Each list describes the set of neighbors of a node in the
 * graph.
 *  The given node will always be the first node with  val = 1 . You must
 * return the  copy of the given node  as a reference to the cloned graph.
 *   Example 1:
 *  Input:  adjList = [[2,4],[1,3],[2,4],[1,3]]
 *  Output:  [[2,4],[1,3],[2,4],[1,3]]
 *  Explanation:  There are 4 nodes in the graph.
 * 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val =
 * 4).
 * 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val =
 * 3).
 * 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val =
 * 4).
 * 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val =
 * 3).
 *   Example 2:
 *  Input:  adjList = [[]]
 *  Output:  [[]]
 *  Explanation:  Note that the input contains one empty list. The graph
 * consists of only one node with val = 1 and it does not have any neighbors.
 *   Example 3:
 *  Input:  adjList = []
 *  Output:  []
 *  Explanation:  This an empty graph, it does not have any nodes.
 *   Constraints:
 *          The number of nodes in the graph is in the range  [0, 100] .
 *           1 <= Node.val <= 100
 *           Node.val  is unique for each node.
 *          There are no repeated edges and no self-loops in the graph.
 *          The Graph is connected and all nodes can be visited starting from
 * the given node.
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
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        return {};
    }
};
// @lc code=end


#include <nlohmann/json.hpp>

using json = nlohmann::json;

Node* buildGraph(const vector<vector<int>>& adjList) {
    if (adjList.empty()) return nullptr;
    unordered_map<int, Node*> nodes;
    for (int i = 0; i < adjList.size(); i++) {
        nodes[i + 1] = new Node(i + 1);
    }
    for (int i = 0; i < adjList.size(); i++) {
        for (int neighbor : adjList[i]) {
            nodes[i + 1]->neighbors.push_back(nodes[neighbor]);
        }
    }
    return nodes[1];
}

vector<vector<int>> graphToAdjList(Node* node) {
    if (!node) return {};
    unordered_map<int, Node*> visited;
    queue<Node*> q;
    q.push(node);
    visited[node->val] = node;
    int maxVal = 0;
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        maxVal = max(maxVal, curr->val);
        for (Node* neighbor : curr->neighbors) {
            if (visited.find(neighbor->val) == visited.end()) {
                visited[neighbor->val] = neighbor;
                q.push(neighbor);
            }
        }
    }
    vector<vector<int>> adjList(maxVal);
    for (int i = 1; i <= maxVal; i++) {
        if (visited.count(i)) {
            for (Node* neighbor : visited[i]->neighbors) {
                adjList[i - 1].push_back(neighbor->val);
            }
        }
    }
    return adjList;
}

bool checkDeepCopy(Node* original, Node* clone) {
    if (!original && !clone) return true;
    if (!original || !clone) return false;
    
    unordered_map<int, Node*> visitedOrig, visitedClone;
    queue<Node*> qOrig, qClone;
    
    qOrig.push(original);
    qClone.push(clone);
    visitedOrig[original->val] = original;
    visitedClone[clone->val] = clone;
    
    while (!qOrig.empty() && !qClone.empty()) {
        Node* currOrig = qOrig.front(); qOrig.pop();
        Node* currClone = qClone.front(); qClone.pop();
        
        if (currOrig == currClone) return false; // Not a deep copy!
        if (currOrig->val != currClone->val) return false;
        if (currOrig->neighbors.size() != currClone->neighbors.size()) return false;
        
        for (int i = 0; i < currOrig->neighbors.size(); i++) {
            Node* nOrig = currOrig->neighbors[i];
            Node* nClone = currClone->neighbors[i];
            
            if (nOrig == nClone) return false; // Shared reference, not deep copy!
            
            if (visitedOrig.find(nOrig->val) == visitedOrig.end()) {
                visitedOrig[nOrig->val] = nOrig;
                qOrig.push(nOrig);
            }
            if (visitedClone.find(nClone->val) == visitedClone.end()) {
                visitedClone[nClone->val] = nClone;
                qClone.push(nClone);
            }
        }
    }
    return true;
}

int main() {
  try {
    json j = json::parse(R"raw({
      "cases": [
        {
          "adjList": [[2,4],[1,3],[2,4],[1,3]],
          "expected": [[2,4],[1,3],[2,4],[1,3]]
        },
        {
          "adjList": [[]],
          "expected": [[]]
        },
        {
          "adjList": [],
          "expected": []
        }
      ]
    })raw");

    for (auto &tc : j.at("cases")) {
      vector<vector<int>> adjList = tc.at("adjList").get<vector<vector<int>>>();
      vector<vector<int>> expected = tc.at("expected").get<vector<vector<int>>>();
      
      Node* original = buildGraph(adjList);
      
      Solution sol;
      Node* cloned = sol.cloneGraph(original);
      
      vector<vector<int>> clonedAdjList = graphToAdjList(cloned);
      bool isDeepCopy = checkDeepCopy(original, cloned);
      
      if (clonedAdjList != expected || !isDeepCopy) {
        cerr << "FAIL for input" << endl;
        cerr << "Is Deep Copy? " << (isDeepCopy ? "Yes" : "NO") << endl;
        return 1;
      }
    }
    cout << "PASS" << endl;
  } catch (const exception &e) {
    cerr << "Fatal Error: " << e.what() << endl;
    return 1;
  }
  return 0;
}
