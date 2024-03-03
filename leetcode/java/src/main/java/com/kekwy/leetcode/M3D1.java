package com.kekwy.leetcode;

import org.junit.jupiter.api.Test;

import java.util.*;

class P93 {

    class Solution {

        private List<String> res = new LinkedList<>();

        private void helper(String s, String ip, int k, int index) {
            if (k == 0) {
                String substring = s.substring(index);
                if (substring.length() > 3 || substring.charAt(0) == '0' && substring.length() > 1) return;
                if (Integer.parseInt(substring) < 256) {
                    res.add(ip + substring);
                }
            } else {
                for (int i = index; i < s.length() - 1 && i - index < 3; i++) {
                    String substring = s.substring(index, i + 1);
                    if (Integer.parseInt(substring) < 256) {
                        helper(s, ip + substring + ".", k - 1, i + 1);
                    }
                    if (s.charAt(index) == '0') break;
                }
            }
        }

        public List<String> restoreIpAddresses(String s) {
            helper(s, "", 3, 0);
            return res;
        }
    }

    @Test
    public void test() {
        Solution solution = new Solution();
        System.out.println(solution.restoreIpAddresses("0279245587303"));
    }

}

class P78 {

    class Solution {

        private List<List<Integer>> res = new LinkedList<>();

        private LinkedList<Integer> subSet = new LinkedList<>();

        private void helper(int[] nums, int index) {
            if (index >= nums.length) {
                res.add(List.copyOf(subSet));
            } else {
                subSet.add(nums[index]);
                helper(nums, index + 1);
                subSet.removeLast();
                helper(nums, index + 1);
            }
        }

        public List<List<Integer>> subsets(int[] nums) {
            helper(nums, 0);
            return res;
        }
    }

}

class P90 {

    class Solution {

        private List<List<Integer>> res = new LinkedList<>();
        private LinkedList<Integer> subSet = new LinkedList<>();

        private void helper(int[] nums, int index) {
            res.add(List.copyOf(subSet));
            for (int i = index; i < nums.length; i++) {
                if (i > index && nums[i] == nums[i - 1]) {
                    continue;
                }
                subSet.add(nums[i]);
                helper(nums, i + 1);
                subSet.removeLast();
            }
        }

        private void quickSort(int[] nums, int begin, int end) {
            if (begin >= end) return;
            int pivot = nums[begin];
            int lp = begin;
            int rp = end - 1;
            while (lp < rp) {
                while (lp < rp && nums[rp] >= pivot) rp--;
                if (lp < rp) nums[lp++] = nums[rp];
                while (lp < rp && nums[lp] <= pivot) lp++;
                if (lp < rp) nums[rp--] = nums[lp];
            }
            nums[lp] = pivot;
            quickSort(nums, begin, lp);
            quickSort(nums, lp + 1, end);
        }

        public List<List<Integer>> subsetsWithDup(int[] nums) {
            quickSort(nums, 0, nums.length);
            helper(nums, 0);
            return res;
        }
    }

    @Test
    public void test() {
        Solution solution = new Solution();
        System.out.println(solution.subsetsWithDup(new int[]{1, 2, 2}));
    }

}

class P491 {
    class Solution {

        private List<List<Integer>> res = new LinkedList<>();
        private LinkedList<Integer> subSequence = new LinkedList<>();

        private void helper(int[] nums, int index) {
            if (subSequence.size() >= 2) res.add(List.copyOf(subSequence));
            Set<Integer> set = new HashSet<>();
            for (int i = index; i < nums.length; i++) {
                if (set.contains(nums[i])) {
                    continue;
                }
                set.add(nums[i]);
                if (subSequence.isEmpty() || nums[i] >= subSequence.getLast()) {
                    subSequence.add(nums[i]);
                    helper(nums, i + 1);
                    subSequence.removeLast();
                }
            }
        }

        public List<List<Integer>> findSubsequences(int[] nums) {
            helper(nums, 0);
            return res;
        }
    }
}

class LCCI_16_25 {

    class LRUCache {

        private static class Node {
            int val;
            Node next;
            Node prev;

            public Node() {
                val = 0;
                next = null;
                prev = null;
            }

            Node(int val) {
                this.val = val;
                next = null;
                prev = null;
            }
        }

        private final Map<Integer, Node> keyMap;
        private final Node dummyHead;
        private final Node dummyTail;
        private final int capacity;
        private int size;

        public LRUCache(int capacity) {
            dummyHead = new Node();
            dummyTail = new Node();
            keyMap = new HashMap<>();
            dummyHead.next = dummyTail;
            dummyTail.prev = dummyHead;
            size = 0;
            this.capacity = capacity;
        }

        private void deleteNode(Node node) {
            node.prev.next = node.next;
            if (node.next != null) {
                node.next.prev = node.prev;
            }
        }

        private void insertNode(Node prev, Node node) {
            node.next = prev.next;
            prev.next = node;
            node.prev = prev;
        }

        public int get(int key) {
            if (keyMap.containsKey(key)) {
                Node node = keyMap.get(key);
                deleteNode(node);
                insertNode(dummyHead, node);
                return node.val;
            } else {
                return -1;
            }
        }

        public void put(int key, int value) {
//            if (keyMap.containsKey())
//                if (size > capacity) {
//
//                } else {
//
//                }
        }
    }

}

class P46 {
    class Solution {

        private List<List<Integer>> res = new LinkedList<>();
        private LinkedList<Integer> permutation = new LinkedList<>();
        private boolean[] used;

        private void helper(int[] nums) {
            if (permutation.size() >= nums.length) {
                res.add(List.copyOf(permutation));
            } else {
                for (int i = 0; i < nums.length; i++) {
                    if (!used[i]) {
                        used[i] = true;
                        permutation.add(nums[i]);
                        helper(nums);
                        permutation.removeLast();
                        used[i] = false;
                    }
                }
            }
        }

        public List<List<Integer>> permute(int[] nums) {
            used = new boolean[nums.length];
            helper(nums);
            return res;
        }
    }
}

class P47 {
    class Solution {

        private List<List<Integer>> res = new LinkedList<>();
        private LinkedList<Integer> permutation = new LinkedList<>();
        private boolean[] used;

        private void helper(int[] nums) {
            if (permutation.size() >= nums.length) {
                res.add(List.copyOf(permutation));
            } else {
                for (int i = 0; i < nums.length; i++) {
                    if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
                    if (!used[i]) {
                        used[i] = true;
                        permutation.add(nums[i]);
                        helper(nums);
                        permutation.removeLast();
                        used[i] = false;
                    }
                }
            }
        }

        public List<List<Integer>> permuteUnique(int[] nums) {
            int[] array = Arrays.stream(nums).sorted().toArray();
            used = new boolean[array.length];
            helper(array);
            return res;
        }
    }

    @Test
    public void test() {
        Solution solution = new Solution();
        System.out.println(solution.permuteUnique(new int[]{1, 2, 2}));
    }

}


class P2368 {

    class Solution {

        private int res = 0;

        private void helper(int n, int node, List<List<Integer>> edges, boolean[] isRestricted) {
            res++;
            isRestricted[node] = true;
            for (Integer i : edges.get(node)) {
                if (!isRestricted[i]) {
                    helper(n, i, edges, isRestricted);
                }
            }
        }

        public int reachableNodes(int n, int[][] edges, int[] restricted) {
            boolean[] isRestricted = new boolean[n];
            List<List<Integer>> edgeList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                edgeList.add(new ArrayList<>());
            }
            for (int i : restricted) {
                isRestricted[i] = true;
            }
            for (int[] edge : edges) {
                edgeList.get(edge[0]).add(edge[1]);
                edgeList.get(edge[1]).add(edge[0]);
            }
            helper(n, 0, edgeList, isRestricted);
            return res;
        }
    }

    @Test
    public void test() {
        Solution solution = new Solution();
        System.out.println(
                solution.reachableNodes(
                        7, new int[][]{{0, 1}, {1, 2}, {3, 1}, {4, 0}, {0, 5}, {5, 6}}, new int[]{4, 5}
                )
        );
    }

}


