package com.kekwy.leetcode;

import java.util.*;

class P310 {

    class Solution {

        int minHeight = Integer.MAX_VALUE;

        private int helper(int curr, int from, Map<Integer, Map<Integer, Integer>> edges) {
            if (!edges.containsKey(curr)) return 1;
            int h = 0;
            Map<Integer, Integer> map = edges.get(curr);
            for (Integer ch : map.keySet()) {
                if (ch == from) continue;
                if (map.get(ch) == -1)
                    map.put(ch, helper(ch, curr, edges));
                h = Math.max(h, 1 + map.get(ch));
                if (h > minHeight) return h;
            }
            return h;
        }

        public List<Integer> findMinHeightTrees(int n, int[][] edges) {
            Map<Integer, Map<Integer, Integer>> edgesMap = new HashMap<>();
            for (int[] edge : edges) {
                Map<Integer, Integer> map = edgesMap.getOrDefault(edge[0], new HashMap<>());
                map.put(edge[1], -1);
                edgesMap.put(edge[0], map);
                map = edgesMap.getOrDefault(edge[1], new HashMap<>());
                map.put(edge[0], -1);
                edgesMap.put(edge[1], map);
            }
            List<Integer> res = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int tmp = helper(i, -1, edgesMap);
                if (tmp < minHeight) {
                    res.clear();
                    res.add(i);
                    minHeight = tmp;
                } else if (tmp == minHeight) {
                    res.add(i);
                }
            }
            return res;
        }
    }

}

class P332 {

    /**
     * 存在相同起始与终止地的机票
     */
    class Solution {

        Map<String, Map<String, Integer>> ticketMap = new HashMap<>();
        LinkedList<String> result = new LinkedList<>();
        int total;

        private boolean helper() {
            if (total == result.size()) {
                return true;
            }
            if (!ticketMap.containsKey(result.getLast())) {
                return false;
            }
            for (Map.Entry<String, Integer> entry : ticketMap.get(result.getLast()).entrySet()) {
                if (entry.getValue() > 0) {
                    entry.setValue(entry.getValue() - 1);
                    result.add(entry.getKey());
                    if (helper()) {
                        return true;
                    }
                    result.removeLast();
                    entry.setValue(entry.getValue() + 1);
                }
            }
            return false;
        }

        public List<String> findItinerary(List<List<String>> tickets) {
            total = tickets.size() + 1;
            for (List<String> ticket : tickets) {
                Map<String, Integer> map = ticketMap.getOrDefault(ticket.get(0), new TreeMap<>());
                map.put(ticket.get(1), map.getOrDefault(ticket.get(1), 0) + 1);
                ticketMap.put(ticket.get(0), map);
            }
            result.add("JFK");
            helper();
            return result;
        }
    }

}

class P51 {
    class Solution {

        private char[][] board;

        private final List<List<String>> res = new ArrayList<>();

        private void helper(int i, int n) {
            if (i == n) {
                List<String> tmp = new LinkedList<>();
                for (char[] chars : board) {
                    StringBuilder builder = new StringBuilder();
                    for (char c : chars) {
                        builder.append(c);
                    }
                    tmp.add(builder.toString());
                }
                res.add(tmp);
            }
            for (int j = 0; j < n; j++) {
                boolean flag = true;
                // 检查列
                for (int k = i - 1; k >= 0; k--) {
                    if (board[k][j] == 'Q') {
                        flag = false;
                        break;
                    }
                }
                // 检查对角线1
                for (int k = i - 1, l = j - 1; flag && k >= 0 && l >= 0; k--, l--) {
                    if (board[k][l] == 'Q') {
                        flag = false;
                        break;
                    }
                }
                // 检查对角线2
                for (int k = i - 1, l = j + 1; flag && k >= 0 && l < n; k--, l++) {
                    if (board[k][l] == 'Q') {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                board[i][j] = 'Q';
                helper(i + 1, n);
                board[i][j] = '.';
            }
        }

        public List<List<String>> solveNQueens(int n) {
            board = new char[n][n];
            for (char[] chars : board) {
                Arrays.fill(chars, '.');
            }
            helper(0, n);
            return res;
        }
    }
}

class P303 {

    class NumArray {

        private final int[] nums;

        public NumArray(int[] nums) {
            this.nums = nums;
        }

        public int sumRange(int left, int right) {
            int sum = 0;
            for (int i = left; i <= right; i++) {
                sum += nums[i];
            }
            return sum;
        }
    }

}

class P37 {

    class Solution {

        private boolean isValid(char[][] board, int i, int j, int n, char c) {
            // 判断行
            for (int k = 0; k < n; k++) {
                if (board[i][k] == c) return false;
            }
            // 判断列
            for (int k = 0; k < n; k++) {
                if (board[k][j] == c) return false;
            }
            // 判断九宫格
//            int bi = i / 3, bj = j / 3; bugfix
            int bi = i / 3 * 3, bj = j / 3 * 3;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (board[bi + k][bj + l] == c) return false;
                }
            }
            return true;
        }

        private boolean helper(char[][] board, int i, int j, int n) {
            for (int k = i; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (board[k][l] != '.') continue;
                    for (char m = '1'; m <= '9'; m++) {
                        if (!isValid(board, k, l, n, m)) continue;
                        board[k][l] = m;
                        int ni = k, nj = (l + 1) % n;
                        if (nj == 0) ni++;
                        if (helper(board, ni, nj, n)) return true;
                        board[k][l] = '.';
                    }

                    return false;
                }
            }
            return true;
        }

        public void solveSudoku(char[][] board) {
            helper(board, 0, 0, board.length);
        }
    }

}