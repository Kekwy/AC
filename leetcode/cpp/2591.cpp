/*
 * @lc app=leetcode.cn id=2591 lang=cpp
 * @lcpr version=21914
 *
 * [2591] 将钱分给最多的儿童
 */

// @lc code=start
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1; // 金额小于儿童数，不存在分配方案，返回 -1
        money -= children;               // 为每人分配 1 元
        int res = money / 7;             // 计算剩下的钱能为多少人分配 7 元，再拿到 7 元的人即为恰好获得 8 元的人
        // 如果当前分配方案恰能使 children - 1 人获得 8 元
        // 但是剩余 1 人拿到了 4 元，则需要最后一个如某一个拿到 8 元的人py交易，改变两人的钱数
        // 此时恰好拿到 8 元的人会减少一个
        if (res == children - 1 && money % 7 == 3) res--; 
        // 边界条件较难把握
        // 若上述计算结果大于了儿童总数，或恰好等于儿童数，但是分完还有余钱时
        // 则需要让某一个人拿所有多余的钱，故此时最多有 children - 1 人恰好拿到 8 元
        else if (res > children || (res == children && money % 7 > 0)) res = children - 1;
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 20\n3\n
// @lcpr case=end

// @lcpr case=start
// 16\n2\n
// @lcpr case=end

 */

