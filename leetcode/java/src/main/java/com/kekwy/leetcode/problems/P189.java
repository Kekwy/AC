package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/6 19:25
 */
public class P189 {
    class Solution {

        private void reverse(int[] nums, int begin, int end) {
            int lp = begin, rp = end - 1;
            while (lp < rp) {
                int temp = nums[lp];
                nums[lp] = nums[rp];
                nums[rp] = temp;
                lp++;
                rp--;
            }
        }

        /**
         * 整个数组反转一次，
         * 取 t = k % n
         * 再将反转数组的前 t 个元素后 n - t 个元素分别反转一次
         */
        public void rotate(int[] nums, int k) {
            int t = k % nums.length;
            reverse(nums, 0, nums.length);
            reverse(nums, 0, t);
            reverse(nums, t, nums.length);
        }
    }
}
