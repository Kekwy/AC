/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=21917
 *
 * [121] 买卖股票的最佳时机
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
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy = prices[0];
        for (int p : prices) {
            if (p - buy > res) res = p - buy;
            else if (p < buy) buy = p;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

