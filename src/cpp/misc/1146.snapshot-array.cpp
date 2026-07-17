#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <nlohmann/json.hpp>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 *
 * Problem Description:
 * Implement a SnapshotArray that supports the following interface:
 * - SnapshotArray(int length) Initializes a member-like data structure with the given length. 
 *   Initially, each element equals 0.
 * - void set(index, val) Sets the element at the given index to be equal to val.
 *   Note: Multiple sets on the same index between snapshots only save the final value.
 * - int snap() Takes a snapshot of the array and returns the snap_id: the total number of times 
 *   we called snap() minus 1.
 * - int get(index, snap_id) Returns the value at the given index, at the time we took the snapshot 
 *   with the given snap_id.
 *
 * Examples:
 * Input:
 * ["SnapshotArray", "set", "snap", "set", "get"]
 * [[3], [0, 5], [], [0, 6], [0, 0]]
 * Output:
 * [null, null, 0, null, 5]
 *
 * Explanation:
 * SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
 * snapshotArr.set(0, 5);  // Set array[0] = 5
 * snapshotArr.snap();     // Take a snapshot, return snap_id = 0
 * snapshotArr.set(0, 6);
 * snapshotArr.get(0, 0);  // Get the value of array[0] with snap_id = 0, return 5
 *
 * Constraints:
 * - 1 <= length <= 50,000
 * - 0 <= index < length
 * - 0 <= val <= 10^9
 * - 0 <= snap_id < (total number of times snap() has been called)
 * - At most 50,000 calls will be made to set, snap, and get.
 */

#include <vector>
#include <string>
using namespace std;
using json = nlohmann::json;

vector<string> runSnapshotArray(const vector<string> &cmds, const json &args);

using json = nlohmann::json;

vector<string> runSnapshotArray(const vector<string> &cmds, const json &args);

using json = nlohmann::json;

vector<string> runSnapshotArray(const vector<string> &cmds, const json &args);

using json = nlohmann::json;

vector<string> runSnapshotArray(const vector<string> &cmds, const json &args);

using json = nlohmann::json;

vector<string> runSnapshotArray(const vector<string> &cmds, const json &args);



// @lc code=start
class SnapshotArray {
public:
    SnapshotArray(int length) {
        // TODO: Initialize your snapshot array structures
    }
    
    void set(int index, int val) {
        // TODO: Set index to val at current snapshot
    }
    
    int snap() {
        // TODO: Increment snap_id and return previous snap_id
        return 0;
    }
    
    int get(int index, int snap_id) {
        // TODO: Retrieve value at index for the specific snap_id
        return 0;
    }
};
// @lc code=end
















vector<string> runSnapshotArray(const vector<string> &cmds, const json &args) {
    SnapshotArray *sa = nullptr;
    vector<string> res;
    for (size_t i = 0; i < cmds.size(); ++i) {
        if (cmds[i] == "SnapshotArray") {
            int length = args[i][0].get<int>();
            sa = new SnapshotArray(length);
            res.push_back("null");
        } else if (cmds[i] == "set") {
            int index = args[i][0].get<int>();
            int val = args[i][1].get<int>();
            sa->set(index, val);
            res.push_back("null");
        } else if (cmds[i] == "snap") {
            res.push_back(to_string(sa->snap()));
        } else if (cmds[i] == "get") {
            int index = args[i][0].get<int>();
            int snap_id = args[i][1].get<int>();
            res.push_back(to_string(sa->get(index, snap_id)));
        }
    }
    delete sa;
    return res;
}





int main() {
    try {
        json j = json::parse(R"raw({
  "cases": [
    {
      "commands": [
        "SnapshotArray",
        "set",
        "snap",
        "set",
        "get"
      ],
      "arguments": [
        [
          3
        ],
        [
          0,
          5
        ],
        [],
        [
          0,
          6
        ],
        [
          0,
          0
        ]
      ],
      "expected": [
        null,
        null,
        0,
        null,
        5
      ]
    }
  ]
})raw");
        for (const auto &tc : j.at("cases")) {
            const auto &commands = tc.at("commands");
            const auto &args = tc.contains("arguments") ? tc.at("arguments") : tc.at("args");
            const auto &expected = tc.at("expected");
            SnapshotArray* obj = nullptr;
            for (size_t i = 0; i < commands.size(); ++i) {
                string cmd = commands[i].get<string>();
                if (cmd == "SnapshotArray") {
                    if (obj) delete obj;
                    obj = new SnapshotArray(args[i][0].get<int>());
                } else if (cmd == "set") {
                    obj->set(args[i][0].get<int>(), args[i][1].get<int>());
                } else if (cmd == "snap") {
                    int got = obj->snap();
                    if (!expected[i].is_null()) {
                        int exp = expected[i].get<int>();
                        if (got != exp) { cerr << "FAIL snap" << endl; return 1; }
                    }
                } else if (cmd == "get") {
                    int got = obj->get(args[i][0].get<int>(), args[i][1].get<int>());
                    if (!expected[i].is_null()) {
                        int exp = expected[i].get<int>();
                        if (got != exp) { cerr << "FAIL get" << endl; return 1; }
                    }
                }
            }
            if (obj) delete obj;
        }
        cout << "PASS" << endl;
        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 4;
    }
}
