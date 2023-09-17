/*
 * @lc app=leetcode.cn id=剑指 Offer 10- I lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 10- I] 斐波那契数列
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

    vector<int> dp;

public:

    int fib(int n) {
        if (n == 0 || n == 1) return n;
        auto dp = vector<long>(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        stack<int> recurStack;
        recurStack.push(n);
        while (!recurStack.empty()) {
            int i = recurStack.top();
            if (dp[i - 1] != -1 && dp[i - 2] != -1) {
                dp[i] = (dp[i - 1] + dp[i - 2]) % ((int)1e9 + 7);
                recurStack.pop();
            } else {
                if (dp[i - 1] == -1) recurStack.push(i - 1);
                if (dp[i - 2] == -1) recurStack.push(i - 2);
            }
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
// 5\n
// @lcpr case=end

 */

