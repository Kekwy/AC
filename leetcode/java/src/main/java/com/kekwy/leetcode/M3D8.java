package com.kekwy.leetcode;

import org.junit.jupiter.api.Test;

class P2834 {

    /* 构式 */
    class Solution {
        private int getModSum(int begin, int end, int m) {
            return (int) ((long) (begin + end) * (end - begin + 1) / 2 % m);
        }

        public int minimumPossibleSum(int n, int target) {
            int m = (int) (1e9 + 7);
            int mid = (target - 1) / 2;
            if (target % 2 == 0) mid++;
            if (mid >= n)
                return getModSum(1, n, m);
            int sum = getModSum(1, mid, m);
            int left = n - mid;
            sum = (sum + getModSum(target, target + left - 1, m)) % m;
            return sum;
        }
    }

    @Test
    public void test() {
        Solution solution = new Solution();
        solution.minimumPossibleSum(1000000000, 1000000000);
    }

}
