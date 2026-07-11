#include <iostream>
#include <set>

using namespace std;

// Note: std::set (Ordered Set)
// - Implemented as a Self-Balancing Binary Search Tree (Red-Black Tree).
// - Elements are UNIQUE and ALWAYS sorted.
// - Insert/Erase/Find are O(log N).
int main() {
    set<int> s = {5, 2, 8, 2, 1}; // Initializes with {1, 2, 5, 8} (duplicates removed, sorted)
    
    // 1. Modifiers
    s.insert(10);
    s.erase(5); // Removes 5
    
    // 2. Search & Status
    cout << "Size: " << s.size() << endl;
    
    // Check if exists (C++20 adds .contains(), otherwise use .count() or .find())
    if (s.contains(8)) {
        cout << "8 is in the set!" << endl;
    }
    
    if (s.count(2) > 0) { // Returns 1 if present, 0 if not
        cout << "2 is in the set!" << endl;
    }
    
    // 3. Lower & Upper Bounds (O(log N) Binary Search)
    // lower_bound: iterator to first element >= val
    // upper_bound: iterator to first element > val
    auto it_low = s.lower_bound(2); // Points to 2
    auto it_up = s.upper_bound(2);  // Points to 8
    
    cout << "Lower bound of 2: " << *it_low << endl;
    cout << "Upper bound of 2: " << *it_up << endl;
    
    // 4. Iteration (In-order traversal)
    for (int num : s) {
        cout << num << " "; // 1 2 8 10
    }
    cout << endl;
    
    return 0;
}
