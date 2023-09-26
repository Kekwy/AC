/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 * @lcpr version=21917
 *
 * [2582] 递枕头
 */

// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time) {
        if ((time / (n - 1)) % 2 == 0) {
            return 1 + (time % (n - 1));
        } else {
            return n - (time % (n - 1));
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n5\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

 */

