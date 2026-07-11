import os

STL_DIR = "/home/rajesh/proj/mylc/src/cpp/stl"
os.makedirs(STL_DIR, exist_ok=True)

files = {
    "01_vector.cpp": """#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // ---------------------------------------------------------
    // 1. INITIALIZATION & ASSIGNMENT
    // ---------------------------------------------------------
    vector<int> v1 = {4, 2, 5, 1, 3}; // Initializer list
    vector<int> v2(5, 10);            // 5 elements, all initialized to 10
    vector<int> v3(v1.begin(), v1.begin() + 3); // Copy first 3 elements of v1
    
    v3.assign(3, 100); // Replaces v3 contents with: 100, 100, 100
    
    // ---------------------------------------------------------
    // 2. CAPACITY & SIZING
    // ---------------------------------------------------------
    cout << "Size: " << v1.size() << endl;       // Number of elements
    cout << "Capacity: " << v1.capacity() << endl; // Allocated storage space
    cout << "Is Empty? " << (v1.empty() ? "Yes" : "No") << endl;
    
    v1.reserve(20); // Pre-allocates memory for 20 elements (prevents reallocations)
    v1.resize(7);   // Resizes to 7 elements. Appends 0s if expanding.
    v1.shrink_to_fit(); // Reduces capacity to match size
    
    // ---------------------------------------------------------
    // 3. ELEMENT ACCESS
    // ---------------------------------------------------------
    cout << "Index 2: " << v1[2] << endl;       // No bounds checking (fast)
    cout << "Index 2 (safe): " << v1.at(2) << endl; // Bounds checking (throws exception)
    cout << "First: " << v1.front() << endl;    // First element
    cout << "Last: " << v1.back() << endl;      // Last element
    
    // ---------------------------------------------------------
    // 4. MODIFIERS (Adding/Removing)
    // ---------------------------------------------------------
    v1.push_back(99);    // Adds 99 to the end (O(1))
    v1.emplace_back(88); // Constructs element in-place at the end (faster for objects)
    v1.pop_back();       // Removes last element (O(1))
    
    // Insert/Erase in the middle (O(N) - slow because elements must shift!)
    v1.insert(v1.begin() + 1, 77); // Inserts 77 at index 1
    v1.erase(v1.begin() + 2);      // Removes element at index 2
    
    v1.clear(); // Removes ALL elements (size becomes 0)
    
    // ---------------------------------------------------------
    // 5. ALGORITHMS & ITERATION
    // ---------------------------------------------------------
    vector<int> v = {4, 2, 5, 1, 3};
    
    // Sorting
    sort(v.begin(), v.end());                   // Ascending: 1, 2, 3, 4, 5
    sort(v.rbegin(), v.rend());                 // Descending: 5, 4, 3, 2, 1
    
    // Find an element
    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        cout << "Found 3 at index: " << distance(v.begin(), it) << endl;
    }
    
    // Range-based for loop
    for (const int& num : v) { // use const auto& to avoid copying
        cout << num << " ";
    }
    cout << endl;
    
    // Swapping two vectors (O(1) time - just swaps internal pointers!)
    v.swap(v2); 
    
    return 0;
}
""",
    
    "02_list.cpp": """#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Note: std::list is a doubly-linked list.
// - Supports O(1) insertions/deletions anywhere IF you have the iterator.
// - Lacks random access (no operator[]).
int main() {
    // 1. Initialization
    list<int> l1 = {10, 20, 30, 40};
    list<int> l2(3, 100); // {100, 100, 100}
    
    // 2. Modifiers
    l1.push_back(50);   // O(1)
    l1.push_front(0);   // O(1)
    l1.pop_back();      // O(1)
    l1.pop_front();     // O(1)
    
    // 3. Iteration & Element Access (Only front/back)
    cout << "Front: " << l1.front() << ", Back: " << l1.back() << endl;
    
    // 4. Mid-list Operations (Iterators required!)
    auto it = l1.begin();
    advance(it, 2); // Move iterator to index 2 (O(N) cost!)
    l1.insert(it, 25); // Insert 25 BEFORE index 2 -> {10, 20, 25, 30, 40}
    
    // 5. Splicing (O(1) transfer of elements between lists)
    l1.splice(l1.begin(), l2); // Moves all elements of l2 to the front of l1
    
    // 6. List-specific algorithms (std::sort does NOT work on list)
    l1.sort();          // Sorts in O(N log N)
    l1.reverse();       // Reverses the list in O(N)
    l1.remove(100);     // Removes all occurrences of 100
    l1.unique();        // Removes adjacent duplicates
    
    return 0;
}
""",

    "03_deque.cpp": """#include <iostream>
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
""",

    "04_queue.cpp": """#include <iostream>
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
""",

    "05_stack.cpp": """#include <iostream>
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
""",

    "06_set.cpp": """#include <iostream>
#include <set>

using namespace std;

// Note: std::set (Ordered Set)
// - Implemented as a Self-Balancing Binary Search Tree (Red-Black Tree).
// - Elements are UNIQUE and ALWAYS sorted.
// - Insert/Erase/Find are O(log N).
int main() {
    set<int> s = {5, 2, 8, 2, 1}; // Initializes with {1, 2, 5, 8} (duplicates removed, sorted)
    
    // 1. Modifiers
    s.insert(10);
    s.erase(5); // Removes 5
    
    // 2. Search & Status
    cout << "Size: " << s.size() << endl;
    
    // Check if exists (C++20 adds .contains(), otherwise use .count() or .find())
    if (s.contains(8)) {
        cout << "8 is in the set!" << endl;
    }
    
    if (s.count(2) > 0) { // Returns 1 if present, 0 if not
        cout << "2 is in the set!" << endl;
    }
    
    // 3. Lower & Upper Bounds (O(log N) Binary Search)
    // lower_bound: iterator to first element >= val
    // upper_bound: iterator to first element > val
    auto it_low = s.lower_bound(2); // Points to 2
    auto it_up = s.upper_bound(2);  // Points to 8
    
    cout << "Lower bound of 2: " << *it_low << endl;
    cout << "Upper bound of 2: " << *it_up << endl;
    
    // 4. Iteration (In-order traversal)
    for (int num : s) {
        cout << num << " "; // 1 2 8 10
    }
    cout << endl;
    
    return 0;
}
""",

    "07_map.cpp": """#include <iostream>
#include <map>

using namespace std;

// Note: std::map (Ordered Map / Dictionary)
// - Red-Black Tree mapping Keys to Values.
// - Keys are UNIQUE and ALWAYS sorted.
// - O(log N) operations.
int main() {
    map<string, int> m;
    
    // 1. Insertion
    m["zebra"] = 100;    // operator[] inserts if key doesn't exist
    m["apple"] = 50;
    m.insert({"banana", 75});
    
    // 2. Modification
    m["apple"] = 55;     // Updates existing key
    m["apple"]++;        // Now 56
    
    // 3. Search
    if (m.contains("apple")) { // C++20
        cout << "Apple: " << m["apple"] << endl;
    }
    
    // Using find() (pre-C++20 or if you need the iterator)
    auto it = m.find("banana");
    if (it != m.end()) {
        cout << "Banana: " << it->second << endl;
    }
    
    // 4. Erase
    m.erase("zebra");
    
    // 5. Lower / Upper Bound on Keys
    m["cat"] = 10;
    m["dog"] = 20;
    auto l_bound = m.lower_bound("c"); // Points to "cat"
    cout << "First key >= 'c': " << l_bound->first << endl;
    
    // 6. Iteration (Alphabetical by Key)
    for (const auto& [key, val] : m) {
        cout << key << ": " << val << endl;
    }
    
    return 0;
}
""",

    "08_unordered_set.cpp": """#include <iostream>
#include <unordered_set>

using namespace std;

// Note: std::unordered_set (Hash Set)
// - Hash Table implementation.
// - Elements are UNIQUE and UNORDERED.
// - Average O(1) operations. Worst case O(N) on collision/rehash.
int main() {
    unordered_set<int> us = {5, 2, 8, 1};
    
    // 1. Capacity & Rehashing Optimizations
    // In LeetCode, if you know N <= 100,000, reserve space to prevent slow re-allocations!
    us.reserve(100000);
    
    cout << "Size: " << us.size() << endl;
    cout << "Bucket count: " << us.bucket_count() << endl;
    cout << "Load factor: " << us.load_factor() << endl;
    
    // 2. Modifiers
    us.insert(10);
    us.erase(5); // Returns 1 if removed, 0 if it didn't exist
    
    // 3. Search
    if (us.contains(8)) { // C++20
        cout << "8 is present!" << endl;
    }
    
    if (us.count(2)) { // C++11 standard check
        cout << "2 is present!" << endl;
    }
    
    // 4. Iteration (Random order!)
    for (int num : us) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
""",

    "09_unordered_map.cpp": """#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Note: std::unordered_map (Hash Map)
// - Hash Table mapping Keys to Values.
// - Keys are UNIQUE and UNORDERED.
// - Average O(1) operations. 
// - The undisputed MVP for 90% of LeetCode problems (Two Sum, Frequency Counting, etc).
int main() {
    unordered_map<string, int> um;
    
    // Optimization: Pre-allocate buckets if size is known
    um.reserve(1000);
    
    // 1. Insertion / Updating
    um["apple"] = 5;       
    um["banana"] = 10;
    
    // Counting frequencies is trivial:
    um["apple"]++; // If "apple" didn't exist, it would be created and initialized to 0, then incremented to 1.
    
    // 2. Search
    // DANGER: Never use `if (um["cherry"] > 0)` to check existence!
    // That will accidentally insert "cherry" into the map with a value of 0!
    
    // Safe ways to check existence:
    if (um.contains("apple")) { // C++20 (Cleanest)
        cout << "Apple count: " << um["apple"] << endl;
    }
    
    if (um.count("banana") > 0) { // C++11
        cout << "Banana exists!" << endl;
    }
    
    // 3. Iteration
    for (const auto& [key, val] : um) {
        cout << key << ": " << val << endl;
    }
    
    // 4. Erase
    um.erase("banana");
    
    return 0;
}
""",

    "10_priority_queue.cpp": """#include <iostream>
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
"""
}

for name, content in files.items():
    with open(os.path.join(STL_DIR, name), "w") as f:
        f.write(content)

print(f"Generated {len(files)} comprehensive STL examples.")
