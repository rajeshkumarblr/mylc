package backtracking;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


/*
 * @lc app=leetcode id=46 lang=java
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
public class P46 {


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    public List<List<Integer>> permute(int[] nums) {

        List<List<Integer>> solution = new  ArrayList<> ();
        Set<Integer> used = new HashSet<>();
        backtrack(nums, solution, used, new ArrayList<>());
        return solution;
        
    }

    private void backtrack(int nums[],  List<List<Integer>> solution ,  Set<Integer> used , List<Integer> subList) {

        if(subList.size() == nums.length) {
            solution.add(new ArrayList<>(subList));
            System.out.println("adding sublist:"+ new ArrayList<>(subList));
            return;
        }

        for(int i : nums) {
            System.out.println("i:"+i);
          if(!used.contains(i)) { 
           used.add(i);
           subList.add(i);
           
           backtrack(nums, solution, used, subList);
           
           subList.remove(subList.size()-1);             
           used.remove(i);
          }
        }
    }
}
}
// @lc code=end
