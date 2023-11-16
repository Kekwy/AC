package com.kekwy.leetcode.p977;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/16 15:57
 */
public class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] res = new int[nums.length];
        int left = 0, right = nums.length - 1;
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];
        int i = nums.length - 1;
        while (left < right) {
            if (leftSquare > rightSquare) {
                res[i--] = leftSquare;
                left++;
                leftSquare = nums[left] * nums[left];
            } else {
                res[i--] = rightSquare;
                right--;
                rightSquare = nums[right] * nums[right];
            }
        }
        res[i] = leftSquare;
        return res;
    }
}
