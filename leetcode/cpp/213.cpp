// @lcpr-before-debug-begin


//cvcxzv

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 * @lcpr version=21913
 *
 * [213] 打家劫舍 II
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

    int rangeRob(vector<int> &nums, int begin, int end) {
        if (begin >= end) return 0;
        int size = end - begin + 1;
        auto dp = vector<int>(size);
        dp[size - 1] = 0;
        dp[size - 2] = nums[end - 1];
        for (int i = end - 2; i >= begin; i--) {
            dp[i - begin] = max(nums[i] + dp[i + 2 - begin], dp[i + 1 - begin]);
        }
        return dp[0];
    }

public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        return max(rangeRob(nums, 0, nums.size() - 1), rangeRob(nums, 1, nums.size()));
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

