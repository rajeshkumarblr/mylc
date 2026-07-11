#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Note: std::priority_queue is a HEAP data structure.
// Insertions and removals are O(log N). Getting the top is O(1).
int main() {
    // 1. MAX HEAP (Default in C++)
    priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(10);
    maxHeap.push(5);
    cout << "Max Heap Top: " << maxHeap.top() << endl; // 10
    maxHeap.pop(); // Removes 10
    
    // 2. MIN HEAP (Requires special syntax)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(10);
    minHeap.push(5);
    cout << "Min Heap Top: " << minHeap.top() << endl; // 3
    minHeap.pop(); // Removes 3
    
    return 0;
}
