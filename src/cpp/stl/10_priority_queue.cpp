#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for std::greater

using namespace std;

// Note: std::priority_queue (Heap)
// - Implemented as an array-backed Binary Heap.
// - O(log N) push/pop. O(1) top.
// - Useful for "Top K" elements problems, Dijkstra's algorithm.
int main() {
    // ---------------------------------------------------------
    // 1. MAX HEAP (Default behavior in C++)
    // ---------------------------------------------------------
    priority_queue<int> maxHeap;
    
    maxHeap.push(3);
    maxHeap.push(10);
    maxHeap.push(5);
    
    cout << "Max Heap Top: " << maxHeap.top() << endl; // 10
    maxHeap.pop(); // Removes 10
    
    // ---------------------------------------------------------
    // 2. MIN HEAP (Requires verbose template arguments)
    // ---------------------------------------------------------
    // Type, Underlying Container, Comparator (greater = Min Heap)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    minHeap.push(3);
    minHeap.push(10);
    minHeap.push(5);
    
    cout << "Min Heap Top: " << minHeap.top() << endl; // 3
    minHeap.pop(); // Removes 3
    
    // ---------------------------------------------------------
    // 3. CUSTOM OBJECTS / COMPARATORS
    // ---------------------------------------------------------
    // Example: Min Heap of Pairs (sorted by first element, then second)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_pairs;
    pq_pairs.push({5, 1});
    pq_pairs.push({2, 10});
    pq_pairs.push({2, 5});
    
    cout << "Top Pair: {" << pq_pairs.top().first << ", " << pq_pairs.top().second << "}" << endl; // {2, 5}
    
    return 0;
}
