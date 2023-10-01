/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=21917
 *
 * [18] 四数之和
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
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 4; i++) {     // 确定第一个数
            // if (nums[i] > target) break; // 有负数，故不可跳过
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // int sum1 = target - nums[i];
            long long sum1 = (long long)(target - nums[i]);
            for (int j = i + 1; j <= nums.size() - 3; j++) { // 确定第二个数
                // if (nums[j] > sum1) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // i + 1!!
                // int sum2 = sum1 - nums[j]; // 当 target 为负时，减法溢出
                long long sum2 = (long long)(sum1 - nums[j]);
                int lp = j + 1, rp = nums.size() - 1;   // 寻找最后两个数
                while (lp < rp) {
                    if (nums[lp] + nums[rp] < sum2) lp++;
                    else if (nums[lp] + nums[rp] > sum2) rp--;
                    else {
                        res.push_back({ nums[i], nums[j], nums[lp], nums[rp] });
                        for (; lp + 1 < nums.size() && nums[lp] == nums[lp + 1]; lp++);
                        for (; rp - 1 >= 0 && nums[rp] == nums[rp - 1]; rp--);
                        lp++;
                        rp--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */

