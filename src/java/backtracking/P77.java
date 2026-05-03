package backtracking;

import java.util.ArrayList;
import java.util.List;


/*
 * @lc app=leetcode id=77 lang=java
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
public class P77 {

class Solution {

    public List<List<Integer>> combine(int n, int k) {

       List<List<Integer>> solution  = new ArrayList<>();
        backtrack(1, n, k, solution, new ArrayList<Integer>());
        return solution;

    }


    public void backtrack(int start, int n, int k,  List<List<Integer>> solution, List<Integer> currentState) {

        if(currentState.size() == k) {
           solution.add(new ArrayList<>(currentState));     
          // System.out.println("solution:"+solution);
           return; 
        }

       
        for(int i =start; i <= n; i ++) {
            currentState.add(i);
            // 1,2,3,4
            backtrack(i + 1, n, k, solution, currentState);
            currentState.remove(currentState.size()-1);      
           
        }

    }
}
}
// @lc code=end
