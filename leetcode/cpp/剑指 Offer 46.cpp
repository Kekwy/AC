// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=剑指 Offer 46 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 46] 把数字翻译成字符串
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
    int translateNum(int num) {
        int i = 1, lastN = num % 10;
        num /= 10;
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);
        while (num > 0) {
            int curN = num % 10;
            int count = dp[i];
            if (curN == 1 || curN == 2) {
                int tmpN = curN * 10 + lastN;
                if (tmpN < 26) count += dp[i - 1];
            }
            dp.push_back(count);
            num /= 10;
            i++;
            lastN = curN;
        }
        return dp[i];
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName= translateNum
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 12258\n
// @lcpr case=end

 */

