#include <iostream>
#include <unordered_set>

using namespace std;

// Note: std::unordered_set is a Hash Set.
// Elements are NOT sorted.
// Insert/Find/Delete are average O(1) time. Heavily used in LeetCode.
int main() {
    unordered_set<int> us;
    
    // Optimization for LeetCode to avoid rehashing:
    // us.reserve(100000); 
    
    us.insert(5);
    us.insert(1);
    us.insert(3);
    
    // Will print in random/hash order!
    for (int num : us) {
        cout << num << " ";
    }
    cout << endl;
    
    if (us.contains(5)) { // C++20 standard
        cout << "5 exists in the hash set!" << endl;
    }
    
    return 0;
}
