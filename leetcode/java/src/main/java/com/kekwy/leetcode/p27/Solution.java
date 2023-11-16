package com.kekwy.leetcode.p27;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/16 15:50
 */
public class Solution {
    public int removeElement(int[] nums, int val) {
        int left = 0, right = nums.length - 1;
        while (left <= right && nums[right] == val) right--;
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right];
                right--;
                while (left <= right && nums[right] == val) right--;
            }
            left++;
        }
        return right + 1;
    }
}
