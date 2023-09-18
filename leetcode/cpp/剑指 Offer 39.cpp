/*
 * @lc app=leetcode.cn id=剑指 Offer 39 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 39] 数组中出现次数超过一半的数字
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
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int halfSize = size / 2;
        sort(nums.begin(), nums.end());
        int count = 1;
        int res = nums[0];
        for (int i = 0; i < size - 1; i++) {
            if (nums[i] == nums[i + 1]) count++;
            else count = 1;
            if (count > halfSize) {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 3, 2, 2, 2, 5, 4, 2]\n
// @lcpr case=end

 */

