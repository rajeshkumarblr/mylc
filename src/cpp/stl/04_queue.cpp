#include <iostream>
#include <queue>

using namespace std;

// Note: std::queue is a Container Adaptor (FIFO)
// - Under the hood, it uses std::deque by default.
// - MVP for Breadth-First Search (BFS) in Trees & Graphs.
int main() {
    queue<int> q;
    
    // 1. Enqueue (Push)
    q.push(10);
    q.emplace(20); // Faster in-place construction
    q.push(30);
    
    // 2. Access
    cout << "Front: " << q.front() << endl; // 10
    cout << "Back: "  << q.back() << endl;  // 30
    
    // 3. Status
    cout << "Size: " << q.size() << endl;
    cout << "Is Empty? " << (q.empty() ? "Yes" : "No") << endl;
    
    // 4. Dequeue and Process (Classic BFS Pattern)
    while (!q.empty()) {
        int curr = q.front();
        cout << "Processing: " << curr << endl;
        q.pop(); // Removes the front element (O(1))
    }
    
    return 0;
}
