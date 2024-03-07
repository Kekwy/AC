package com.kekwy.leetcode;

class P2917 {

    class Solution {
        public int findKOr(int[] nums, int k) {
            int i = 0;
            int res = 0;
            boolean flag = false;
            do {
                int count = 0;
                flag = false;
                for (int num : nums) {
                    int tmp = num >> i;
                    if (tmp == 0) continue;
                    if (tmp % 2 == 1) {
                        count++;
                    }
                    flag = true;
                }
                if (count >= k) {
                    res += 1 << i;
                }
                i++;
            } while (flag);
            return res;
        }
    }

}