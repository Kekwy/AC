/*
 * @lc app=leetcode.cn id=605 lang=cpp
 * @lcpr version=21917
 *
 * [605] 种花问题
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
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int state = 0;
        for (int i = 0; n > 0 && i < flowerbed.size(); i++) {
            switch (state) {
            case 0: {
                if (flowerbed[i] == 0) {
                    if (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0) {
                        i++;
                        n--;
                    }
                } else {
                    state = 1;
                }
                break;
            }
            case 1: {
                if (flowerbed[i] == 0) state = 0;
                break;
            }
            default:
                break;
            }
        }
        return n == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,0,0,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0,1]\n2\n
// @lcpr case=end

 */

