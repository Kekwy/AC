// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=剑指 Offer 60 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 60] n个骰子的点数
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
    vector<double> dicesProbability(int n) {
        auto dp = vector<vector<double>>(n);
        dp[0].resize(6, 1.0 / 6.0);
        for (int i = 0; i < n - 1; i++) {
            dp[i + 1].resize(dp[i].size() + 5);
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i + 1][0 + j] += dp[i][j] / 6.0;
                dp[i + 1][1 + j] += dp[i][j] / 6.0;
                dp[i + 1][2 + j] += dp[i][j] / 6.0;
                dp[i + 1][3 + j] += dp[i][j] / 6.0;
                dp[i + 1][4 + j] += dp[i][j] / 6.0;
                dp[i + 1][5 + j] += dp[i][j] / 6.0;
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=dicesProbability
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

