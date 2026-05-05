package hash;

import java.util.*;

/**
 * Problem Statement: API Rate Limiter (Sliding Window)
 * 
 * Description:
 * You are tasked with building a rate limiter for an API. You are given an
 * array of logs
 * representing incoming requests, and an integer limit.
 * Each string in the logs array is formatted as "[ClientName] [Timestamp]",
 * where
 * Timestamp is the time of the request in minutes from system start.
 * The limit represents the maximum number of successful requests a client is
 * allowed
 * to make within any 60-minute sliding window.
 * 
 * When a request arrives:
 * 1. If the client has made fewer than limit successful requests in the past 60
 * minutes
 * (i.e., in the time range (timestamp - 60, timestamp]), the request is
 * allowed.
 * 2. If the client has already reached the limit within that time range, the
 * request
 * is denied and dropped. (Note: Denied requests do not count toward the limit
 * of future windows).
 * 
 * Task:
 * Write a function that processes the logs and returns an array of strings
 * showing
 * the total number of allowed requests for each client. The output array must
 * be
 * formatted as "[ClientName] [AllowedCount]" and must retain the order in which
 * the clients first appeared in the logs.
 * 
 * Assumptions:
 * - The logs are chronologically sorted by timestamp.
 * - Timestamps are strictly positive integers.
 */
public class ApiRateLimiter {

    /**
     * Processes the logs and returns the count of allowed requests for each client.
     * 
     * @param logs  Array of strings formatted as "[ClientName] [Timestamp]"
     * @param limit Maximum allowed requests in a 60-minute sliding window
     * @return Array of strings formatted as "[ClientName] [AllowedCount]"
     */
    public String[] getRateLimitStatus(String[] logs, int limit) {
        Map<String, Queue<Integer>> clientWindows = new HashMap<>();
        Map<String, Integer> allowedCounts = new LinkedHashMap<>();
        for (String log : logs) {
            String parts[] = log.split(" ");
            String client = parts[0];
            int timestamp = Integer.parseInt(parts[1]);
            clientWindows.putIfAbsent(client, new LinkedList<>());
            allowedCounts.putIfAbsent(client, 0);

            Queue<Integer> window = clientWindows.get(client);
            while (!window.isEmpty() && window.peek() <= timestamp - 60) {
                window.poll();
            }

            if (window.size() < limit) {
                window.offer(timestamp);
                allowedCounts.put(client, allowedCounts.get(client) + 1);
            }
        }

        String results[] = new String[allowedCounts.size()];
        int index = 0;
        for (String name : allowedCounts.keySet()) {
            String result = name + " " + allowedCounts.get(name);
            results[index++] = result;
        }

        return results;
    }

    public static void main(String[] args) {
        ApiRateLimiter limiter = new ApiRateLimiter();

        // Sample Test Case
        String[] logs = {
                "A 10",
                "A 20",
                "B 25",
                "A 30",
                "A 75",
                "B 80"
        };
        int limit = 2; // Each client allowed 2 requests per 60 mins

        /*
         * Expected Analysis:
         * A 10: Allowed (Total A: 1)
         * A 20: Allowed (Total A: 2)
         * B 25: Allowed (Total B: 1)
         * A 30: Denied (Window is (-30, 30]. Allowed at 10, 20 are both in. 2 >= 2)
         * A 75: Allowed (Window is (15, 75]. Allowed at 20 is in, 10 is out. 1 < 2.
         * Total A: 3)
         * B 80: Allowed (Window is (20, 80]. Allowed at 25 is in. 1 < 2. Total B: 2)
         * 
         * Expected Output:
         * ["A 3", "B 2"]
         */

        String[] result = limiter.getRateLimitStatus(logs, limit);

        System.out.println("Rate Limiter Results:");
        if (result.length == 0) {
            System.out.println("[] (Implement the logic to see results)");
        } else {
            for (String status : result) {
                System.out.println(status);
            }
        }
    }
}
