/*
 * @lc app=leetcode.cn id=剑指 Offer 57 - II lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 57 - II] 和为s的连续正数序列
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
    vector<vector<int>> findContinuousSequence(int target) {
        auto array = vector<int>();
        auto res = vector<vector<int>>();
        for (int i = 0; i < target; i++) {
            array.push_back(i);
        }
        int lp = 0, rp = 1;
        int sum = 0;
        for (; rp < target; rp++) {
            sum += array[rp];
            while (sum - array[lp] >= target) {
                sum -= array[lp++];
            }
            if (sum == target) {
                res.push_back(vector<int>(array.begin() + lp, array.begin() + rp + 1));
            } else if (sum > target && rp - lp == 1) {
                break;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 9\n
// @lcpr case=end

// @lcpr case=start
// 15\n
// @lcpr case=end

 */

