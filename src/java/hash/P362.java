package hash;

import java.util.*;

/*
 * @lc app=leetcode id=362 lang=java
 *
 * [362] Design Hit Counter
 * 
 * Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).
 * - hit(int timestamp) Record a hit at timestamp (in seconds).
 * - getHits(int timestamp) Return the number of hits in the past 5 minutes (from timestamp - 299 to timestamp).
 * 
 * Example:
 * HitCounter counter = new HitCounter();
 * counter.hit(1);
 * counter.hit(2);
 * counter.hit(3);
 * counter.getHits(4);   // return 3
 * counter.hit(300);
 * counter.getHits(300); // return 4
 * counter.getHits(301); // return 3
 * 
 * URL: https://leetcode.com/problems/design-hit-counter/
 */

// @lc code=start

public class P362 {

    Queue<Integer> window;

    public P362() {
        window = new LinkedList<>();
    }

    /**
     * @param timestamp The current timestamp (in seconds).
     */
    public void hit(int timestamp) {
        while (!window.isEmpty() && window.peek() < timestamp - 299) {
            window.poll();
        }
        window.offer(timestamp);
    }

    /**
     * @param timestamp The current timestamp (in seconds).
     * @return The number of hits in the past 5 minutes.
     */
    public int getHits(int timestamp) {
        while (!window.isEmpty() && window.peek() < timestamp - 299) {
            window.poll();
        }
        return window.size();
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * P362 obj = new P362();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
// @lc code=end
