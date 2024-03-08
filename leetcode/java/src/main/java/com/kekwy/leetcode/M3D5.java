package com.kekwy.leetcode;

import java.util.HashMap;
import java.util.Map;

class P1976 {
    class Solution {

        public int countPaths(int n, int[][] roads) {
            int NUMBER = (int) (10e9 + 7);
            Map<Integer, Map<Integer, Integer>> map = new HashMap<>();

            boolean flag = false;

            do {
                for (int[] road : roads) {
                    int u = road[0];
                    int v = road[1];
                    int time = road[2];
                }
            } while (flag);

            int res = 1;
            Map<Integer, Integer> resMap = map.get(n - 1);
            for (Integer key : resMap.keySet()) {
                res = (res * resMap.get(key)) % NUMBER;
            }
            return res;
        }
    }
}
