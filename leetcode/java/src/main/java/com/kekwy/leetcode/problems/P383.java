package com.kekwy.leetcode.problems;

import java.util.HashMap;
import java.util.Map;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/19 15:50
 */
public class P383 {
    class Solution {

        private void countChar(String str, int[] table) {
            for (int i = 0; i < str.length(); i++) {
                table[str.charAt(i) - 'a']++;
            }
        }

        public boolean canConstruct(String ransomNote, String magazine) {
            int[] charTable1 = new int[26];
            int[] charTable2 = new int[26];
            countChar(ransomNote, charTable1);
            countChar(magazine, charTable2);
            for (int i = 0; i < 26; i++) {
                if (charTable1[i] > charTable2[i]) {
                    return false;
                }
            }
            return true;
        }
    }
}
