import os

STL_DIR = "/home/rajesh/proj/mylc/src/cpp/stl"
os.makedirs(STL_DIR, exist_ok=True)

files = {
    "01_vector.cpp": """#include <iostream>
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
""",
    
    "02_list.cpp": """#include <iostream>
#include <list>

using namespace std;

// Note: std::list is a doubly-linked list. It does NOT support random access (no v[2]).
// Usually, vector is preferred for LeetCode unless you need fast insertions/deletions in the middle.
int main() {
    list<int> l = {1, 2, 3};
    
    l.push_back(4);   // O(1)
    l.push_front(0);  // O(1)
    
    l.pop_back();     // O(1)
    l.pop_front();    // O(1)
    
    // Iteration (must use iterators, cannot use index)
    for (int num : l) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
""",

    "03_deque.cpp": """#include <iostream>
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
""",

    "04_queue.cpp": """#include <iostream>
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
""",

    "05_stack.cpp": """#include <iostream>
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
""",

    "06_set.cpp": """#include <iostream>
#include <set>

using namespace std;

// Note: std::set is an ORDERED set (implemented as a Red-Black Tree).
// Elements are always kept in sorted order automatically!
// Operations take O(log N) time.
int main() {
    set<int> s;
    
    s.insert(5); // O(log N)
    s.insert(1);
    s.insert(3);
    s.insert(1); // Ignored, sets only keep unique elements
    
    // Will print: 1 3 5 (Automatically sorted!)
    for (int num : s) {
        cout << num << " ";
    }
    cout << endl;
    
    // Search
    if (s.count(3)) {
        cout << "3 exists in the set!" << endl;
    }
    
    return 0;
}
""",

    "07_map.cpp": """#include <iostream>
#include <map>

using namespace std;

// Note: std::map is an ORDERED dictionary (Red-Black Tree).
// Keys are always kept in sorted order!
// Operations take O(log N) time.
int main() {
    map<string, int> m;
    
    m["zebra"] = 5;
    m["apple"] = 2;
    m["monkey"] = 3;
    
    // Will print in alphabetical order of keys: apple, monkey, zebra
    for (auto const& [key, val] : m) {
        cout << key << ": " << val << endl;
    }
    
    // Check if key exists
    if (m.find("apple") != m.end()) {
        cout << "Apple exists!" << endl;
    }
    
    return 0;
}
""",

    "08_unordered_set.cpp": """#include <iostream>
#include <unordered_set>

using namespace std;

// Note: std::unordered_set is a Hash Set.
// Elements are NOT sorted.
// Insert/Find/Delete are average O(1) time. Heavily used in LeetCode.
int main() {
    unordered_set<int> us;
    
    // Optimization for LeetCode to avoid rehashing:
    // us.reserve(100000); 
    
    us.insert(5);
    us.insert(1);
    us.insert(3);
    
    // Will print in random/hash order!
    for (int num : us) {
        cout << num << " ";
    }
    cout << endl;
    
    if (us.contains(5)) { // C++20 standard
        cout << "5 exists in the hash set!" << endl;
    }
    
    return 0;
}
""",

    "09_unordered_map.cpp": """#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Note: std::unordered_map is a Hash Map / Dictionary.
// Keys are NOT sorted.
// Insert/Find/Delete are average O(1) time. The MVP of LeetCode.
int main() {
    unordered_map<string, int> um;
    
    um["apple"] = 5;
    um["banana"] = 10;
    
    // Updating or adding
    um["apple"]++; // Now 6
    
    // Iterating
    for (auto const& [key, val] : um) {
        cout << key << ": " << val << endl;
    }
    
    // Searching
    if (um.contains("apple")) { // C++20
        cout << "Apple count: " << um["apple"] << endl;
    }
    
    return 0;
}
""",

    "10_priority_queue.cpp": """#include <iostream>
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
"""
}

for name, content in files.items():
    with open(os.path.join(STL_DIR, name), "w") as f:
        f.write(content)

print(f"Generated {len(files)} STL examples.")
