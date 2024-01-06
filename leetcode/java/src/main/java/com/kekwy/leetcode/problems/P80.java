package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/5 21:12
 */
public class P80 {

    Solution solution = new Solution();

    public Solution getSolution() {
        return solution;
    }

    public class Solution {
        public int removeDuplicates(int[] nums) {
            boolean isFirst = true;
            int lp = 0, rp = 1;
            while (rp < nums.length) {
                if (nums[lp] != nums[rp]) {
                    nums[++lp] = nums[rp];
                    isFirst = true;
                } else if (isFirst) {
                    nums[++lp] = nums[rp];
                    isFirst = false;
                }
                rp++;
            }
            return lp + 1;
        }
    }

}
