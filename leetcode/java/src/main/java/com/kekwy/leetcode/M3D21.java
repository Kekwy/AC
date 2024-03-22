package com.kekwy.leetcode;

import java.util.*;

class P2671 {
    class FrequencyTracker {

        private final Map<Integer, Integer> index = new HashMap<>();
        private final Map<Integer, Set<Integer>> reverseIndex = new HashMap<>();

        public FrequencyTracker() {

        }

        public void add(int number) {
            int freq = index.getOrDefault(number, 0);
            if (freq != 0) {
                Set<Integer> set = reverseIndex.get(freq);
                set.remove(number);
                if (set.isEmpty()) reverseIndex.remove(freq);
            }
            freq++;
            Set<Integer> set = reverseIndex.getOrDefault(freq, new HashSet<>());
            set.add(number);
            reverseIndex.put(freq, set);
            index.put(number, freq);
        }

        public void deleteOne(int number) {
            if (!index.containsKey(number)) return;
            int freq = index.get(number);
            Set<Integer> set1 = reverseIndex.get(freq);
            set1.remove(number);
            if (set1.isEmpty()) reverseIndex.remove(freq);
            freq--;
            if (freq == 0) {
                index.remove(number);
            } else {
                Set<Integer> set2 = reverseIndex.getOrDefault(freq, new HashSet<>());
                set2.add(number);
                reverseIndex.put(freq, set2);
                index.put(number, freq);
            }
        }

        public boolean hasFrequency(int frequency) {
            return reverseIndex.containsKey(frequency);
        }
    }
}

class P509 {

    class Solution {

        public int fib(int n) {
            if (n == 0 || n == 1) return n;
            int[] dp = new int[n + 1];
            dp[0] = 0;
            dp[1] = 1;
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
    }

}

class P70__ {
    class Solution {
        public int climbStairs(int n) {
            if (n == 0 || n == 1) return n;
            int[] dp = new int[n + 1];
            dp[0] = 1;
            dp[1] = 1;
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
    }
}

class P746 {

    class Solution {
        public int minCostClimbingStairs(int[] cost) {
            int n = cost.length;
            if (n == 0 || n == 1) return n;
            int[] dp = new int[n + 1];
            dp[0] = 0;
            dp[1] = 0;
            for (int i = 2; i <= n; i++) {
                dp[i] = Math.min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            }
            return dp[n];
        }
    }

}

class P62 {

    class Solution {
        public int uniquePaths(int m, int n) {
            int[][] dp = new int[m][n];
            dp[m - 1][n - 1] = 1;
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i + 1 < m) dp[i][j] += dp[i + 1][j];
                    if (j + 1 < n) dp[i][j] += dp[i][j + 1];
                }
            }
            return dp[0][0];
        }
    }

}

class P63 {

    class Solution {
        public int uniquePathsWithObstacles(int[][] obstacleGrid) {
            int m = obstacleGrid.length;
            int n = obstacleGrid[0].length;
            if (obstacleGrid[m - 1][n - 1] == 1) return 0;
            int[][] dp = new int[m][n];
            dp[m - 1][n - 1] = 1;
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (obstacleGrid[i][j] == 1) continue;
                    if (i + 1 < m && obstacleGrid[i + 1][j] == 0)
                        dp[i][j] += dp[i + 1][j];
                    if (j + 1 < n && obstacleGrid[i][j + 1] == 0)
                        dp[i][j] += dp[i][j + 1];
                }
            }
            return dp[0][0];
        }
    }

}

class P343 {

    class Solution {
        public int integerBreak(int n) {
            int[] dp = new int[n + 1];
            dp[1] = 1;
            dp[2] = 1;
            for (int i = 3; i <= n; i++) {
                for (int j = 1; j < i; j++) {
//                    dp[i] = Math.max(dp[i], j * dp[i - j]);
                    dp[i] = Math.max(dp[i], Math.max((i - j) * j, dp[i - j] * j)); // i - j 可以不分割
                }
            }
            return dp[n];
        }
    }

}

class P96 {

    class Solution {
        public int numTrees(int n) {
            return 0;
        }
    }

}

class P416 {
    class Solution {
        public boolean canPartition(int[] nums) {
            int sum = Arrays.stream(nums).sum();
            if (sum % 2 == 1) return false;
            int target = sum / 2;
            int[] dp = new int[target + 1];
            for (int i = 0; i < dp.length; i++) {
                dp[i] = i;
            }
            for (int num : nums) {
                for (int i = target; i >= 0; i--) {
                    if (num <= i) {
                        dp[i] = Math.min(dp[i - num], dp[i]);
                    }
                }
            }
            return dp[target] == 0;
        }
    }
}

class P1049 {

    class Solution {
        public int lastStoneWeightII(int[] stones) {
            Arrays.sort(stones);
            for (int i = 1; i < stones.length; i++) {
                if (i < stones.length - 1)
                    stones[i] -= stones[i - 1];
            }
            return stones[stones.length - 1];
        }
    }

}

class P494 {

    class Solution {
        public int findTargetSumWays(int[] nums, int target) {
            return 0;
        }
    }

}

class P474 {

    class Solution {
        public int findMaxForm(String[] strs, int m, int n) {
            int[][] count = new int[strs.length][2];
            for (int i = 0; i < strs.length; i++) {
                String str = strs[i];
                for (int j = 0; j < str.length(); j++) {
                    if (str.charAt(j) == '0') count[i][0]++;
                    else if (str.charAt(j) == '1') count[i][1]++;
                }
            }
            int[][] dp = new int[m + 1][n + 1];
            for (int i = 0; i < strs.length; i++) {
                for (int j = m; j >= 0; j--) {
                    if (count[i][0] > j) break;
                    for (int k = n; k >= 0; k--) {
                        if (count[i][1] > k) break;
                        dp[j][k] = Math.max(dp[j][k],
                                dp[j - count[i][0]][k - count[i][1]] + 1);
                    }
                }
            }
            return dp[m][n];
        }
    }

}

class P518 {

    class Solution_ {

        int[][] dp;

        private void helper(int i, int[] coins, int amount) {
            if (amount == 0) {
                dp[i][amount] = 1;
                return;
            }
            if (i >= coins.length || coins[i] > amount) {
                dp[i][amount] = 0;
                return;
            }
            if (dp[i][amount - coins[i]] == -1) helper(i, coins, amount - coins[i]);
            if (dp[i + 1][amount] == -1) helper(i + 1, coins, amount);
            dp[i][amount] = dp[i][amount - coins[i]] + dp[i + 1][amount];
        }


        public int change(int amount, int[] coins) {
            Arrays.sort(coins);
            dp = new int[coins.length + 1][amount + 1];
            for (int[] ints : dp) {
                Arrays.fill(ints, -1);
            }
            helper(0, coins, amount);
            return dp[0][amount];
        }
    }

    class Solution {
        public int change(int amount, int[] coins) {
            int[] dp = new int[amount + 1];
            dp[0] = 1;
            for (int coin : coins) {
                for (int i = coin; i <= amount; i++) {
                    dp[i] += dp[i - coin];
                }
            }
            return dp[amount];
        }
    }

}