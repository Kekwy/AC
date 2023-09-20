/*
 * @lc app=leetcode.cn id=LCP 06 lang=cpp
 * @lcpr version=21914
 *
 * [LCP 06] 拿硬币
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
    int minCount(vector<int>& coins) {
        int res = 0;
        for (int c : coins) {
            res += c / 2 + c % 2;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,10]\n
// @lcpr case=end

 */

