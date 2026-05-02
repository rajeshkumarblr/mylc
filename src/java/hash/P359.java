package hash;

import java.util.*;

/*
 * @lc app=leetcode id=359 lang=java
 *
 * [359] Logger Rate Limiter
 * 
 * Problem Description:
 * Design a logger system that receives a stream of messages along with their timestamps. 
 * Each unique message should only be printed at most every 10 seconds (i.e., a message printed 
 * at timestamp t will prevent other identical messages from being printed until timestamp t + 10).
 * All messages will come in chronological order. Several messages may arrive at the same timestamp.
 * 
 * Example:
 * Input:
 * ["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
 * [[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
 * Output:
 * [null, true, true, false, false, false, true]
 * 
 * URL: https://leetcode.com/problems/logger-rate-limiter/
 */

// @lc code=start

public class P359 {

    Map<String, Integer> map;

    public P359() {
        map = new HashMap<>();
    }

    /**
     * Returns true if the message should be printed in the given timestamp,
     * otherwise returns false.
     * 
     * Example:
     * shouldPrintMessage(1, "foo") -> returns true (next allowed timestamp for
     * "foo" is 11)
     * shouldPrintMessage(2, "bar") -> returns true (next allowed timestamp for
     * "bar" is 12)
     * shouldPrintMessage(3, "foo") -> returns false (3 < 11)
     * shouldPrintMessage(8, "bar") -> returns false (8 < 12)
     * shouldPrintMessage(10, "foo") -> returns false (10 < 11)
     * shouldPrintMessage(11, "foo") -> returns true (11 >= 11, next allowed
     * timestamp is 21)
     * 
     * @param timestamp The timestamp in seconds granularity.
     * @param message   The message to be printed.
     * @return true if the message should be printed, false otherwise.
     */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if (!map.containsKey(message) || map.get(message) <= timestamp) {
            map.put(message, timestamp + 10);
            return true;
        }
        return false;
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * P359 obj = new P359();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */
// @lc code=end
