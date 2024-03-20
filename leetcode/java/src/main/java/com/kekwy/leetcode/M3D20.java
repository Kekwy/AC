package com.kekwy.leetcode;

import com.kekwy.leetcode.util.TreeNode;
import org.junit.jupiter.api.Test;

import java.util.*;

class P455 {
    class Solution {
        public int findContentChildren(int[] g, int[] s) {
            int res = 0;
            Arrays.sort(g);
            Arrays.sort(s);
            int i = 0, j = 0;
            while (i < g.length && j < s.length) {
                if (g[i] <= s[j]) {
                    res++;
                    i++;
                }
                j++;
            }
            return res;
        }
    }
}

class P376 {
    class Solution {
        public int wiggleMaxLength(int[] nums) {
            int res = 1;
            Boolean flag = null;
            int curr = nums[0];
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] == curr) continue;
                if (flag == null) {
                    flag = nums[i] > curr;
                    res++;
                } else if (flag && nums[i] < curr) {
                    flag = false;
                    res++;
                } else if (!flag && nums[i] > curr) {
                    flag = true;
                    res++;
                }
                curr = nums[i];
            }
            return res;
        }
    }
}

class P53 {

    class Solution {
        public int maxSubArray(int[] nums) {
            int res = nums[0];
            int sum = nums[0];
            for (int i = 1; i < nums.length; i++) {
                if (sum < 0) {
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
                if (sum > res) res = sum;
            }
            return res;
        }
    }

}

class P122 {

    class Solution {
        public int maxProfit(int[] prices) {
            int result = 0;
            for (int i = 1; i < prices.length; i++) {
                result += Math.max(prices[i] - prices[i - 1], 0);
            }
            return result;
        }
    }

}

class P1005 {

    class Solution {
        public int largestSumAfterKNegations(int[] nums, int k) {
            Arrays.sort(nums);
            int i = 0;
            while (i < k && i < nums.length && nums[i] < 0) {
                nums[i] = -nums[i];
                i++;
            }
            if (i < k) {
                if ((k - i) % 2 == 1) {
                    Arrays.sort(nums);
                    nums[0] = -nums[0];
                }
            }
            return Arrays.stream(nums).sum();
        }
    }

}

class P134_ {

    class Solution {
        public int canCompleteCircuit(int[] gas, int[] cost) {
            int curSum = 0;
            int totalSum = 0;
            int start = 0;
            for (int i = 0; i < gas.length; i++) {
                curSum += gas[i] - cost[i];
                totalSum += gas[i] - cost[i];
                if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
                    start = i + 1;  // 起始位置更新为i+1
                    curSum = 0;     // curSum从0开始
                }
            }
            if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
            return start;
        }
    }


}

class P860 {

    class Solution {
        public boolean lemonadeChange(int[] bills) {
            int dol5 = 0;
            int dol10 = 0;
            for (int bill : bills) {
                if (bill == 5) {
                    dol5++;
                } else if (bill == 10) {
                    if (dol5 > 0) {
                        dol5--;
                        dol10++;
                    } else return false;
                } else if (bill == 20) {
                    if (dol10 > 0) {
                        dol10--;
                        if (dol5 > 0) {
                            dol5--;
                        } else return false;
                    } else if (dol5 >= 3) {
                        dol5 -= 3;
                    } else return false;
                }
            }
            return true;
        }
    }

}

class P406 {

    class Solution {

        /**
         * 先插入高个子，后插入的矮个子不影响已插入的高个子在身高大于等于他的人中的次序
         */
        public int[][] reconstructQueue(int[][] people) {
            Arrays.sort(people, (a, b) -> {
                if (b[0] == a[0]) {
                    return a[1] - b[1];
                }
                return b[0] - a[0];
            }); // desc
            List<int[]> res = new LinkedList<>();
            for (int[] person : people) {
                res.add(person[1], person);
            }
            return res.toArray(new int[0][]);
        }
    }

}

class P435 {

    class Solution {
        public int eraseOverlapIntervals(int[][] intervals) {
            int res = 0;
            Arrays.sort(intervals, Comparator.comparing(a -> a[0]));
            int lp = intervals[0][0], rp = intervals[0][1];
            for (int i = 1; i < intervals.length; i++) {
                if (intervals[i][0] >= lp && intervals[i][0] < rp) {
                    lp = intervals[i][0];
                    rp = Math.min(rp, intervals[i][1]);
                    res++;
                } else {
                    lp = intervals[i][0];
                    rp = intervals[i][1];
                }
            }
            return res;
        }
    }

}

class P763 {

    class Solution {
        public List<Integer> partitionLabels(String s) {
            Map<Character, Integer> map = new HashMap<>();
            for (int i = 0; i < s.length(); i++) {
                map.put(s.charAt(i), i);
            }
            List<Integer> res = new LinkedList<>();
            int begin = 0, end = 0;
            for (int i = 0; i < s.length(); i++) {
                end = Math.max(map.get(s.charAt(i)), end);
                if (i == end) {
                    res.add(end - begin + 1);
                    begin = i + 1;
                    end = i + 1;
                }
            }
            return res;
        }
    }

}

class P738 {

    class Solution {
        public int monotoneIncreasingDigits(int n) {
            char[] nStr = String.valueOf(n).toCharArray();
            int flag = nStr.length;
            for (int i = nStr.length - 1; i > 0; i--) {
                if (nStr[i - 1] > nStr[i]) {
                    nStr[i - 1]--;
                    flag = i;
                }
            }
            int i = 0;
            int res = 0;
            while (i < flag) {
                res = res * 10 + nStr[i] - '0';
                i++;
            }
            while (i < nStr.length) {
                res = res * 10 + 9;
                i++;
            }
            return res;
        }
    }

}

class P968 {

    class Solution {

        int res = 0;

        private int helper(TreeNode node) {
            if (node == null) return 1;
//         //   boolean flag = helper(node.left) && helper(node.right); bugfix
            int flag1 = helper(node.left);
            int flag2 = helper(node.right);
            int flag = 2;
            if (flag1 == 2 || flag2 == 2) {
                res++;
                return 0;
            } else if (flag1 == 0 || flag2 == 0) {
                return 1;
            } else {
                return 2;
            }
        }
        public int minCameraCover(TreeNode root) {
            if (root.left == null && root.right == null) return 1;
            if (helper(root) == 2) res++;
            return res;

        }
    }





    @Test
    public void test() {
        TreeNode node = new TreeNode(0);
        node.left = new TreeNode(0);
        node.right = new TreeNode(0);
        TreeNode right = node.right;
        right.right = new TreeNode(0);
        new Solution().minCameraCover(node);
    }

}