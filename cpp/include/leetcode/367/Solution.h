//
// Created by Kekwy on 2023/8/13.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

public:
    bool isPerfectSquare(int num) {
        int low = 0, high = num;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid > 0 && num / mid < mid) high = mid - 1;
            else if (mid > 0 && (num / mid > mid || (num - 1) / mid >= mid)) low = mid + 1; // 5 / 2 == 2; 4 / 2 == 2.
            else return true;   // 若 mid 为 0，则 num 只可能为 0 或 1，两者均为完全平方数，故不必特殊判断 mid 为 0 的情况
        }
        return false;
    }
};

#endif //CPP_SOLUTION_H
