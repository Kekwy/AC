package com.kekwy.leetcode.p209;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/16 16:16
 */
public class Solution {

    public int minSubArrayLen(int target, int[] nums) {
        int minLen = Integer.MAX_VALUE, curLen = 0;
        int sum = 0;
        int left = 0, right = 0;
        while (right < nums.length) {
            sum += nums[right++];
            curLen++;
            while (sum >= target) {
                if (curLen < minLen) minLen = curLen;
                curLen--;
                sum -= nums[left++];
            }
        }
        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }

}
