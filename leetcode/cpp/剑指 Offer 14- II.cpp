/*
 * @lc app=leetcode.cn id=剑指 Offer 14- II lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 14- II] 剪绳子 II
 */

 // @lc code=start

class Solution {

public:
    int cuttingRope(int n) {
        if (n < 3) { return 1; }
        if (n == 3) { return 2; }
        long res = 1;
        while (n > 4) {
            res *= 3;
            res %= 1000000007;
            n -= 3;
        }
        return (int)(n * res % 1000000007);
    }
};


// 作者：al-viewer
// 链接：https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/solutions/106190/mian-shi-ti-14-ii-jian-sheng-zi-iitan-xin-er-fen-f/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

