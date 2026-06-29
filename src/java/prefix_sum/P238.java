package prefix_sum;
import common.*;


public class P238 {
/*
 * @lc app=leetcode id=238 lang=java
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit in a
 * 32-bit integer.
 *
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 *
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 *
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *
 * Constraints:
 * - 2 <= nums.length <= 10^5
 * - -30 <= nums[i] <= 30
 * - The product of any prefix or suffix of nums is guaranteed to fit in a
 *   32-bit integer.
 *
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The
 * output array does not count as extra space for space complexity analysis.)
 */
    // @lc code=start
    public class Solution {
    public int[] productExceptSelf(int[] nums) {
     if (nums == null | nums.length == 0) {
                return null;
            }

            //this is solved by doing left product with the right product
            // left product starts with 1 and leaves the last element
            //right product starts from 1 and leaves the 1st element

            int res [] = new int[nums.length];
            //[1,2,3,4]
            int leftProduct = 1;
            res[0] = 1;
            for(int i =0; i<nums.length-1;i++) {
                leftProduct *= nums[i];
                res[i+1] = leftProduct;
            }
            
            int rightProduct  =1;
            for(int i = nums.length -1; i >=0; i--){
                res[i] = rightProduct * res[i];
                rightProduct *= nums[i];
            }
            return res;   
    }
    }
    // @lc code=end
}

