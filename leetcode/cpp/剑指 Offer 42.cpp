/*
 * @lc app=leetcode.cn id=剑指 Offer 42 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 42] 连续子数组的最大和
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
    int maxSubArray(vector<int>& nums) {
        int pre = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            pre = max(pre + nums[i], nums[i]);
            res = max(pre, res);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

 */

