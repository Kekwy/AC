// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 * @lcpr version=21914
 *
 * [2560] 打家劫舍 IV
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
    // dp 超时
    // int minCapability(vector<int> &nums, int k) {
    //     auto dp = vector<vector<int>>(nums.size(), vector<int>(k, INT_MAX));
    //     dp[0][0] = nums[0];
    //     for (int i = 1; i < nums.size(); i++) {
    //         dp[i][0] = min(nums[i], dp[i - 1][0]);
    //         for (int j = 1; j < k; j++) {
    //             dp[i][j] = min(max(nums[i], dp[i - 1][j - 1]), dp[i - 1][j]);
    //         }
    //     }
    //     return dp[nums.size() - 1][k - 1];
    // }
    int minCapability(vector<int>& nums, int k) {
        int lower = *min_element(nums.begin(), nums.end());
        int upper = *max_element(nums.begin(), nums.end());
        while (lower <= upper) {
            int middle = (lower + upper) / 2;
            int count = 0;
            bool visited = false;
            // 计算此时可以偷取的最大房间数，从第一个房间开始贪心计算即可
            // 可以证明通过刻意跳过一个能偷取的房间来避免遇到不能偷取的房间，并不能增加最大偷取的房间数。
            for (int x : nums) {
                if (x <= middle && !visited) {
                    count++;
                    visited = true;
                } else {
                    visited = false;
                }
            }
            if (count >= k) {
                upper = middle - 1;
            } else {
                lower = middle + 1;
            }
        }
        return lower;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minCapability
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2,3,5,9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n2\n
// @lcpr case=end

 */

