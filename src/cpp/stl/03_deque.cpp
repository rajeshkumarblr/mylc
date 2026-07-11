#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// Note: std::deque (Double Ended Queue)
// - Supports O(1) insertion/deletion at BOTH front and back.
// - Supports O(1) random access (like vector).
// - Elements are NOT perfectly contiguous in memory (chunked).
// - MVP for Sliding Window Maximum / Monotonic Queue problems!
int main() {
    deque<int> dq = {3, 1, 4};
    
    // 1. Double-ended Modifiers
    dq.push_back(10);   // {3, 1, 4, 10}
    dq.emplace_back(20);
    dq.push_front(0);   // {0, 3, 1, 4, 10, 20}
    dq.emplace_front(-1);
    
    dq.pop_back();      // Removes 20
    dq.pop_front();     // Removes -1
    
    // 2. Random Access
    cout << "Index 2: " << dq[2] << endl;
    cout << "Index 2 (safe): " << dq.at(2) << endl;
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    
    // 3. Sizing
    cout << "Size: " << dq.size() << endl;
    dq.resize(10, -1); // Resizes to 10, appending -1s
    
    // 4. Algorithms work just like vector
    sort(dq.begin(), dq.end());
    
    return 0;
}
