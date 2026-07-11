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

#include "../lc_test_utils.h"
#include <vector>
#include <string>

using namespace std;

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
