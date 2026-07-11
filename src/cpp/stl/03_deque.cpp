#include <iostream>
#include <deque>

using namespace std;

// Note: std::deque (Double Ended Queue) is heavily used in Sliding Window problems!
int main() {
    deque<int> dq;
    
    dq.push_back(2);   // [2]
    dq.push_back(3);   // [2, 3]
    dq.push_front(1);  // [1, 2, 3]
    
    dq.pop_back();     // [1, 2]
    dq.pop_front();    // [2]
    
    // Deque ALSO supports random access, unlike std::list!
    dq.push_back(3);
    cout << "Element at index 1: " << dq[1] << endl; 
    
    return 0;
}
