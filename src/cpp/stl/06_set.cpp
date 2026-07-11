#include <iostream>
#include <set>

using namespace std;

// Note: std::set is an ORDERED set (implemented as a Red-Black Tree).
// Elements are always kept in sorted order automatically!
// Operations take O(log N) time.
int main() {
    set<int> s;
    
    s.insert(5); // O(log N)
    s.insert(1);
    s.insert(3);
    s.insert(1); // Ignored, sets only keep unique elements
    
    // Will print: 1 3 5 (Automatically sorted!)
    for (int num : s) {
        cout << num << " ";
    }
    cout << endl;
    
    // Search
    if (s.count(3)) {
        cout << "3 exists in the set!" << endl;
    }
    
    return 0;
}
