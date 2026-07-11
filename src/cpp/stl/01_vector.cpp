#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 1. Initialization
    vector<int> v = {4, 2, 5, 1, 3};
    
    // 2. Add/Remove
    v.push_back(6);      // Add to end: O(1)
    v.pop_back();        // Remove from end: O(1)
    
    // 3. Access
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;
    cout << "Element at index 2: " << v[2] << endl;
    
    // 4. Sorting (Very common in LeetCode)
    sort(v.begin(), v.end()); // O(N log N)
    
    // 5. Iteration
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
