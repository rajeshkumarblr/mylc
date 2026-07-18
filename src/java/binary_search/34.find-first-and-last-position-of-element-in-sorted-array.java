/*
 * @lc app=leetcode id=34 lang=java
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int [] ret = {-1, -1};
        int leftIndex = getLeftIndex( nums, target);
        int rightIndex = getRightIndex( nums, target);
        ret[0] = leftIndex;
        ret[1] = rightIndex;
        return ret;
    }


    private int getLeftIndex(int [] nums, int target) {
        int left  =0, right = nums.length -1;
        int index = -1;
        while(left <=right) {
            int mid = (left + right )/2;

            if(nums[mid] == target) {
                index  = mid;
                right = mid -1;
           } else if (nums[mid] > target) {
                 right = mid -1;
           } else {
                left = mid +1;
           }

        }
        return index;
    }

       private int getRightIndex(int [] nums, int target) {
        int left  =0, right = nums.length -1;
        int index = -1;
        while(left <=right) {
            int mid = (left + right )/2;

            if(nums[mid] == target) {
                index  = mid;
                left = mid +1;
           } else if (nums[mid] > target) {
                 right = mid -1;
           } else {
                left = mid +1;
           }

        }
        return index;
    }
}
// @lc code=end

