/*
 * @lc app=leetcode.cn id=剑指 Offer 63 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 63] 股票的最大利润
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
    int maxProfit(vector<int> &prices) {
        deque<int> q;
        for (int p : prices) {
            for (;!q.empty() && q.back() < p; q.pop_back());
            q.push_back(p);
        }
        int res = 0;
        for (int p : prices) {
            if (q.front() == p) q.pop_front();
            if (!q.empty() && q.front() - p > res) {
                res = q.front() - p;
            }
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

