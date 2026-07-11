#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Note: std::unordered_map (Hash Map)
// - Hash Table mapping Keys to Values.
// - Keys are UNIQUE and UNORDERED.
// - Average O(1) operations. 
// - The undisputed MVP for 90% of LeetCode problems (Two Sum, Frequency Counting, etc).
int main() {
    unordered_map<string, int> um;
    
    // Optimization: Pre-allocate buckets if size is known
    um.reserve(1000);
    
    // 1. Insertion / Updating
    um["apple"] = 5;       
    um["banana"] = 10;
    
    // Counting frequencies is trivial:
    um["apple"]++; // If "apple" didn't exist, it would be created and initialized to 0, then incremented to 1.
    
    // 2. Search
    // DANGER: Never use `if (um["cherry"] > 0)` to check existence!
    // That will accidentally insert "cherry" into the map with a value of 0!
    
    // Safe ways to check existence:
    if (um.contains("apple")) { // C++20 (Cleanest)
        cout << "Apple count: " << um["apple"] << endl;
    }
    
    if (um.count("banana") > 0) { // C++11
        cout << "Banana exists!" << endl;
    }
    
    // 3. Iteration
    for (const auto& [key, val] : um) {
        cout << key << ": " << val << endl;
    }
    
    // 4. Erase
    um.erase("banana");
    
    return 0;
}
