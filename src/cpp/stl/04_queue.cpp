#include <iostream>
#include <queue>

using namespace std;

// Note: std::queue is a FIFO (First In First Out) data structure.
// Primarily used for BFS (Breadth First Search) in Graphs/Trees.
int main() {
    queue<int> q;
    
    // Enqueue
    q.push(1);
    q.push(2);
    q.push(3);
    
    // Dequeue and process (BFS pattern)
    while (!q.empty()) {
        int front_element = q.front();
        cout << "Processing: " << front_element << endl;
        q.pop(); // Remove it
    }
    
    return 0;
}
