package com.kekwy.leetcode;

import java.util.*;

class P55 {

    /**
     * 暴力回溯：超限
     * 考虑动态规划：没必要，被思维定势了
     * 最佳解法是贪心，维护最远可达具体即可
     */
    class Solution1 {

        private boolean[] results;
        private boolean[] flags;

        private void helper(int[] nums, int index) {
            flags[index] = true;
            for (int i = 1; i <= nums[index]; i++) {
                if (index + i >= nums.length - 1) {
                    results[index] = true;
                    return;
                } else {
                    if (!flags[index + i]) helper(nums, index + i);
                    if (results[index + i]) {
                        results[index] = true;
                        return;
                    }
                }
            }
        }


        public boolean canJump(int[] nums) {
            results = new boolean[nums.length];
            flags = new boolean[nums.length];
            if (nums.length == 1) return true;
            helper(nums, 0);
            return results[0];
        }
    }

    class Solution {
        public boolean canJump(int[] nums) {
            int furthest = 0;
            for (int i = 0; i < nums.length && furthest < nums.length - 1; i++) {
                if (i <= furthest) {
                    furthest = Math.max(furthest, i + nums[i]);
                } else {
                    break;
                }
            }
            return furthest >= nums.length - 1;
        }
    }

}

class P45 {

    class Solution {
        public int jump(int[] nums) {
            int res = 0;
            int reachable = 0;
            int tmpReachable = 0;
            for (int i = 0; i < nums.length && reachable < nums.length - 1; i++) {
                if (i <= reachable) {
                    if (i + nums[i] > tmpReachable) {
                        tmpReachable = i + nums[i];
                    }
                } else {
                    res++;
                    reachable = tmpReachable;
                    i--; // bug
                }
            }
            return res;
        }
    }

}

/**
 * star
 */
class P380 {

    /**
     * 随机访存：数组
     * O(1) 查找：哈希
     * O(1) 删除：将表中元素的删除，转化为表尾元素的删除。
     */
    class RandomizedSet {
        private final Map<Integer, Integer> map;
        private final List<Integer> data;
        private final Random random;

        public RandomizedSet() {

            random = new Random(System.currentTimeMillis());
            map = new HashMap<>();

            data = new ArrayList<>();
        }

        public boolean insert(int val) {
            if (map.containsKey(val)) return false;

            data.add(val);
            map.put(val, data.size() - 1);
            return true;
        }

        public boolean remove(int val) {
            if (!map.containsKey(val)) return false;

            int index = map.get(val);
            Integer tail = data.get(data.size() - 1);
            map.put(tail, index);
            map.remove(val);
            data.set(index, tail);
            data.remove(data.size() - 1);
            return true;
        }

        public int getRandom() {
            return data.get(random.nextInt(0, data.size()));

        }
    }


}

/**
 * star
 */
class P295 {

    /**
     * 对顶堆
     */
    class MedianFinder {

        public MedianFinder() {

        }

        public void addNum(int num) {
            return;
        }

        public double findMedian() {
            return 0;
        }
    }

}

class P332 {

    class Solution {

        private List<String> res = new ArrayList<>();
        private Map<String, Set<String>> edges = new HashMap<>();

        public List<String> findItinerary(List<List<String>> tickets) {

            return res;
        }
    }

}