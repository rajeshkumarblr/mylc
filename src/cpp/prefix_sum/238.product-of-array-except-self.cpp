#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=238 lang=cpp
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
 *
 * Description:
 * Given an integer array  nums , return  an array   answer   such that
 * answer[i]   is equal to the product of all the elements of   nums   except
 * nums[i] .
 *  The product of any prefix or suffix of  nums  is  guaranteed  to fit in a
 * 32-bit  integer.
 *  You must write an algorithm that runs in  O(n)  time and without using the
 * division operation.
 *   Example 1:
 *   Input:  nums = [1,2,3,4]
 *  Output:  [24,12,8,6]
 *    Example 2:
 *   Input:  nums = [-1,1,0,-3,3]
 *  Output:  [0,0,9,0,0]
 *   Constraints:
 *           2 <= nums.length <= 10 5
 *           -30 <= nums[i] <= 30
 *          The input is generated such that  answer[i]  is  guaranteed  to
 * fit in a  32-bit  integer.
 *   Follow up:  Can you solve the problem in  O(1)  extra space complexity?
 * (The output array  does not  count as extra space for space complexity
 * analysis.)
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Calculate left products
        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        // Calculate right products and multiply with left products
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return result;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
std::vector<int> productExceptSelf(std::vector<int>& nums) {
    Solution sol;
    return sol.productExceptSelf(nums);
}