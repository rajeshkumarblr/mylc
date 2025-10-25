class P35 {
    // @lc app=leetcode id=35 lang=java
    // @lc code=start
    public class Solution {
        public int searchInsert(int[] nums, int target) {
            int left = 0;
            int right = nums.length - 1;

            while(left <= right) {
                int mid = (left + right) / 2;
                int currentNumber = nums[mid];
                if(currentNumber == target){
                    return mid;
                }

                if(target > currentNumber) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return left;  
        }
    }
    // @lc code=end
}

