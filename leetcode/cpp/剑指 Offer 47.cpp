/*
 * @lc app=leetcode.cn id=剑指 Offer 47 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 47] 礼物的最大价值
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
    int maxValue(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = grid[i][j];
                } else if (i == m - 1) {
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                } else if (j == n - 1) {
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                } else {
                    dp[i][j] = grid[i][j] + max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

 */

