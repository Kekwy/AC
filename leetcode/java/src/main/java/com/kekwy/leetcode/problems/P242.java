package com.kekwy.leetcode.problems;

import java.util.Iterator;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2023/11/19 7:54
 */
public class P242 {
    class Solution {
        public boolean isAnagram(String s, String t) {
            int[] hashTableS = new int[26];
            int[] hashTableT = new int[26];
            for (int i = 0; i < s.length(); i++) {
                hashTableS[s.charAt(i) - 'a']++;
            }
            for (int i = 0; i < t.length(); i++) {
                hashTableT[t.charAt(i) - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (hashTableS[i] != hashTableT[i]) {
                    return false;
                }
            }
            return true;
        }
    }
}
