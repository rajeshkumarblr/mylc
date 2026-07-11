#include <iostream>
#include <stack>

using namespace std;

// Note: std::stack is a Container Adaptor (LIFO)
// - Uses std::deque by default.
// - MVP for Depth-First Search (DFS), Valid Parentheses, Monotonic Stacks.
int main() {
    stack<int> s;
    
    // 1. Push
    s.push(10);
    s.emplace(20);
    s.push(30);
    
    // 2. Access
    // Note: Stacks do NOT have a .front() or .back(). They only have .top()
    cout << "Top: " << s.top() << endl; // 30
    
    // 3. Status
    cout << "Size: " << s.size() << endl;
    cout << "Is Empty? " << (s.empty() ? "Yes" : "No") << endl;
    
    // 4. Pop and Process (Classic Pattern)
    while (!s.empty()) {
        int curr = s.top();
        cout << "Popping: " << curr << endl;
        s.pop(); // Removes the top element (O(1))
    }
    
    return 0;
}
