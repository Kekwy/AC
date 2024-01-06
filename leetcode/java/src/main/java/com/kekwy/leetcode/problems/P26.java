package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/5 20:51
 */
public class P26 {

    class Solution {
        public int removeDuplicates(int[] nums) {
            int lp = 0, rp = 1;
            while (rp < nums.length) {
                if (nums[lp] != nums[rp]) nums[++lp] = nums[rp];
                rp++;
            }
            return lp + 1;
        }
    }

}
