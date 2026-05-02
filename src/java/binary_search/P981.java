package binary_search;

import java.util.*;
import java.util.ArrayList;

/**
 * 981. Time Based Key-Value Store
 * Difficulty: Medium
 * 
 * Problem:
 * Design a time-based key-value data structure that can store multiple values
 * for the same key at different time stamps and retrieve the key's value at
 * a certain timestamp.
 * 
 * Implement the `TimeMap` class:
 * - `TimeMap()` Initializes the object of the data structure.
 * - `void set(String key, String value, int timestamp)` Stores the key `key`
 * with the value `value` at the given time `timestamp`.
 * - `String get(String key, int timestamp)` Returns a value such that `set` was
 * called previously, with `timestamp_prev <= timestamp`. If there are multiple
 * such values, it returns the value associated with the largest
 * `timestamp_prev`.
 * If there are no values, it returns "".
 * 
 * Example 1:
 * Input:
 * ["TimeMap", "set", "get", "get", "set", "get", "get"]
 * [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo",
 * 4], ["foo", 5]]
 * Output:
 * [null, null, "bar", "bar", null, "bar2", "bar2"]
 */
public class P981 {

    // @lc app=leetcode id=981 lang=java
    // @lc code=start
    public static class TimeMap {
        class Data {
            Integer timesatamp;
            String data;

            Data(int t, String v) {
                this.timesatamp = t;
                this.data = v;
            }
        };

        Map<String, ArrayList<Data>> map;

        public TimeMap() {
            map = new HashMap<String, ArrayList<Data>>();
        }

        public String getDataForTimeStamp(ArrayList<Data> list, Integer timesatamp) {
            int l = 0;
            int r = list.size() - 1;
            String res = "";
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (list.get(m).timesatamp <= timesatamp) {
                    res = list.get(m).data;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            return res;
        }

        public void set(String key, String value, int timestamp) {
            ArrayList<Data> list;
            Data data = new Data(timestamp, value);
            if (map.containsKey(key)) {
                list = map.get(key);
                if (list == null) {
                    list = new ArrayList<>();
                }
                list.add(data);
            } else {
                list = new ArrayList<>();
                list.add(data);
                map.put(key, list);
            }
        }

        public String get(String key, int timestamp) {
            String res = "";
            if (map.containsKey(key)) {
                res = getDataForTimeStamp(map.get(key), timestamp);
            }
            return res;
        }
    }
    // @lc code=end

    // Non-static wrapper for driver compatibility (if needed)
    public TimeMap createTimeMap() {
        return new TimeMap();
    }
}
