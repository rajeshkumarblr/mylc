#include <iostream>
#include <unordered_set>

using namespace std;

// Note: std::unordered_set (Hash Set)
// - Hash Table implementation.
// - Elements are UNIQUE and UNORDERED.
// - Average O(1) operations. Worst case O(N) on collision/rehash.
int main() {
    unordered_set<int> us = {5, 2, 8, 1};
    
    // 1. Capacity & Rehashing Optimizations
    // In LeetCode, if you know N <= 100,000, reserve space to prevent slow re-allocations!
    us.reserve(100000);
    
    cout << "Size: " << us.size() << endl;
    cout << "Bucket count: " << us.bucket_count() << endl;
    cout << "Load factor: " << us.load_factor() << endl;
    
    // 2. Modifiers
    us.insert(10);
    us.erase(5); // Returns 1 if removed, 0 if it didn't exist
    
    // 3. Search
    if (us.contains(8)) { // C++20
        cout << "8 is present!" << endl;
    }
    
    if (us.count(2)) { // C++11 standard check
        cout << "2 is present!" << endl;
    }
    
    // 4. Iteration (Random order!)
    for (int num : us) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
