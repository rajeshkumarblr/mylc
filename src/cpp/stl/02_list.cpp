#include <iostream>
#include <list>

using namespace std;

// Note: std::list is a doubly-linked list. It does NOT support random access (no v[2]).
// Usually, vector is preferred for LeetCode unless you need fast insertions/deletions in the middle.
int main() {
    list<int> l = {1, 2, 3};
    
    l.push_back(4);   // O(1)
    l.push_front(0);  // O(1)
    
    l.pop_back();     // O(1)
    l.pop_front();    // O(1)
    
    // Iteration (must use iterators, cannot use index)
    for (int num : l) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
