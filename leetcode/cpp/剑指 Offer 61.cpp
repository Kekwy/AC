/*
 * @lc app=leetcode.cn id=剑指 Offer 61 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 61] 扑克牌中的顺子
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
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zeroNum = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) {
                zeroNum++;
                continue;
            }
            while (nums[i] != nums[i + 1] - 1) {
                if (zeroNum == 0) return false;
                else {
                    nums[i]++;
                    zeroNum--;
                }
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,2,5]\n
// @lcpr case=end

 */

