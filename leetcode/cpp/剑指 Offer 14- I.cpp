/*
 * @lc app=leetcode.cn id=剑指 Offer 14- I lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 14- I] 剪绳子
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution {
public:
    int cuttingRope(int n) { // 暴力 dp 解法
        auto dp = vector<vector<int>>(n + 1, vector<int>(n + 1));
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= n; j++) {
                if (j == 2) dp[i][j] = (i / 2) * (i - i / 2);
                else {
                    dp[i][j] = INT_MIN;
                    for (int k = 1; k < i; k++) {
                        dp[i][j] = max(dp[i][j], dp[i - k][j - 1] * k);
                    }
                }
            }
        }
        int res = INT_MIN;
        for (int i : dp[n]) {
            if (i > res) res = i;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

