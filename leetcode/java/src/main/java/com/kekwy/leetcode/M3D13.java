package com.kekwy.leetcode;

class P2864 {

    class Solution {
        public String maximumOddBinaryNumber(String s) {
            int count = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '1') count++;
            }
            return "1".repeat(count - 1) +
                   "0".repeat(s.length() - count) +
                   "1";
        }
    }

}
