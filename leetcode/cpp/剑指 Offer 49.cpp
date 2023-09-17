/*
 * @lc app=leetcode.cn id=剑指 Offer 49 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 49] 丑数
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
    int nthUglyNumber(int n) {
        auto uglyNumber = vector<int>(n);
        uglyNumber[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            int next = min({2 * uglyNumber[p2], 3 * uglyNumber[p3], 5 * uglyNumber[p5]});
            if (next == 2 * uglyNumber[p2]) p2++;
            // else if (next == 3 * uglyNumber[p3]) p3++; // 会造成重复，有可能 next 同时等于两个不同的计算步骤中产生的结果
            if (next == 3 * uglyNumber[p3]) p3++;
            if (next == 5 * uglyNumber[p5]) p5++;
            uglyNumber[i] = next;
        }
        return uglyNumber[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

 */

