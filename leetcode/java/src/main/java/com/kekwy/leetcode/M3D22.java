package com.kekwy.leetcode;

import com.kekwy.leetcode.util.TreeNode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

class P377 {

    class Solution {
        public int combinationSum4(int[] nums, int target) {
            int[] dp = new int[target + 1];
            dp[0] = 1;
            for (int i = 1; i <= target; i++) {
                for (int num : nums) {
                    if (i < num) continue;
                    dp[i] += dp[i - num];
                }
            }
            return dp[target];
        }
    }

}

class P322 {

    class Solution {
        public int coinChange(int[] coins, int amount) {
            int[] dp = new int[amount + 1];
            Arrays.fill(dp, Integer.MAX_VALUE - 1);
            dp[0] = 0;
            for (int coin : coins) {
                for (int i = coin; i <= amount; i++) {
                    dp[i] = Math.min(dp[i], 1 + dp[i - coin]);
                }
            }
            if (dp[amount] == Integer.MAX_VALUE - 1) return -1;
            return dp[amount];
        }
    }

}

class P279 {

    class Solution {
        public int numSquares(int n) {
            List<Integer> nums = new LinkedList<>();
            for (int i = 1; i * i <= n; i++) {
                nums.add(i * i);
            }
//            int[] array = Arrays.stream(nums.toArray(new Integer[0]))
//                    .mapMultiToInt((a, b) -> b.accept(a)).toArray();
            int[] dp = new int[n + 1];
            Arrays.fill(dp, Integer.MAX_VALUE - 1);
            dp[0] = 0;
            for (Integer num : nums) {
                for (int i = num; i <= n; i++) {
                    dp[i] = Math.min(dp[i], dp[i - num] + 1);
                }
            }
            return dp[n];
        }
    }

}

class P139 {

    /**
     * 找到物品的排列（结果如物品的顺序有关），应该先遍历背包，再遍历物品。
     */
    class Solution {
        public boolean wordBreak(String s, List<String> wordDict) {
            boolean[] dp = new boolean[s.length() + 1];
            dp[0] = true;
            for (int i = 1; i <= s.length(); i++) {
                for (String string : wordDict) {
                    if (string.length() > i) continue;
                    if (s.startsWith(string, i - string.length())) {
                        dp[i] = dp[i] || dp[i - string.length()];
                    }
                }
            }
            return dp[s.length()];
        }
    }

}

class P198 {

    class Solution {
        public int rob(int[] nums) {
            int[] dp = new int[nums.length + 1];
            dp[nums.length - 1] = nums[nums.length - 1];
            for (int i = nums.length - 2; i >= 0; i--) {
                dp[i] = Math.max(dp[i + 1], nums[i] + dp[i + 2]);
            }
            return dp[0];
        }
    }

}

class P213 {

    class Solution {
        public int rob(int[] nums) {
            if (nums.length == 1) return nums[0];
            int[] dp1 = new int[nums.length + 1];
            dp1[nums.length - 2] = nums[nums.length - 2];
            for (int i = nums.length - 3; i >= 0; i--) {
                dp1[i] = Math.max(dp1[i + 1], nums[i] + dp1[i + 2]);
            }
            int[] dp2 = new int[nums.length + 1];
            dp2[nums.length - 1] = nums[nums.length - 1];
            for (int i = nums.length - 2; i >= 1; i--) {
                dp2[i] = Math.max(dp2[i + 1], nums[i] + dp2[i + 2]);
            }
            return Math.max(dp1[0], dp2[1]);
        }
    }

}

class P337 {

    class Solution {

        private int[] helper(TreeNode node) {
            if (node == null) return new int[]{0, 0};
            int[] left = helper(node.left);
            int[] right = helper(node.right);
            return new int[]{
                    node.val + left[1] + right[1],
                    Math.max(left[0], left[1]) + Math.max(right[0], right[1])
            };
        }

        public int rob(TreeNode root) {
            int[] res = helper(root);
            return Math.max(res[0], res[1]);
        }
    }

}

class P122__ {

    class Solution {
        public int maxProfit(int[] prices) {
            int[][] dp = new int[prices.length][2];
            dp[0][0] = -prices[0];
            dp[0][1] = 0;
            for (int i = 1; i < prices.length; i++) {
                dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
                dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            }
            return dp[prices.length - 1][1];
        }
    }

}

class P123 {

    class Solution {
        public int maxProfit(int[] prices) {
            int[][][] dp = new int[prices.length][2][3];
            dp[0][0][0] = -prices[0];
            dp[0][0][1] = -prices[0];
            for (int i = 1; i < prices.length; i++) {
                dp[i][0][0] = Math.max(dp[i - 1][0][0], dp[i - 1][1][0] - prices[i]);
                dp[i][0][1] = Math.max(dp[i - 1][0][1], dp[i - 1][1][1] - prices[i]);
                dp[i][1][0] = dp[i - 1][1][0];
                dp[i][1][1] = Math.max(dp[i - 1][1][1], dp[i - 1][0][0] + prices[i]);
                dp[i][1][2] = Math.max(dp[i - 1][1][2], dp[i - 1][0][1] + prices[i]);
            }
//            return Arrays.stream(dp[prices.length - 1][1]).max().getAsInt();
            return dp[prices.length - 1][1][2];
        }
    }

}

class P188 {

    class Solution {
        public int maxProfit(int k, int[] prices) {
            int[][][] dp = new int[prices.length][2][k + 1];
            Arrays.fill(dp[0][0], -prices[0]);
            for (int i = 1; i < prices.length; i++) {
                for (int j = 0; j <= k; j++) {
                    dp[i][0][j] = Math.max(dp[i - 1][0][j], dp[i - 1][1][j] - prices[i]);
                }
                dp[i][1][0] = dp[i - 1][1][0];
                for (int j = 1; j <= k; j++) {
                    dp[i][1][j] = Math.max(dp[i - 1][1][j], dp[i - 1][0][j - 1] + prices[i]);
                }
            }
//            return Arrays.stream(dp[prices.length - 1][1]).max().getAsInt();
            return dp[prices.length - 1][1][k];
        }
    }

}

class P309 {

    class Solution {
        public int maxProfit(int[] prices) {
            int[][][] dp = new int[prices.length][2][2];
            Arrays.fill(dp[0][0], -prices[0]);
            for (int i = 1; i < prices.length; i++) {
                dp[i][0][0] = Math.max(dp[i - 1][0][0], dp[i - 1][1][0] - prices[i]);
                dp[i][1][0] = Math.max(dp[i - 1][1][0], dp[i - 1][1][1]);
                dp[i][1][1] = dp[i - 1][0][0] + prices[i];
            }
            return Math.max(dp[prices.length - 1][1][0], dp[prices.length - 1][1][1]);
        }
    }

}

class P714 {

    class Solution {
        public int maxProfit(int[] prices, int fee) {
            int[][] dp = new int[prices.length][2];
            dp[0][0] = -prices[0];
            dp[0][1] = 0;
            for (int i = 1; i < prices.length; i++) {
                dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
                dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
            }
            return dp[prices.length - 1][1];
        }
    }

}