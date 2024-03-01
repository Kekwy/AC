package com.kekwy.leetcode;

import org.junit.jupiter.api.Test;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

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
            Set<Integer> used = new HashSet<>();
            for (int i = index; i < nums.length; i++) {
                if (!used.contains(nums[i])) {
                    used.add(i);
                    subSet.add(nums[i]);
                    helper(nums, i + 1);
                    subSet.removeLast();
                }
            }
        }

        public List<List<Integer>> subsetsWithDup(int[] nums) {
            helper(nums, 0);
            return res;
        }
    }

}