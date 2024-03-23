package com.kekwy.leetcode;

import org.junit.jupiter.api.Test;

import java.util.*;

class P300 {
    class Solution {
        public int lengthOfLIS(int[] nums) {
            int[] dp = new int[nums.length];
            Arrays.fill(dp, 1);
            int res = 1;
            for (int i = nums.length - 2; i >= 0; i--) {
                for (int j = i + 1; j < nums.length; j++) {
                    if (nums[i] < nums[j]) dp[i] = Math.max(dp[i], dp[j] + 1);
                }
                if (res < dp[i]) res = dp[i];
            }
            return res;
        }
    }
}

class P674 {

    class Solution {
        public int findLengthOfLCIS(int[] nums) {
            int[] dp = new int[nums.length];
            Arrays.fill(dp, 1);
            int res = 1;
            for (int i = nums.length - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) dp[i] = dp[i + 1] + 1;
                if (dp[i] > res) res = dp[i];
            }
            return res;
        }
    }

}

class P718 {

    class Solution {
        /**
         * 注意初始值和状态转移方程
         */
        public int findLength(int[] nums1, int[] nums2) {
            int[] dp = new int[nums1.length + 1];
            int res = 0;
            for (int i : nums2) {
                for (int j = nums1.length; j >= 1; j--) {
                    if (nums1[j - 1] == i) dp[j] = dp[j - 1] + 1;
                    else dp[j] = 0;
                    if (res < dp[j]) res = dp[j];
                }
            }
            return res;
        }
    }

}

class P1143 {

    class Solution {
        /**
         * 与递增子序列不同的是，字符串的子序列中各字符之间无顺序要求，故不需要嵌套循环。
         * 滚动数组可以不用，如果空间复杂度没有超限的话。
         * <a href="https://programmercarl.com/1143.%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97.html#%E6%80%9D%E8%B7%AF">...</a>
         */
        public int longestCommonSubsequence(String text1, String text2) {
            int[] dp = new int[text1.length() + 1];
            int res = 0;
            for (int i = 0; i < text2.length(); i++) {
                char c1 = text2.charAt(i);
                for (int j = text1.length(); j >= 1; j--) {
                    char c2 = text1.charAt(j - 1);
                    if (c2 != c1) continue;
                    for (int k = j - 1; k >= 0; k--) {
                        dp[j] = Math.max(dp[j], 1 + dp[k]);
                    }
                    if (dp[j] > res) res = dp[j];
                }
            }
            return res;
        }
    }

}

class P1035 {

    /**
     * 转化为求最长子序列的问题
     */
    class Solution {
        public int maxUncrossedLines(int[] nums1, int[] nums2) {
            int res = 0;
            int[][] dp = new int[nums1.length + 1][nums2.length + 1];
            for (int i = 1; i <= nums1.length; i++) {

                for (int j = 1; j <= nums2.length; j++) {
                    if (nums1[i - 1] == nums2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                    }
                    if (dp[i][j] > res) res = dp[i][j];
                }
            }
            return res;
        }
    }

}

class P53__ {

    class Solution {
        public int maxSubArray(int[] nums) {
            int res = nums[nums.length - 1];
            int[] dp = Arrays.copyOf(nums, nums.length);
            for (int i = nums.length - 2; i >= 0; i--) {
                dp[i] = Math.max(dp[i], dp[i] + dp[i + 1]);
                if (dp[i] > res) res = dp[i];
            }
            return res;
        }
    }

}

class P392__ {

    class Solution {
        public boolean isSubsequence(String s, String t) {
            boolean[][] dp = new boolean[s.length() + 1][t.length() + 1];
            Arrays.fill(dp[0], true);
            for (int i = 1; i <= s.length(); i++) {
                for (int j = 1; j <= t.length(); j++) {
                    if (s.charAt(i - 1) == t.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
            return dp[s.length()][t.length()];
        }
    }

}

class P115 {

    class Solution {
        public int numDistinct(String s, String t) {
            int[][] dp = new int[t.length() + 1][s.length() + 1];
            Arrays.fill(dp[0], 1);
            for (int i = 1; i <= t.length(); i++) {
                for (int j = 1; j <= s.length(); j++) {
                    if (t.charAt(i - 1) == s.charAt(j - 1)) {
                        dp[i][j] += dp[i - 1][j - 1];
                    }
                    dp[i][j] += dp[i][j - 1];
                }
            }
            return dp[t.length()][s.length()];
        }
    }

}

class P583 {

    class Solution {
        public int minDistance(String word1, String word2) {
            int[][] dp = new int[word1.length() + 1][word2.length() + 1];
            for (int i = 0; i < dp.length; i++) {
                dp[i][0] = i;
            }
            for (int i = 0; i < dp[0].length; i++) {
                dp[0][i] = i;
            }
            for (int i = 1; i <= word1.length(); i++) {
                for (int j = 1; j <= word2.length(); j++) {
                    if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = Math.min(dp[i][j - 1], dp[i - 1][j]) + 1;
                    }
                }
            }
            return dp[word1.length()][word2.length()];
        }
    }

    @Test
    public void test() {
        Solution solution = new Solution();
        solution.minDistance("eat", "sea");
    }

}

class P72 {

    class Solution {

        // word2添加一个元素，相当于word1删除一个元素
        public int minDistance(String word1, String word2) {
            int[][] dp = new int[word1.length() + 1][word2.length() + 1];
            for (int i = 0; i < dp.length; i++) {
                dp[i][0] = i;
            }
            for (int i = 0; i < dp[0].length; i++) {
                dp[0][i] = i;
            }
            for (int i = 1; i <= word1.length(); i++) {
                for (int j = 1; j <= word2.length(); j++) {
                    if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]);
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1]);
                        dp[i][j] += 1;
                    }
                }
            }
            return dp[word1.length()][word2.length()];
        }
    }

}

class P647 {

    class Solution {
        public int countSubstrings(String s) {
            boolean[][] dp = new boolean[s.length()][s.length()];
            for (int i = s.length() - 1; i >= 0; i--) {
                for (int j = i; j < s.length(); j++) {
                    if (i == j) dp[i][j] = true;
                    else if (j - i == 1) dp[i][j] = s.charAt(i) == s.charAt(j);
                    else dp[i][j] = s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1];
                }
            }
            int res = 0;
            for (boolean[] d : dp) {
                for (boolean b : d) {
                    if (b) res++;
                }
            }
            return res;
        }
    }

}

class P516 {

    class Solution {
        public int longestPalindromeSubseq(String s) {
            int res = 0;
            int[][] dp = new int[s.length()][s.length()];
            for (int i = s.length() - 1; i >= 0; i--) {
                for (int j = i; j < s.length(); j++) {
                    if (i == j) {
                        dp[i][j] = 1;
                    } else {
                        if (s.charAt(i) == s.charAt(j)) {
                            dp[i][j] = (j - i == 1) ? 2 : dp[i + 1][j - 1] + 2;
                        } else {
                            dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                        }
                    }
                    if (dp[i][j] > res) res = dp[i][j];
                }
            }
            return res;
        }
    }

}

class P739 {

    class Solution {
        public int[] dailyTemperatures(int[] temperatures) {
            Stack<Integer> stack = new Stack<>();
            int[] res = new int[temperatures.length];
            for (int i = 0; i < temperatures.length; i++) {
                while (!stack.isEmpty() && temperatures[stack.peek()] < temperatures[i]) {
                    int top = stack.pop();
                    res[top] = i - top;
                }
                stack.push(i);
            }
//            while (!stack.isEmpty()) {
//                res[stack.pop()] = 0;
//            }
            return res;
        }
    }

}

class P496 {

    class Solution {
        public int[] nextGreaterElement(int[] nums1, int[] nums2) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < nums1.length; i++) {
                map.put(nums1[i], i);
            }
            int[] res = new int[nums1.length];
            Arrays.fill(res, -1);
            Stack<Integer> stack = new Stack<>();
            for (int i = 0; i < nums2.length; i++) {
                while (!stack.isEmpty() && stack.peek() < nums2[i]) {
                    int j = stack.pop();
                    res[map.get(j)] = i;
                }
                if (map.containsKey(nums2[i])) stack.push(nums2[i]);
            }
            return res;
        }
    }

}

class P503 {

    class Solution {
        // 循环队列，遍历两遍即可（将两个 nums 拼在一起）
        public int[] nextGreaterElements(int[] nums) {
            int[] res = new int[nums.length];
            Arrays.fill(res, -1);
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < nums.length * 2; i++) {
                // 模拟遍历两边nums，注意一下都是用i % nums.size()来操作
                while (!st.empty() && nums[i % nums.length] > nums[st.peek()]) {
                    res[st.peek()] = nums[i % nums.length];
                    st.pop();
                }
                st.push(i % nums.length);
            }
            return res;
        }
    }

}

class P84 {

    class Solution {
        public int largestRectangleArea(int[] heights) {
            return -1;
        }
    }

}
