package com.kekwy.leetcode.p59;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/17 8:38
 */
public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int i = 1;
        int loop = 0;
        int m = n / 2;
        while (loop < m) {
            for (int j = loop; j < n - loop - 1; j++) {
                res[loop][j] = i;
                i++;
            }
            for (int j = loop; j < n - loop - 1; j++) {
                res[j][n - loop - 1] = i;
                i++;
            }
            for (int j = n - loop - 1; j > loop; j--) {
                res[n - loop - 1][j] = i;
                i++;
            }
            for (int j = n - loop - 1; j > loop; j--) {
                res[j][loop] = i;
                i++;
            }
            loop++;
        }
        if (n % 2 == 1) {
            res[m][m] = i;
        }
        return res;
    }
}
