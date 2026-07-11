#include <iostream>
#include <stack>

using namespace std;

// Note: std::stack is a LIFO (Last In First Out) data structure.
// Heavily used for DFS (Depth First Search), Valid Parentheses, Monotonic Stack problems.
int main() {
    stack<int> s;
    
    // Push
    s.push(1);
    s.push(2);
    s.push(3);
    
    // Process top-down
    while (!s.empty()) {
        int top_element = s.top(); // Get top
        cout << "Popping: " << top_element << endl;
        s.pop(); // Remove it
    }
    
    return 0;
}
