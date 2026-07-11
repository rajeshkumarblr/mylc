#include <iostream>
#include <map>

using namespace std;

// Note: std::map is an ORDERED dictionary (Red-Black Tree).
// Keys are always kept in sorted order!
// Operations take O(log N) time.
int main() {
    map<string, int> m;
    
    m["zebra"] = 5;
    m["apple"] = 2;
    m["monkey"] = 3;
    
    // Will print in alphabetical order of keys: apple, monkey, zebra
    for (auto const& [key, val] : m) {
        cout << key << ": " << val << endl;
    }
    
    // Check if key exists
    if (m.find("apple") != m.end()) {
        cout << "Apple exists!" << endl;
    }
    
    return 0;
}
