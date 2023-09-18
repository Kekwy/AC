/*
 * @lc app=leetcode.cn id=剑指 Offer 66 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 66] 构建乘积数组
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
    vector<int> constructArr(vector<int>& a) {
        auto res = vector<int>(a.size(), 1);
        int pre = 1;
        for (int i = 0; i < a.size(); i++) {
            res[i] *= pre;
            pre *= a[i];
        }
        pre = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            res[i] *= pre;
            pre *= a[i];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

