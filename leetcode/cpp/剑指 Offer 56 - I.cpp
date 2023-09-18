/*
 * @lc app=leetcode.cn id=剑指 Offer 56 - I lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 56 - I] 数组中数字出现的次数
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
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end



/*
// @lcpr case=start
// [4,1,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,10,4,1,4,3,3]\n
// @lcpr case=end

 */

