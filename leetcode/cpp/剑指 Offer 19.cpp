/*
 * @lc app=leetcode.cn id=剑指 Offer 19 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 19] 正则表达式匹配
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

    vector<vector<bool>> dp;

public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) return true;
        else if (p.empty()) return false;
        dp.resize(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[s.length()][p.length()] = true;
        for (int j = p.length() - 2; j >= 0; j--) {
            if (j + 1 && p[j + 1] == '*') {
                dp[s.length()][j] = dp[s.length()][j + 2];
            } else {
                dp[s.length()][j] = false;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = p.length() - 1; j >= 0; j--) {
                if (j + 1 < p.length() && p[j + 1] == '*') {
                    if (p[j] == '.' || p[j] == s[i]) {
                        dp[i][j] = dp[i + 1][j + 2] || dp[i + 1][j] || dp[i][j + 2];
                    } else {
                        dp[i][j] = dp[i][j + 2];
                    }
                } else if (p[j] == '.' || p[j] == s[i]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a"\n
// @lcpr case=end

// @lcpr case=start
// "a*"\n
// @lcpr case=end

// @lcpr case=start
// ".*"\n
// @lcpr case=end

// @lcpr case=start
// "c*a*b"\n
// @lcpr case=end

// @lcpr case=start
// "mis*is*p*."\n
// @lcpr case=end

 */

