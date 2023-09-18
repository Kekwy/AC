/*
 * @lc app=leetcode.cn id=剑指 Offer 56 - II lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 56 - II] 数组中数字出现的次数 II
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
    int singleNumber(vector<int> &nums) {
        int counts[32] = { 0 };
        for (int num : nums) {
            for (int j = 0; j < 32; j++) {
                counts[j] += num & 1;
                num = ((unsigned int)num) >> 1;
            }
        }
        int res = 0, m = 3;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= counts[31 - i] % m;
        }
        return res;
    }
};
// 作者：Krahets
// 链接：https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end



/*
// @lcpr case=start
// [3,4,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [9,1,7,9,7,9,7]\n
// @lcpr case=end

 */

