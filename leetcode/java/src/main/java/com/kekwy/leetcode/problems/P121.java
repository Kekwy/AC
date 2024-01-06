package com.kekwy.leetcode.problems;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/6 19:46
 */
public class P121 {

    class Solution {
        /**
         * 遍历 prices 数组，
         * 并维护一个变量表示当前遍历到的元素之前的所有元素中最小的元素，
         * 将每个元素与数组中位于其之前的所有元素中最小的元素作差，
         * 其中最大的差值即为所求解。
         */
        public int maxProfit(int[] prices) {
            int min = prices[0], res = 0;
            for (int i = 1; i < prices.length; i++) {
                if (prices[i] > min) {
                    int tmp = prices[i] - min;
                    if (tmp > res) res = tmp;
                } else {
                    min = prices[i];
                }
            }
            return res;
        }
    }

}
