/*
 * @lc app=leetcode.cn id=剑指 Offer 15 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 15] 二进制中1的个数
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
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n > 0) {
            if ((n & 0x1) == 1) res++;
            n >>= 1;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 11 (控制台输入 00000000000000000000000000001011)\n
// @lcpr case=end

// @lcpr case=start
// 128 (控制台输入 00000000000000000000000010000000)\n
// @lcpr case=end

// @lcpr case=start
// -3）\n
// @lcpr case=end

 */

