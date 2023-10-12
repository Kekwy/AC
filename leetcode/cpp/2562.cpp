/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 * @lcpr version=21917
 *
 * [2562] 找出数组的串联值
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
    long long findTheArrayConcVal(vector<int> &nums) {
        int lPtr = 0, rPtr = nums.size() - 1;
        long long res = 0;
        while (lPtr < rPtr) {
            long long lNum = nums[lPtr];
            long long rNum = nums[rPtr];
            while (rNum > 0) {
                lNum *= 10;
                rNum /= 10;
            }
            res += lNum + nums[rPtr];
            lPtr++;
            rPtr--;
        }
        if (lPtr == rPtr) {
            res += nums[lPtr];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,52,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,14,13,8,12]\n
// @lcpr case=end

 */

