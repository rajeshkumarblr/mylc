#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Note: std::list is a doubly-linked list.
// - Supports O(1) insertions/deletions anywhere IF you have the iterator.
// - Lacks random access (no operator[]).
int main() {
    // 1. Initialization
    list<int> l1 = {10, 20, 30, 40};
    list<int> l2(3, 100); // {100, 100, 100}
    
    // 2. Modifiers
    l1.push_back(50);   // O(1)
    l1.push_front(0);   // O(1)
    l1.pop_back();      // O(1)
    l1.pop_front();     // O(1)
    
    // 3. Iteration & Element Access (Only front/back)
    cout << "Front: " << l1.front() << ", Back: " << l1.back() << endl;
    
    // 4. Mid-list Operations (Iterators required!)
    auto it = l1.begin();
    advance(it, 2); // Move iterator to index 2 (O(N) cost!)
    l1.insert(it, 25); // Insert 25 BEFORE index 2 -> {10, 20, 25, 30, 40}
    
    // 5. Splicing (O(1) transfer of elements between lists)
    l1.splice(l1.begin(), l2); // Moves all elements of l2 to the front of l1
    
    // 6. List-specific algorithms (std::sort does NOT work on list)
    l1.sort();          // Sorts in O(N log N)
    l1.reverse();       // Reverses the list in O(N)
    l1.remove(100);     // Removes all occurrences of 100
    l1.unique();        // Removes adjacent duplicates
    
    return 0;
}
