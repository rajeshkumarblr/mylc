#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Note: std::unordered_map is a Hash Map / Dictionary.
// Keys are NOT sorted.
// Insert/Find/Delete are average O(1) time. The MVP of LeetCode.
int main() {
    unordered_map<string, int> um;
    
    um["apple"] = 5;
    um["banana"] = 10;
    
    // Updating or adding
    um["apple"]++; // Now 6
    
    // Iterating
    for (auto const& [key, val] : um) {
        cout << key << ": " << val << endl;
    }
    
    // Searching
    if (um.contains("apple")) { // C++20
        cout << "Apple count: " << um["apple"] << endl;
    }
    
    return 0;
}
