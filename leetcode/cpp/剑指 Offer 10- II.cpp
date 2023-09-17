/*
 * @lc app=leetcode.cn id=剑指 Offer 10- II lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 10- II] 青蛙跳台阶问题
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

    vector<int> dp = vector<int>(101, -1);

public:

    int numWays(int n) {
        if (n == 0 || n == 1) {
            dp[n] = 1;
        } else {
            if (dp[n - 1] == -1) numWays(n - 1);
            if (dp[n - 2] == -1) numWays(n - 2);
            dp[n] = (dp[n - 1] + dp[n - 2]) % 1000000007;
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */

