package backtracking;

import java.util.ArrayList;
import java.util.List;


/*
 * @lc app=leetcode id=47 lang=java
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
public class P47 {


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> solution = new ArrayList<>();
        List<Integer> visited = new ArrayList<>();
        backtrack(nums, solution, new ArrayList<>(), visited);
        return solution;

    }

    private void backtrack(int nums[],  List<List<Integer>> solution, List<Integer> subList , List<Integer> visited){

        if(subList.size() == nums.length) {
            if( !solution.contains(subList)) solution.add(new ArrayList<>(subList));
            return;
        }

        for(int i=0; i< nums.length; i++) {
            if(!visited.contains(i)) {
                visited.add(i);
                subList.add(nums[i]);

                backtrack( nums, solution,subList,visited);

                subList.remove(subList.size()-1);
                visited.remove(visited.size()-1);
            }

        }
    }
}
}
// @lc code=end
