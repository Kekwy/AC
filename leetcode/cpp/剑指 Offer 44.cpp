/*
 * @lc app=leetcode.cn id=剑指 Offer 44 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 44] 数字序列中某一位的数字
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
#include <cmath>
// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        n -= 10;
        int d = 2;
        long long count = 90;
        while (n > d * count) {
            n -= d * count;
            d++;
            count *= 10;
        }
        return (int)(((n / d) + pow(10, d - 1)) / pow(10, d - (n % d) - 1)) % 10;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 11\n
// @lcpr case=end

 */

