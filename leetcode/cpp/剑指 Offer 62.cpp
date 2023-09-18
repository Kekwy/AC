/*
 * @lc app=leetcode.cn id=剑指 Offer 62 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 62] 圆圈中最后剩下的数字
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
    int lastRemaining(int n, int m) {
        int ans = 0;
        // 最后一轮剩下2个人，所以从2开始反推
        for (int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }
        return ans;
    }
};

// 作者：Sweetiee🍬的小号
// 链接：https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// @lc code=end



/*
// @lcpr case=start
// 5\n3\n
// @lcpr case=end

// @lcpr case=start
// 10\n17\n
// @lcpr case=end

 */
