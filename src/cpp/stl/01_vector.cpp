#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // ---------------------------------------------------------
    // 1. INITIALIZATION & ASSIGNMENT
    // ---------------------------------------------------------
    vector<int> v1 = {4, 2, 5, 1, 3}; // Initializer list
    vector<int> v2(5, 10);            // 5 elements, all initialized to 10
    vector<int> v3(v1.begin(), v1.begin() + 3); // Copy first 3 elements of v1
    
    v3.assign(3, 100); // Replaces v3 contents with: 100, 100, 100
    
    // ---------------------------------------------------------
    // 2. CAPACITY & SIZING
    // ---------------------------------------------------------
    cout << "Size: " << v1.size() << endl;       // Number of elements
    cout << "Capacity: " << v1.capacity() << endl; // Allocated storage space
    cout << "Is Empty? " << (v1.empty() ? "Yes" : "No") << endl;
    
    v1.reserve(20); // Pre-allocates memory for 20 elements (prevents reallocations)
    v1.resize(7);   // Resizes to 7 elements. Appends 0s if expanding.
    v1.shrink_to_fit(); // Reduces capacity to match size
    
    // ---------------------------------------------------------
    // 3. ELEMENT ACCESS
    // ---------------------------------------------------------
    cout << "Index 2: " << v1[2] << endl;       // No bounds checking (fast)
    cout << "Index 2 (safe): " << v1.at(2) << endl; // Bounds checking (throws exception)
    cout << "First: " << v1.front() << endl;    // First element
    cout << "Last: " << v1.back() << endl;      // Last element
    
    // ---------------------------------------------------------
    // 4. MODIFIERS (Adding/Removing)
    // ---------------------------------------------------------
    v1.push_back(99);    // Adds 99 to the end (O(1))
    v1.emplace_back(88); // Constructs element in-place at the end (faster for objects)
    v1.pop_back();       // Removes last element (O(1))
    
    // Insert/Erase in the middle (O(N) - slow because elements must shift!)
    v1.insert(v1.begin() + 1, 77); // Inserts 77 at index 1
    v1.erase(v1.begin() + 2);      // Removes element at index 2
    
    v1.clear(); // Removes ALL elements (size becomes 0)
    
    // ---------------------------------------------------------
    // 5. ALGORITHMS & ITERATION
    // ---------------------------------------------------------
    vector<int> v = {4, 2, 5, 1, 3};
    
    // Sorting
    sort(v.begin(), v.end());                   // Ascending: 1, 2, 3, 4, 5
    sort(v.rbegin(), v.rend());                 // Descending: 5, 4, 3, 2, 1
    
    // Find an element
    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        cout << "Found 3 at index: " << distance(v.begin(), it) << endl;
    }
    
    // Range-based for loop
    for (const int& num : v) { // use const auto& to avoid copying
        cout << num << " ";
    }
    cout << endl;
    
    // Swapping two vectors (O(1) time - just swaps internal pointers!)
    v.swap(v2); 
    
    return 0;
}
