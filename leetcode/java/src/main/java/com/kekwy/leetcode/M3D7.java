package com.kekwy.leetcode;

class P2575 {

    class Solution {
        public int[] divisibilityArray(String word, int m) {
            long n = 0;
            int[] res = new int[word.length()];
            for (int i = 0; i < word.length(); i++) {
                n = (n * 10 + (word.charAt(i) - '0')) % m;
                if (n == 0) {
                    res[i] = 1;
                }
            }
            return res;
        }
    }

}