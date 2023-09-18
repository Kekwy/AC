/*
 * @lc app=leetcode.cn id=剑指 Offer 65 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 65] 不用加减乘除做加法
 */

// @lc code=start
class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};

// @lc code=end



/*
// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

