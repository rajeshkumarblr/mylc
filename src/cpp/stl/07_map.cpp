#include <iostream>
#include <map>

using namespace std;

// Note: std::map (Ordered Map / Dictionary)
// - Red-Black Tree mapping Keys to Values.
// - Keys are UNIQUE and ALWAYS sorted.
// - O(log N) operations.
int main() {
  map<string, int> m;

  // 1. Insertion
  m["zebra"] = 100; // operator[] inserts if key doesn't exist
  m["apple"] = 50;
  m.insert({"banana", 75});

  // 2. Modification
  m["apple"] = 55; // Updates existing key
  m["apple"]++;    // Now 56

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
  for (const auto &[key, val] : m) {
    cout << key << ": " << val << endl;
  }

  auto u_bound = m.upper_bound("d"); // Points to "cat"
  cout << "Last key <= 'd': " << u_bound->first << " val: " << u_bound->second
       << endl;

  cout << "map size: " << m.size() << endl;

  cout << "map first:" << m.begin()->first << " map last: " << m.rbegin()->first
       << endl;

  return 0;
}
