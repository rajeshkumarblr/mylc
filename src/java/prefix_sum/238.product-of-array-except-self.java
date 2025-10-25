class P238 {
    // @lc app=leetcode id=238 lang=java
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

